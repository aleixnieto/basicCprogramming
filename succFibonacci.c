#include<stdio>
int main (void){
	int x[42];
	printf("escriu un valor per a x0:\n");
	scanf("%d", &x[0]);
	
	printf("escriu un valor per a x1:\n");
	scanf("%d", &x[1]);

	for(n=2, n<41, n++){
		x[n]= x[n-1]+x[n-2];
		printf("%f,");
	}return 0;
}

