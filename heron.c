#include<stdio.h>
#include<math.h>
char triangle (float x, float y, float z){
	float max,c;
	max=x;
	c=y+z;
	if(y>max){
		max=y;
		c=x+z;
	}if(z>max){
		max=z;
		c=x+y;
	}if(max<c){
		return('s');
	}else{
		return('n');
	}
}float heron (float a,float b, float c){
	float sp,disc,A;
	sp=(a+b+c)/2;
	disc=sp*(sp-a)*(sp-b)*(sp-c);
	A=sqrt(disc);
	return (A);
}int main (void){
	float a,b,c;
	char x;
	printf("donam els costats del triangle\n");
	scanf("%g %g %g", &a,&b,&c);
	if(a<=0 || b<=0 || c<=0){
		printf("dades incorrectes");
	}else{
		x=triangle (a,b,c);
		if(x=='s'){
			printf("si que es contruible, i la seva area es %g \n", heron(a,b,c));
		}else{
			printf("no es construible\n");
		}	 
	}return 0;
}
	
