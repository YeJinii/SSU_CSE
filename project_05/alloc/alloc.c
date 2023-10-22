#include "alloc.h"
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

int curdatanum;
char * m;

typedef struct DATAINFO{
	bool exist;
	int datanum;
}DATAINFO;

DATAINFO data_info[PAGESIZE / MINALLOC];

int init_alloc(void){
	
	curdatanum=1;
	m=NULL;
	memset(data_info,0,sizeof(data_info));
	
	if((m=mmap(NULL, PAGESIZE, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0))<0){
		return 1;
	}
	return 0;
}

char *alloc(int alloc_size){

	int savesize = alloc_size/MINALLOC;
	int issave=0;
	int i=0;

	if(alloc_size%MINALLOC){
		return NULL;
	}
	for(i=0; i<= (PAGESIZE / MINALLOC) - savesize; i++){
		int cnt=0;
		for(int j=i; j< i+savesize; j++){
			if(!data_info[j].exist) cnt++;
		}
		if(cnt==savesize){
			for(int k=i; k< i+savesize; k++){
				data_info[k].exist=TRUE;
				data_info[k].datanum=curdatanum;
			}
			issave=1;
			curdatanum++;
			break;
		}
	}
	if(issave==1) return m+(i*MINALLOC);
	else return NULL;
}

void dealloc(char *s){
	int idx = (s-m)/MINALLOC;
	int ddn = data_info[idx].datanum;
	for(int i=idx; i<PAGESIZE / MINALLOC; i++){
		if(data_info[i].datanum==ddn){
			data_info[i].datanum=0;
			data_info[i].exist=FALSE;
		}
		else break;
	}
}

int cleanup(void){
	if(munmap(m, PAGESIZE)==-1){
		return 1;
	}
	else return 0;
}