#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct{
	double x,y;
	}punt;

punt puntMig(punt, punt);

int main(void){

	int n, i;
	char fitxersort[20];
	FILE *sort;

	punt punt1, punt2, punt3, puntint;
	punt puntmig;

	/*fixo 3 punts en el pla de manera que formen un triangle*/
	punt1.x = -1;
	punt1.y = -1;
	punt2.x = 0;
	punt2.y = 1;
	punt3.x = 1;
	punt3.y = -1;
	/*assigno el punt interior*/
	puntint.x = 0.25;
	puntint.y = 0.5;

	printf("Quantes iteracions vols fer?\n");
	scanf("%d", &n);
	printf("Digues el nom del fitxer de sortida\n");
	scanf("%s", fitxersort);

	sort = fopen(fitxersort, "w");
	if(sort == NULL){
		printf("Error de memòria\n");
		exit (1);

	}

	/*Assigno el valor 1,2,3 als 3 vèrtexs, faig que generi un número aleatori del 1 al 3*/
	int aleatori;
	srand ((unsigned)time(NULL));
	for(i=0;i<n;i++){
		aleatori=((rand() %3)+1);
		if (aleatori==1){
			puntmig=puntMig(punt1, puntint);
			puntint = puntmig;
		fprintf(sort, "%6.3le %6.3le\n", puntint.x, puntint.y);
		}else{
			if(aleatori==2){
				puntmig= puntMig(punt2, puntint);
				puntint=puntmig;
				fprintf(sort, "%6.3le %6.3le\n", puntint.x, puntint.y);
			}else{
				puntmig= puntMig(punt3, puntint);
                                puntint=puntmig;
                                fprintf(sort, "%6.3le %6.3le\n", puntint.x, puntint.y);
				}
		}
	}
	fclose(sort);

return 0;
}

punt puntMig (punt prim, punt seg){
	punt resultat;
	
	resultat.x = (prim.x +seg.x)/2;
	resultat.y = (prim.y +seg.y)/2;

	return resultat;
}
