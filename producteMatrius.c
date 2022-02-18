/*
   producteMatrius.c
   Aleix Nieto Juscafrea
   Funció que calcula el producte de matrius
*/ 

#include <stdlib.h>

double **prod_mat(int nFilA, int nColA, double **matA,
                  int nColB, double **matB){
   double **matRes = NULL;
   int i, j, k;

   /*Reservem memoria per matRes*/
   matRes = (double**) malloc(nFilA*sizeof(double*));
   if(matRes == NULL){
      return NULL;
   }

   for(i = 0; i < nFilA; i++){
      matRes[i] = (double*) malloc(nColB*sizeof(double));
      if(matRes[i] == NULL){
         return NULL;
      }
   }

   /*Producte*/
   for(i = 0; i < nFilA; i++){
      for(j = 0; j < nColB; j++){
         matRes[i][j] = 0;
         for(k = 0; k < nColA; k++){
            matRes[i][j] += matA[i][k] * matB[k][j];
         }
      }
   }

   return matRes;
}
