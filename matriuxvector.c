#include<stdio.h>
#define N 20
#define M 20
float producte(int n,int m, float M[M][N],float V[N]);
int main (void){
	int n,m,i,j;
	float V[N],M[M][N];
	printf("files de la matriu:\n");
	scanf("%d",&m);
	printf("columnes de la matriu:\n");
	scanf("%d", &n);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			M[j][i]=1/(1+(i+j));
		}
	}for(j=0;j<m;j++){
		V[j]=j;
	}printf("el producte de la matriu %lg  pel vector %lg  es %lg",M[][N],V[],producte(n,m,M[][N],V[]));
	return 0;
} float producte (int n,int m, float M[M][N],float V[N]){
	int j,i;
	float MxV[N];
	for(j=0;j<m;j++){
		MxV[j]=0;
	}
	for(j=0;j<m;j++){
		for(i=0;i<n;j++){
			MxV[j]+=M[i][j]*V[i];
			}
		}
	}return(MxV[M]);
}

