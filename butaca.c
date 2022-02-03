#include <stdio.h>
#include <math.h>

typedef struct{
	int fila;
	int columna;
	int butaque[50][50];
} cinema;

void ocuparButaca(cinema);
void lliurarTotesButaques(cinema);
void escriureLliures(cinema);

int main(void){
	cinema butaca;
	int i,j;
	char fer;
			
	printf("Dona'm el nombre de files i el nombre de columnes\n");
	scanf("%d %d", &butaca.fila, &butaca.columna);

	for(i=0;i<butaca.fila;i++){
		for(j=0;j<butaca.columna;j++){
			butaca.butaques[i][j]=0;
		}
	}
/*Com ho fariem perquè funciones introduint tota la frase en comptes de només una lletra en el switch, si poso el switch dins un for o un dowhile i li donc un cas del switch no surt d'aquell cas en bucle*/
/* No fa la funcio de ocupar butques correctament*/	
	printf("Quina accio vols fer\no = ocupar butques\nl = lliurar butaques\ne = escriure lliures\ns = sortir\n");
	scanf(" %c", &fer);

	for(;fer!='s';){
	
	switch(fer){
		case 'o':
			ocuparButaca(butaca);
			break;
		case 'l':
			lliurarTotesButaques(butaca);
			break;
		case 'e':
			escriureLliures(butaca);
			break;
		default:
			printf("No has anomenat cap acció correctament\n");
	}
	printf("Quina acció vols fer\n");
	scanf(" %c", &fer);	
}

	return 0;
}

void ocuparButaca(cinema c1){
	int f, c;
	printf("Dona'm la fila i columna que vols ocupar\n");
	scanf("%d %d", &f, &c);

	c1.butaques[f-1][c-1]=1;
	
	return;
}

void lliurarTotesButaques(cinema c1){
	int i, j;

	 for(i=0;i<c1.fila;i++){
                for(j=0;j<c1.columna;j++){
                        c1.butaques[i][j]=0;
                }
        }
return;
}

void escriureLliures(cinema c1){
	int i, j;

	for(i=0;i<c1.fila;i++){
                for(j=0;j<c1.columna;j++){
                       if(c1.butaques[i][j]==0){
			      printf("%d %d\n", i+1, j+1);
		       }
		}
        }

return;
}
