#include<stdio.h>
#include<math.h>

#define AREA(r) (M_PI)*(r)*(r)
#define CIRCONFERENZA(r) 2*(M_PI)*(r)

int main(void){
	double raggio;
	printf("Inserisci lunghezza raggio\n");
	scanf("%lf", &raggio);
	printf("AREA(%lf)          = %lf\n", raggio, AREA(raggio));
	printf("CIRCONFERENZA(%lf) = %lf\n", raggio, CIRCONFERENZA(raggio));
	return 0;
}
