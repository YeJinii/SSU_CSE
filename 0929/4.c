#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

int main(void){

	char * words[N];

	//입력
	for(int i=0; i<N; i++){

		char word[20];
		//배열 초기화
		memset(word, '\0', sizeof(word));

		//문자열 입력 받기
		scanf("%s", word);

		//입력받은 문자열의 길이만큼 동적 할당
		words[i] = (char *)calloc(strlen(word)+1, sizeof(char));
		strcpy(words[i], word);

	}

	//출력
	for(int i=0; i<N; i++)	printf("%s\n", *(words+i));

	//동적 메모리 해제
	for(int i=0; i< N; i++) free(words[i]);

	return 0;
}

