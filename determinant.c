/*Càlcul d'un determinant usant la fòrmula de Laplace */
#include <stdio.h>
#include <stdlib.h>

double determinant(int, double**);

int main(void){
	double **a, det, *pt;
	int n, i, j;
	do{
	printf("Dimensió?\n");
	scanf("%d", &n);
	}while(n<=0); /*No comprovem límit superior perquè ja ens dirà l'ordinador que falta memòria*/

	pt=(double*)calloc(n*n, sizeof(double));
	if(pt==NULL){
		printf("Error al guardar memòria\n");
		exit(1);
		}
	a=(double**)malloc(n*sizeof(double*));
	if(a==NULL){
		printf("Error al guardar memòria\n");
		exit(2);
		}	

	for(i=0;i<n;i++)
		a[i]=pt+i*n;

	/*Llegim a*/
		printf("Dona'm el determinant\n");
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%le", &a[i][j]);
			}
		}

	det= determinant(n,a);
	printf("El determinant en qüestió de dimensió %dx%d és igual a %15.7le\n",n, n, det);
	free(a);
	free(pt);
	return 0;
	}

double determinant(int n, double **a){

	double det;
	int i, j, sign, k;
	double **nova;

	if(n==1)
		det=a[0][0];
	else if (n==2)
		det= a[0][0]*a[1][1]-a[0][1]*a[1][0];

	else{
		det=0;
		sign=1;
		nova=(double**)calloc(n-1,sizeof(double*));
		if(nova==NULL){
			printf("Error al guardar memòria\n");
			exit(1);
		}

		for(i=0;i<n-1;i++){
			nova[i]=(double*)calloc(n-1, sizeof(double));
			if(nova[i]==NULL){
				printf("Error al guardar memòria\n");
			}
		}
	for(i=0;i<n;i++){
		for(k=1;k<n;k++){
			for(j=0;j<i;j++){
				nova[j][k-1]=a[j][k];
			}
			for(j=i+1;j<n;j++){
				nova[j-1][k-1]=a[j][k];
			}
		}
		
		det+=sign*a[i][0]*determinant(n-1,nova);
		sign=-sign;
		}
	
		for(i=0;i<n-1;i++)
			free(nova[i]);
		free(nova);	
		
		} return det;
		}
