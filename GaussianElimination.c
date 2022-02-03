/* ALEIX NIETO JUSCAFRESA */  /* DNI:41601796V */ /* NIUB:20194182 */
/*Exercici 27, que resol un sistema d'equacions lineal pel m�tode d'eliminaci� gaussiana i l'algorisme de substituci� enrere, si hi ha un sistema homogeni, aquest programa et donar�  la soluci� trivial (0,...,0) ja que nom�s resol sitemes compatibles determinats, he introdu�t diferents sistemes i a tots ha donat la soluci� correctament, tamb� he compilat el programa amb el valgrind i ha donat 0 errors, de manera que tota la mem�ria ha sigut alliberada correctament*/ 

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void omplirMat(double**, int);
int gauss(double **, int);
void substitucio(double **, int);
int main(void){
	int n, i, j, validar;
	double **matA, **matB;
	char ent[30], sor[30];
	FILE *entrada, *sortida;
	
	printf("Nom fitxer entrada: \n");
	scanf("%s", ent);
	entrada = fopen(ent, "r");

	if(entrada == NULL){
		printf("No s'ha pogut obrir el fitxer\n");
		exit(1);
	}
	
	fscanf(entrada, "%d", &n);
	
	matA=(double**)malloc(n*sizeof(double*));
	
	if(matA== NULL){
		printf("No hi ha prou mem�ria\n");
		exit(2);
	}
	for(i = 0; i < n; i++){                                   /* Guardo mem�ria per a la matriu amb un for ja que un cop hem guardat mem�ria per a cada fila, ara 
									    hem de guardar mem�ria per a les components de cada fila, �s a dir, dimensi�+1 */
		matA[i]=(double*)malloc((n+1)*sizeof(double));
		if(matA[i] == NULL){
			printf("No hi ha prou mem�ria\n");
			exit(3);
		}
	}
	 matB=(double**)malloc(n*sizeof(double*));

        if(matB == NULL){
                printf("No hi ha prou mem�ria\n");
                exit(2);
        }
        for(i = 0; i < n; i++){                                   
                matB[i]=(double*)malloc((n+1)*sizeof(double));
                if(matB[i] == NULL){
                        printf("No hi ha prou mem�ria\n");
                        exit(3);
                }
	}

	for(i = 0; i < n; i++){
		for(j = n-(n-i); j <= n; j++){
			fscanf(entrada, "%le", &matB[i][j]);
		}
	}
	printf("Fitxer sortida: \n");
        scanf("%s", sor);
        sortida = fopen(sor, "w");
        if(sortida == NULL){
                printf("Problemes a l'obrir el fitxer\n");
                exit(6);
        }
	for(i=0;i<n;i++){
		for(j=0;j<=n;j++){
			matA[i][j]=0;
		}
	}
	omplirMat(matA,n);
		/*Escribim la matriu A*/
	 for(i=0;i<n;i++){
                for(j=0;j<=n;j++){
			fprintf(sortida,"%le", matA[i][j]);
			if(j==n)
				printf("/n");
			}
		}
	validar = gauss(matA, n);
        if(validar == 1){
                printf("No s'ha pogut triangular la matriu\n");  /*Si el programa no ha pogut esglaonar una matriu triangular superior, aleshores s'acaba */
                exit(4);
        }

        substitucio(matA, n);
		

	validar = gauss(matB, n);
	/*Omplim la matriu B un cop hem trobat y*/
	   /*Omplim la matriu B per simetria*/
        for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                        if(matB[i][j]==0)
                        matB[i][j]=matB[j][i];
			if(j==n)
			matB[i][j]=matA[i][j];
                }
        }
	 validar = gauss(matB, n);
        if(validar == 1){
                printf("No s'ha pogut triangular la matriu\n");  /*Si el programa no ha pogut esglaonar una matriu triangular superior, aleshores s'acaba */
                exit(5);
        }

        substitucio(matB, n);

	for(i = 0; i < n; i++){	
		fprintf(sortida, "%le", matB[i][n]);
		fprintf(sortida, "\n");
	}
	fclose(entrada);
	fclose(sortida);
	for(i=0;i<n;i++)                    /* Allibero mem�ria de forma inversa a com l'he guardat */
      		free(matA[i]);
	free(matA);
	for(i=0;i<n;i++)                    
                free(matB[i]);
        free(matB);

return(0);
}

/*Funci� que esglaona la matriu amb una matriu triangular superior*/
int gauss(double **mat, int n){
	int i, j, k;
	double m;
	for(k=0; k<n;k++){
		for(i=k+1;i<n;i++){
			if(fabs(mat[k][k])<1e-8){
				return(1);
			}
			m = mat[i][k]/mat[k][k];	 
			for(j=0;j<=n;j++){
				mat[i][j]=mat[i][j]-m*mat[k][j];
			}
		}
	}
	return(0);
}
/*Funci� que mitjan�ant l'algorisme de substituci� enrere troba les solucions successives a partir de la �ltima fila de la matriu esglaonada*/
void substitucio(double **mat, int n){
	int i, j;
	for(i=n-1;i>=0;i--){
		for(j=i+1;j<n;j++){
			mat[i][n]=mat[i][n]-mat[i][j]*mat[j][n];
		}
		mat[i][n]=mat[i][n]/mat[i][i];
	}
}
void omplirMat(double **matA, int n){
	int i,j;
		for(i=0;i<n;i++){
		for(j=0;j<=n;j++){
			if(i<j){
				matA[i][j]=2*i/j;
			}else{
			if(i>j)
				matA[i][j]=j/(2*i);
			}
			if(i==j)
			matA[i][j]=n;
			
			if(j==n)
			matA[i][j]=1/7;
		}
	}
return;
}
