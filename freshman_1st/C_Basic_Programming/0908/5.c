#include <stdio.h>

void my_strcpy(char str1[], char str2[]){

	int i=0;
	while(str2[i]!='\0'){
		str1[i]=str2[i];
		i++;
	}
	str1[i]='\0';
}

int main(void){


	char str1[20];
	char str2[]="C program";
	
	my_strcpy(str1,str2);
	printf("%s\n", str1);
	return 0;
}
