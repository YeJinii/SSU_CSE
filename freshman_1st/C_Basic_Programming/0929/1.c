#include <stdio.h>
int main(void){

	char *p[3][2] = {"abc", "defg", "hi", "jklmno", "pqrstuvw", "xyz"};

	printf("%c",*(**p+2));
	printf("\n");
	printf("%c", *(*(*(p+1)+1)+2));
	printf("\n");
	printf("%s", **(p+2));
	printf("\n");
	printf("%s", *(*(p+1)+1)+2);
	printf("\n");
	
	return 0;
}
