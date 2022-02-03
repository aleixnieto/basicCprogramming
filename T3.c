/* T3 */
/* calcular el quocient i el residu d'una divisio a partir de el divisor i el dividend */

#include <stdio.h>
int main(void){ 
	int a,b,r,q;
	printf("doneu un dividend a\n");
	scanf("%d",& a);
 
	printf("doneu un divisor b\n");
	scanf("%d",& b);
	q=a/b;
	r=a-q*b;
	printf("el quocient q es igual a  %d i el residu r es igual a %d\n", q,r);
	return 0;
}
