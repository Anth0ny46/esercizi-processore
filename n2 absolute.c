#include<stdio.h>

#define ABSOLUTE(value) value >= 0 ? value : -(value)

int main(void){
	printf("abs(-1) = %d\n"  , ABSOLUTE(-1));
	printf("abs(3-4) = %d\n" , ABSOLUTE(3-4));
	printf("abs(7) = %d\n"   , ABSOLUTE(7));
	printf("abs(-8-3) = %d\n", ABSOLUTE(-8-3));
	return 0;
}
