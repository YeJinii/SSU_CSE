#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

	printf("평균은 %d입니다.\n", (atoi(argv[1])+atoi(argv[2])+atoi(argv[3]))/3);
	return 0;
}
