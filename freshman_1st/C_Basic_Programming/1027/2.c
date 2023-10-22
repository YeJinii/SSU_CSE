#include <stdio.h>
#define PRN_3(x,y,z) printf(#x":%.1f, "#y":%.1f, "#z":%.1f\n", 1.1,2.2,3.3) 

int main(void){
	PRN_3(x,y,z);
	PRN_3(a,b,c);
	return 0;
}
