/*
   commuten.c
   Aleix Nieto Juscafresa- 05/03/2019
   Programamcio Cientifica - Laboratori
   Utilitzan el producte de matrius mirem si dos matrius commuten.
*/

#include <stdio.h>
#include <stdlib.h>

double **prod_mat(int, int, double **, int, double **);


int main(void){

   int i, j, n, commuten;
   double **matA = NULL, **matB = NULL,
          **matAB = NULL, **matBA = NULL;

   /*Lleguir dim matA*/
   printf("Donam files A:\n");
   scanf("%d", &n);
   if(n < 1){
      printf("Dimensions de A errones.\n");
      return 1;
   }

   /*Reservem memoria per matA*/
   matA = (double**) malloc(n*sizeof(double));
   if(matA == NULL){
      printf("Error al reservar memoria.\n");
      return 1;
   }

   for(i = 0; i < n; i++){
      matA[i] = (double*) malloc(n*sizeof(double));
      if(matA[i] == NULL){
         printf("Error al reservar memoria.\n");
         return 1;
      }
   }

   /*Lleguim matA*/
   printf("Donam matA (matriu %dx%d):\n", n, n);
   for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
         scanf("%le", &matA[i][j]);
      }
   }

   /*Reservem memoria per matB*/
   matB = (double**) malloc(n*sizeof(double*));
   if(matB == NULL){
      printf("Error al reservar memoria.\n");
      return 1;
   }

   for(i = 0; i < n; i++){
      matB[i] = (double*) malloc(n*sizeof(double));
      if(matB[i] == NULL){
         printf("Error al reservar memoria.\n");
         return 1;
      }
   }

   /*Lleguim matB*/
   printf("Donam matB (matriu %dx%d):\n", n, n);
   for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
         scanf("%le", &matB[i][j]);
      }
   }
   
   /*Producte de AB i BA*/
   matAB = prod_mat(n, n, matA, n, matB);
   if(matAB == NULL){
      printf("Error en el producte A B.\n");
      return 1;
   }

   matBA = prod_mat(n, n, matB, n, matA);
   if(matBA == NULL){
      printf("Error en el producte B A.\n");
      return 1;
   }

   /*Comprovar si comuten*/
   commuten = 1;
   for(i = 0; i < n && commuten; i++){
      for(j = 0; j < n && commuten; j++){
         if(matAB[i][j] != matBA[i][j]){
            commuten = 0;
            printf("Les matrius no commuten.\n");
         }
      }
   }

   if(commuten) printf("Les matrius commuten");

   /*Lliurem memoria*/
   for(i = 0; i < n; i++){
      free(matB[i]);
      free(matBA[i]);      
   }

   for(i = 0; i < n; i++){
      free(matA[i]);
      free(matAB[i]);
   }

   free(matB);
   free(matA);
   free(matAB);
   free(matBA);

   return 0;
} 















