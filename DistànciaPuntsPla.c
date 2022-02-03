/* T2 */
/* Calcular la distancia entre dos punts qualsevols del pla */

#include <stdio.h>
#include <math.h>
int main (void){
	float x1, x2, y1, y2, D; 
	printf("doneu la primera coordenada del primer punt del pla\n");
 	scanf("%g",& x1); 
 
	printf("doneu la segona coordenada del primer punt del pla\n");
 	scanf("%g",& y1); 
 
	printf("doneu la primera coordenada del segon punt del pla\n");
 	scanf("%g",& x2); 
 
	printf("doneu la segona coordenada del segon punt del pla\n");
 	scanf("%g",& y2);

	D=sqrt((x2- x1)*(X2 -x1) + (y2- y1)*(y2-y1));
	printf("la distancia entre els dos punts es: %g\n",D);
	return 0;
}  
