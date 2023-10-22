#include <stdio.h>
int my_strlen(char str[]){
	int len=0;
	for(int i=0; i<sizeof(&str); i++){
		if(str[i]!='\0') len++;
	}
	return len;

}
int main(void){

	char str[10]={'h','e','l','l','o','w'};
	printf("%d\n", my_strlen(str));
	return 0;
}
