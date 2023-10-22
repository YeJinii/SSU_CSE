#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <wait.h>
#include <pthread.h>
#include <unistd.h>

int item_to_produce, item_to_consume, cur_produce, cur_consume;
int total_items, max_buf_size, num_workers, num_masters;

int is_final_master;

int *buffer;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void print_produced(int num, int master) {

	printf("Produced %d by master %d\n", num, master);
}

void print_consumed(int num, int worker) {

	printf("Consumed %d by worker %d\n", num, worker);

}


//produce items and place in buffer
//modify code below to synchronize correctly
void *generate_requests_loop(void *data)
{
	int thread_id = *((int *)data);
	pthread_mutex_lock(&mutex);
	while(1)
	{
			pthread_cond_wait(&cond, &mutex);

		if(item_to_produce >= total_items) {
			pthread_cond_signal(&cond);
			pthread_mutex_unlock(&mutex);
			break;
		}

		if(cur_produce-cur_consume==max_buf_size){
			pthread_cond_signal(&cond);
			continue;
		}
		buffer[(cur_produce++)%max_buf_size] = item_to_produce;
		print_produced(item_to_produce, thread_id);
		item_to_produce++;
		pthread_cond_signal(&cond);

	}
	return 0;
}

void *consume_requests_loop(void *data){
	int thread_id = *((int *)data);
	//소비를 하세요
	pthread_mutex_lock(&mutex);
	while(1)
	{
		if(is_final_master == 0 || num_workers !=1) 
			pthread_cond_wait(&cond, &mutex);

		if(cur_consume >= total_items){
			pthread_cond_broadcast(&cond);
			pthread_mutex_unlock(&mutex);
			//할일 다함
			break;
		}
		if(cur_produce-cur_consume<=0){
			pthread_cond_signal(&cond);
			continue;
			//empty
		}
		item_to_consume=buffer[(cur_consume++)%max_buf_size];
		print_consumed(item_to_consume, thread_id);
		pthread_cond_signal(&cond);
	}
	return 0;
}


//write function to be run by worker threads
//ensure that the workers call the function print_consumed when they consume an item

int main(int argc, char *argv[])
{
	int *master_thread_id;
	pthread_t *master_thread;

	int *worker_thread_id;
	pthread_t *worker_thread;

	item_to_produce = 0;
	item_to_consume=0;
	cur_produce = 0;
	cur_consume = 0;

	int i=0;

	if (argc < 5) {
		printf("./master-worker #total_items #max_buf_size #num_workers #masters e.g. ./exe 10000 1000 4 3\n");
		exit(1);
	}
	else {
		num_masters = atoi(argv[4]);//master쓰레드
		num_workers = atoi(argv[3]);//worker쓰레드
		total_items = atoi(argv[1]);//생성할숫자
		max_buf_size = atoi(argv[2]);//버퍼사이즈
	}

	buffer = (int *)malloc (sizeof(int) * max_buf_size);//버퍼사이즈만큼 동적 할당

	//create master producer threads
	master_thread_id = (int *)malloc(sizeof(int) * num_masters); //masterthread id
	master_thread = (pthread_t *)malloc(sizeof(pthread_t) * num_masters); //pthread_t형으로 동적 할당

	memset(master_thread_id, 0, sizeof(master_thread_id));
	memset(master_thread, 0, sizeof(master_thread));

	for (i = 0; i < num_masters; i++)
		master_thread_id[i] = i;

	for (i = 0; i < num_masters; i++)
		pthread_create(&master_thread[i], NULL, generate_requests_loop, (void *)&master_thread_id[i]);

	//create worker consumer threads
	worker_thread_id = (int*)malloc(sizeof(int)*num_workers);
	worker_thread = (pthread_t *)malloc(sizeof(pthread_t) *num_workers);

	memset(worker_thread_id, 0, sizeof(worker_thread_id));
	memset(worker_thread, 0, sizeof(worker_thread));

	for(i=0; i<num_workers;i++){
		worker_thread_id[i]=i;
	}
	for (i=0; i<num_workers; i++)
		pthread_create(&worker_thread[i],NULL, consume_requests_loop, (void *)&worker_thread_id[i]);

	usleep(10);
	pthread_cond_signal(&cond);
	
	for (i = 0; i<num_masters; i++)
	{
		pthread_join(master_thread[i], NULL);
		printf("master %d joined\n", i);
	}

	is_final_master=1;
	
	if(num_workers == 1)
		pthread_cond_signal(&cond);
	//pthread_cond_signal(&cond_c);
	//wait for all threads to complete
	
	for (i = 0; i<num_workers; i++)
	{
		pthread_join(worker_thread[i],NULL);
		printf("worker %d joined\n", i);
	}

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
	/*----Deallocating Buffers---------------------*/
	free(buffer);
	free(master_thread_id);
	free(master_thread);



	return 0;
}
