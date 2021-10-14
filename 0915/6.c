#include <stdio.h>

void func(int a, int b, int c[]){
	c[0]=a/b;
	c[1]=a%b;
}

int main(void){

	int c[2]={0,0};
	func(7,2,c);//임의로 a=7, b=2 인자 전달
	printf("%d %d\n",c[0], c[1]); 
	return 0;

}
