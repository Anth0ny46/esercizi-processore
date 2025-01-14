#include<stdio.h>

#define CUBE(x) (x)*(x)*(x)

int main(void){
	printf("CUBE(6)   = %d\n", CUBE(6));
	printf("CUBE(3+4) = %d\n", CUBE(3+4));
	printf("CUBE(7)   = %d\n", CUBE(7));
	printf("CUBE(9-3) = %d\n", CUBE(9-3));
	return 0;
}
