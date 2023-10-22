#include "alloc.h"
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

int curdatanum;
int curpagenum;
bool isfirst;

char * m[4];

typedef struct DATAINFO{

	bool exist;
	int datanum;
	int pagenum;

}DATAINFO;

DATAINFO data_info[4][PAGESIZE / MINALLOC];

int init_alloc(void){

	curpagenum=-1;
	curdatanum=1;
	isfirst=0;
	memset(m, 0, sizeof(m));
	memset(data_info,0,sizeof(data_info));
	return 0;
}

char *alloc(int alloc_size){

	int savesize = alloc_size/MINALLOC;
	int issave=0,i=0, p=0;

	if(alloc_size%MINALLOC){
		return NULL;
	}

	if(isfirst==0){
		curpagenum++;
		if((m[curpagenum]=mmap(NULL, PAGESIZE, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0)) < 0) return NULL;
		isfirst=1;
	}

	for(p=0; p<=curpagenum; p++){ //curpagenum 은 0부터 시작함
		for(i=0; i<= (PAGESIZE / MINALLOC) - savesize; i++){
			int cnt=0;
			for(int j=i; j< i+savesize; j++){
				if(!data_info[p][j].exist) cnt++;
			}
			if(cnt==savesize){
				for(int k=i; k< i+savesize; k++){
					data_info[p][k].exist=TRUE;
					data_info[p][k].datanum=curdatanum;
					data_info[p][k].pagenum=curpagenum;
				}
				issave=1;
				curdatanum++;
				break;
			}

		}
		if(issave==1) break;
	}
	if(issave==0){
		if(curpagenum==3) return NULL;
		curpagenum++;
		if((m[curpagenum]=mmap(NULL, PAGESIZE, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0))<0){
			return NULL;
		}
		for(int k=0; k<savesize; k++){
			data_info[curpagenum][k].exist=TRUE;
			data_info[curpagenum][k].datanum=curdatanum;
			data_info[curpagenum][k].pagenum=curpagenum;
		}
		issave=1;
		return m[curpagenum];
	}
	else return m[p]+(i*MINALLOC);
}

void dealloc(char *s){
	int p=0;
	for(p=0; p<=curpagenum; p++){
		if((m[p]<=s)&&(s<m[p]+PAGESIZE)){
			break;
		}
	}
	int idx = (s-m[p])/MINALLOC;
	int ddn = data_info[p][idx].datanum;
	for(int i=idx; i<PAGESIZE / MINALLOC; i++){
		if(data_info[p][i].datanum==ddn){
			data_info[p][i].datanum=0;
			data_info[p][i].exist=FALSE;
			data_info[p][i].pagenum=0;
		}
		else break;
	}
	return;
}

int cleanup(void){
	curpagenum=-1;
	curdatanum=1;
	isfirst=0;
	memset(m, 0, sizeof(m));
	memset(data_info,0,sizeof(data_info));
	return 0;
}
