#include<stdio.h>
int main(void){
	float a, b, c, maxim,nomax1,nomax2;
	printf("introdueix tres nombres reals a,b,c\n");
	scanf("%g %g %g",&a,&b,&c);

	if(a>b && a>c){
		maxim=a;
		nomax1=b;
		nomax2=c;
	}else{
		if(b>c){
			maxim=b;
			nomax1=a;
			nomax2=c;
		}else{
			maxim=c;
			nomax1=b;
			nomax2=a;
		}
	}if(nomax1>nomax2){
		printf("l'ordre, de menor a major, es de: %g,%g,%g\n", nomax2, nomax1, maxim);
	}else{
		printf("l'ordre, de menor a major, es de: %g,%g,%g\n",nomax1,nomax2,maxim);
	}return 0;
}

