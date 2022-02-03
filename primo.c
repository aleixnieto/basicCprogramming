#include<stdio.h>
int test_primer(int p){
	float q,i;
	for(i=2, i<1001, i++){
		r=p%i;
		if(r==0){
			if(p==i){
				return (1);
			}else{
				return(0);
			}
		}
	}
}int main (void){
	float 
	printf("donam un nombre del 2 al 1000");
	scanf("%d", &p);
	if(p=>2){
		if(test_primer(p)==1){
			printf("es un nombre primer");
		}else{
			printf("es un nombre compost");
		}
	}return 0;
}
