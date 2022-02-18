/*
   triangPascal.c
   Aleix Nieto Juscafrea
   Lleguim n i dibuixem el triangle de Pascal d'altura n.
*/

#include <stdlib.h>
#include <stdio.h>

int main(void){

   int n, i, j, espais;
   int *tira = NULL;

   scanf("%d", &n);
   if(n < 3){
      printf("grau massa petit.\n");
      return 1;
   }

   /*Punta del triangel*/
   espais = n - 1;
   for(i = 0; i < espais; i++)
      printf("%3s", " ");
   printf("%3d\n", 1);

   espais = n - 2;
   for(i = 0; i < espais; i++)
      printf("%3s", " ");
   printf("%3d   %3d\n", 1, 1);

   /*Inici triangel*/
   tira = (int*) malloc(n*sizeof(int));
   tira[0] = 1;
   tira[1] = 1;
   
   for(i = 3; i <= n; i++){
      /*Calculem nova tira*/
      for(j = i%2 == 0? i/2 - 1: i/2; j > 0; j--){
         tira[j] += tira[j-1];
         tira[i - 1 - j] = tira[j];
      }
      tira[i - 1] = 1;

      /*Imprimim la tira*/
      espais = n - i;
      for(j = 0; j < espais; j++)
         printf("%3s", " ");
      for(j = 0; j < i; j++)
         printf("%3d%3s", tira[j], " ");

      printf("\n");
   }

   return 0;
}
