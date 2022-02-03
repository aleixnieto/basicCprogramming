#include<stdio.h>
#define N 1000
int main(void){
	int i,comptar=0;
	char frase[N];
	print("escriu una frase\n");
	scanf("%[^\n]", frase);
	for(i=0;i<N; i++);
		if(frase[i]==('a' || 'e' || 'i' || 'o' || 'u' || 'A' || 'E' || 'I' || 'O' || 'U')){
			comptar++;
		}
	}printf("hi ha %d vocals\n",comptar); 
	return 0;
}
