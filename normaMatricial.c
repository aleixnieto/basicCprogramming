/*
   normaMatricial.c
   Aleix Nieto Juscafrea
   Programa que calcula la norma matricial d'una matriu i el màxim de la divisió entre
   la norma d'un vecotr 'x' per la matriu i la norma de 'x'.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define DIM 100
#define VAL_MIN 1e-6

double normal(double [], int);
double normalMat(double [][DIM], int);
void prodMatVec(double [][DIM], double [], double [], int);

int main(void){

   int n, i, j;
   double max, normVect;
   double vectX[DIM];
   double matA[DIM][DIM];

   srand((unsigned) time(NULL));

   /*lleguim n*/
   scanf("%d", &n);
   if( n < 2 || n > DIM){
      printf("Error, valor n incorrecte.\n");
      return 1;
   }

   /*lleguim matriu*/
   for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
         scanf("%le", &matA[i][j]);
      }
   }

   printf("normalMat = %+20.12le\n", normalMat(matA, n));
   
   /*Inicialitzem vector*/
   for(j = 0; j < n; j++){
      vectX[j] = rand() + VAL_MIN;
   }
   /*Maxim inicial*/
   max = normal(vectX, n);

   for(i = 1; i < (int) 1e6; i++){
      /*Inicialitzem vector*/
      for(j = 0; j < n; j++){
         vectX[j] = rand() + VAL_MIN;
      }

      /*Calcul maxim*/
      normVect = normal(vectX, n);
      if(max < normVect){
         max = normVect;
      }           
   }

   printf("Valor màxim de alfa(A) = %+20.12le\n", max);
   
      

   return 0;
}

/*Calcula la normal d'un vector de dimensio 'n'*/
double normal(double v[], int n){
   double sum;
   int i;

   sum = 0.;
   for(i = 0; i < n; i++){
      sum += fabs(v[i]);
   }

   return sum;
}

/*Calcula la normal d'una matriu quadrada nxn*/
double normalMat(double mat[][DIM], int n){
   double max, normFila;
   int i;

   max = normal(mat[0], n);
   for(i = 1; i < n; i++){
      normFila = normal(mat[i], n); /*CANVIAR ES PER COLUMNES*/
      if(max < normFila){
         max = normFila;
      }
   }

   return max;
}

/*Calcula el producte entre una matriu quadrada nxn i un vector 'v'
  de dimensio n, retorna el resultat per l'argument 'w'*/
void prodMatVec(double mat[][DIM], double v[], double w[], int n){
   int i, j;

   for(i = 0; i < n; i++){
      w[i] = 0;
      for(j = 0; j < n; j++){
         w[i] += mat[i][j] * v[j];
      }
   }
}










