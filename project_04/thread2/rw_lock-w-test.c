#include "rw_lock.h"

void init_rwlock(struct rw_lock * rw)
{
	rw->status=0;
	rw->rlock_num=0; rw->rwait_num=0;
	rw->wlock_num=0; rw->wwait_num=0;
	pthread_mutex_init(&rw->mutex, NULL);
}

void r_lock(struct rw_lock * rw)
{
	pthread_mutex_lock(&rw->mutex);
	rw->rwait_num++;
	pthread_mutex_unlock(&rw->mutex);
	//	Write the code for aquiring read-write lock by the reader.
	for(;;){
		pthread_mutex_lock(&rw->mutex);
		if(rw->status!=2&&rw->wlock_num==0&&rw->wwait_num==0){
			rw->status=1;
			rw->rlock_num++;
			rw->rwait_num--;
			pthread_mutex_unlock(&rw->mutex);
			break;
		}
		pthread_mutex_unlock(&rw->mutex);
	}
	
}

void r_unlock(struct rw_lock * rw)
{
	pthread_mutex_lock(&rw->mutex);
	rw->rlock_num--;		
	if(rw->rlock_num==0){
		rw->status=0;
	}
	pthread_mutex_unlock(&rw->mutex);
	//	Write the code for releasing read-write lock by the reader.
	
}

void w_lock(struct rw_lock * rw)
{
	pthread_mutex_lock(&rw->mutex);
	rw->wwait_num++;
	pthread_mutex_unlock(&rw->mutex);
	for(;;){
		pthread_mutex_lock(&rw->mutex);
		if(rw->status==0&&rw->rlock_num==0&&rw->wlock_num==0){
			rw->status=2;
			rw->wlock_num++;
			rw->wwait_num--;
			pthread_mutex_unlock(&rw->mutex);
			break;
		}
		pthread_mutex_unlock(&rw->mutex);
	}
	
}

void w_unlock(struct rw_lock * rw)
{
	pthread_mutex_lock(&rw->mutex);
	rw->wlock_num--;
	rw->status=0;
	pthread_mutex_unlock(&rw->mutex);	
}
