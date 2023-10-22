#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct FRIEND{
	char name[20];
	char email[30];
	char pnum[15];
};

void search_name(struct FRIEND * f_info, int n){
	
	char sName[20];
	int c=0;

	printf("검색할 친구의 영문 이름 : ");
	scanf("%s", sName);

	for(int i=0; i<n; i++){
		if(strcmp(f_info[i].name, sName)==0){
			c=1;
			printf("%s의 이메일 : %s, 전화번호 : %s\n", f_info[i].name, f_info[i].email, f_info[i].pnum); 
		}
		else continue;
	}

	if(!c) printf("존재 하지 않는 이름입니다.\n");
}

void search_all(struct FRIEND * f_info, int n){
	
	printf("저장된 연락처 목록\n");
	
	for(int i=0; i<n; i++){
		printf("%d. %s %s %s\n", i+1, f_info[i].name, f_info[i].email, f_info[i].pnum);
	}
		
}

int main(void){
	struct FRIEND f_info[10] = {{"yejin", "yejin@ssu.ac.kr", "01011111111"},
						 {"seyeon", "seyeon@ssu.ac.kr", "01022222222"},
						 {"hongray", "hongray@ssu.ac.kr", "01033333333"},
						 {"hayeon", "hayeon@ssu.ac.kr", "01044444444"},
						 {"junic", "junic@ssu.ac.kr", "01055555555"},
						 {"sanghyeon", "sanghyeon@ssu.ac.kr", "01066666666"},
						 {"hyeongdam", "hyeongdam@ssu.ac.kr", "01077777777"},
						 {"jeseong", "jesong@ssu.ac.kr", "01088888888"},
						 {"yeeun", "yeeun@ssu.ac.kr", "01099999999"},
						 {"yechan", "yechan@ssu.ac.kr", "01000000000"}};

	int menu=0;
	printf("1. 이름 검색  2. 전체 검색 : ");
	scanf("%d", &menu);

	switch(menu){
		case 1:
			search_name(f_info, 10);
			break;

		case 2:
			search_all(f_info, 10);
			break;

		default:
			printf("잘못된 메뉴 입력입니다.\n");
			break;
	}
}

