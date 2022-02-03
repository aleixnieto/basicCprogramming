/*Aleix Nieto Juscafresa 20194182*/
/*Aquest programa resol un joc de m jugadors que tiren dos daus n vegades*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 30

void omplejugades(int [][DIM], int, int);
int repeticions(int[][DIM], int ,int, int);
int punts(int[][DIM], int ,int);
int main(void){

int i, n, numJ, maxpunt, guanyador=0, max, num[DIM], tirades[DIM][DIM], primeratirada, repeticions1[DIM]= {0}, empat[DIM] = {0}, guanyadorempat=0;
srand(time(NULL));

do{
	printf("Dona'm el nombre de jugadors amb els quals vols jugar la partida\n");
	scanf("%d", &numJ);
	}while(numJ<=0);

do{
	printf("Dona'm el nombre de tirades que vols dur a terme en el joc\n");
	scanf("%d", &n);
	}while(n<=0 || n>DIM);

/*Jugador guanyador*/
/*Primer omplo la matriu amb les puntuacions dels m jugadors*/

	omplejugades(tirades, n, numJ);
	
	maxpunt=0;
	
for(i=0;i<numJ;i++){

		if(punts(tirades, n, num[i])==maxpunt){
		empat[i]=1;
		}		

		if(punts(tirades, n, num[i])>maxpunt ){
			maxpunt=punts(tirades, n , num[i]);
			guanyador= i;
		}
	}
/*Vaig a mirar en cas d'empat*/
	
	for(i=0;i<numJ;i++){
	if(empat[i]!=0){
	repeticions[i]=repeticions(tirades, numJ, n, 12);
		guanyadorempat=i;
		}
	}

/*Escric qui es el guanyador*/


	if(guanyadorempat!=0){
		printf("El guanyador és el jugador %d amb %d repeticions del nombre 12 \n", guanyadorempat+1);
	}else{
		printf("El guanyador és el jugador %d \n", guanyador +1);
}





	printf("El jugador guanyador ha estat: %d\n", guanyador);	

/*Miro si la tirada 7 és la més repetida de totes*/
	max=repeticions(tirades, numJ, n, 7);

		for(i=0;i<n;i++){
			if(repeticions(tirades, num[i], n, i)>max){
				max=repeticions(tirades, numJ, n, i);
			}
		}
	if(max==repeticions(tirades, numJ, n, 7)){
		printf("La tirada 7 és la més repetida de totes\n");
	}else{
		printf("La tirada 7 no és la més repetida de totes\n");
	}
	
/*Puntuació més repetida en la primera tirada de tots els jugadors*/
/*Poso la n a 0 que vol dir que és la primera tirada*/
	primeratirada=0;
	for(i=0;i<numJ;i++){
		if(repeticions(tirades, num[i], n, i)>primeratirada){
			primeratirada=repeticions(tirades, num[i], n, i);
		}
	}
	
return 0;
} 

void omplejugades(int tirades[][DIM], int m, int n){
	
	int i, j;

	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			tirades[i][j]= (rand()%12)+1; /*12 ja que es tiren els daus dos vegades*/
		}
	}
return;
}

int repeticions(int tirades[][DIM], int m, int n, int pun){
	int i, j, comptador=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(tirades[i][j]==pun){
				comptador++;
					}
				}
			}
		return comptador;
	}
			

int punts(int tirades[][DIM], int n, int index_jug){
	int i, suma=0;
	for(i=0;i<n;i++){
		suma = suma + tirades[index_jug][i];
		}
	return suma;
	}

