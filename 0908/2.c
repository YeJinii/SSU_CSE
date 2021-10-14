#include <stdio.h>
int z;
void f(int x){
	x=2; //함수 내에서는 함수 인자 X값이 2로 대입(변경)되고
	z+=x; //결과적으로 전역변수 z에 2가 더해진다.
}
int main(void){
	z=5; //전역변수인 z에 5를 할당하고 
	f(z); //함수 f를 호출하면서 함수인자 x에 z값 (5)할당
	printf("z=%d\n",z); //따라서 main 함수에서 출력되는 z의 값은 7이 된다.
	return 0;
}
