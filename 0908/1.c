#include <stdio.h>

void divisor(int n){
	for(int i=1; i<=n; i++){
		if(n%i==0) printf("%d",i);
		else continue;
	}
}

int main(void){
	divisor(10);
	return 0;
}
