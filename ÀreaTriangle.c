/* T1 */
/* calcula l'area d'un triangle apartir de la base i l'altura */

#include<stdio.h>
int main(void) {
	float  a,b,A;
	printf("doneu el valor de l'altura a\n");
	scanf("%g",&a);
	printf("doneu el valor de la base b\n");
	scanf("%g",&b);
	A=(a+b)/2;
	printf("l'area del triangle es:%g\n",A);
	return 0;
}

