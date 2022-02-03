#include<stdio.h>
#include<math.h>
int main (void){
	float a,b,c, disc, x1,x2, partr,parti1, parti2;
	
	printf("escriu el coeficient x²:\n");
	scanf("%g", &a);

	printf("escriu el coeficient x:\n");
	scanf("%g", &b);

	printf("escriu el terme independent:\n");
	scanf("%g", &c);
	
	disc=b*b-4*a*c;
	if(disc>0){
		x1=(-b+sqrt(disc))/(2*a);
		x2=(-b-sqrt(disc))/(2*a);
		printf("L'equació %12.6e x² %+12.6e x %+12.6e = 0 \n té dues solucions reals: \n x1 = %12.6e, x2 = %12.6e \n", a,b,c,x1,x2);
 
	}if(disc==0){
		x1=-b/2*a;
		printf("L'equació %12.6e x² %+12.6e x %+12.6e = 0 \n té una solució real: \n x1 = %12.6e \n", a,b,c,x1);

	
	}if(disc<0){
		partr=-b/(2*a);
		parti1=-sqrt(-disc)/(2*a);
		parti2=-parti1;
		printf("L'equació %12.6e x² %+12.6e x %+12.6e = 0 \n té dues solucions complexes conjugades: \n x1 = %12.6e %+13.6ei, x2 = %12.6e %+13.6ei \n", a,b,c,partr,parti1,partr, parti2);
	} return 0;
}
