#include <stdio.h>
#include <string.h>
struct info{
	char name[20]; //이름
	double score; //평점 평균
	int credit; //취득 학점
};

void input_data(struct info * students, int n){
	
	char iName[20];
	double iScore;
	int iCredit;
	
	printf("학생의 이름, 평점 평균, 취득 학점을 입력하세요.\n");

	for(int i=0; i<n; i++){
		
		memset(iName, 0, sizeof(iName)); iScore=0.0; iCredit=0;
		
		scanf("%s %lf %d", iName, &iScore, &iCredit);
		
		strcpy(students[i].name, iName);
		students[i].score = iScore;
		students[i].credit = iCredit;
	}

}

void scholarship(struct info * students, int n){

	printf("\n장학생의 이름, 평점 평균, 취득 학점\n");

	for(int i=0; i<n; i++){
		//취득 학점이 20이상이고 평점 평균이 4.3이상 일때
		if(students[i].credit>=20 && students[i].score>=4.3){
			printf("%s %.1f %d\n", students[i].name, students[i].score, students[i].credit); 
		}
	}
}

int main(void){
	struct info students[5];
	input_data(students, 5);
	scholarship(students, 5);
	return 0;
}

