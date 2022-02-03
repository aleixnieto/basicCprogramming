#include<stdio.h>
int main (void){
	int factorial,i,n;
	factorial=1;
	printf("Escriu el nombre n del qual vols saber el seu factorial:\n");
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		factorial=factorial*i;
	}
	printf("el factorial de %d val: %d\n",n,  factorial);
	return 0;
}
