/*LLegim un polinomi de nombres complexes d'un fitxer, el derivem i l'escrivim en 
un altre fitxer*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

pico crea_pico(int);
void esborra_pico (pico);
pico lpico(char);
void epico( char, pico);
pico derivar(pico);


typedef struct{
	int re, im;
}ico;

typedef struct{
	int grmax;
	ico *c[grmax];
}pico;

int main(void){
	char ent, sor;
	pico polinomi, derivada;

	printf("Dona'm el nom del fitxer d'entrada\n");
	scanf(" %c", ent);

	printf("Dona'm el nom del fitxer de sortida\n");
	scanf(" %c", sor);
	
	polinomi=lpico(ent);
	derivada=derivar(polinomi);
	epico(sor, derivada);
	
return 0;
}

pico crea_pico (int grau){
	pico pol;
	int i;
	
	pol.grmax=grau;
	pol.ico=int*malloc((grau+1)*sizeof(int));
	if(pol.ico==NULL){
		printf("Error al guardar memòria\n");
		exit(1);
	}

	for(i=0;i<=grau;i++){
		pol[i].ico=0;
		}

	return pol;
}

void esborra_pico (pico pol){
	
	free(pol);
	pol=NULL;
	pol.gr=-1; pol.grmax=-1;

	return;
}

pico lpico(char nom){
	FILE *entrada;
	pico pol;
	int grau,i;
	
	entrada = fopen(nom, 'r');
	if(entrada==NULL){
		printf("Error a l'obrir el fitxer\n");
		exit(2);
	}
	
	fscanf("%d", &grau);

	for(i=0;i<=2n;i++){
		if(i%2==0)
		fscanf("%d", &pol.c[i].re);
		else
		fscanf("%d", &pol.c[i].im);
	}
	return pol;
	}

void epico( char nom, pico pol){
	FILE *sortida;
	int i;

	sortida = fopen(nom,'w');
	
	if(sortida==NULL){
                printf("Error a l'obrir el fitxer\n");
                exit(3);
        }
	fprintf("%d", pol.grmax);
	fprintf("\n");
	
	for(i=0;i<=2n;i++){
                if(i%2==0)
                fprintf("%d", &pol.c[i].re);
                else
                fprintf("%d", &pol.c[i].im);
        }
return;
}

pico derivar (pico pol){
	pico der;
	int i;

	der.grmax=pol.grmax;

	if(der.grmax==0){
	der.c=(int*)malloc(sizeof(int));
	if(der.c==NULL){
		printf("Error al reservar memòria\n");
		exit(4);
		}
	der.c[0]=0;
	return der;
	}

	der.c=(int*)malloc(der.grmax*sizeof(int));
	if(der.c==NULL){
                printf("Error al reservar memòria\n");  
                exit(5);
                }
	for(i=1;i<=n;i++){
		der.c[i-1]=pol.c[i]*i;
	}
	return der;
}











