/*
   frac-ord.c
   Aleix Nieto Juscafresa
   Donat un nombre n, el programa escriu totes les fraccions p/q tals que
   2 <= q <= n, 1 <= p <= q, mcd(p, q) = 1. També ha de dir quantes n'hi ha
*/

#include <stdio.h>

#define N_MAX 10

int mcd(int, int);
void escriure(int, int [][2]);
void inserir(int *, int, int, int [][2]);

int main(void){

   int n, cont, q, p;
   int matDiv[N_MAX*(N_MAX - 1)/2][2];

   scanf("%d", &n);
   if(n < 1 || n > N_MAX){
      printf("Error, n incorrecte!\n");
      return 1;
   }

   matDiv[0][0] = 1;
   matDiv[0][1] = 2;
   cont = 1;

   for(q = 3; q <= n; q ++){
      for(p = 1; p < q; p++){
         if(mcd(p, q) == 1){
            inserir(&cont, p, q, matDiv);
         }         
      }
      escriure(cont, matDiv);
   }

   return 0;
}

int mcd(int p, int q){
   int aux, res;

   /*Ordenem*/
   if(p < q){
      aux = p;
      p = q;
      q = aux;
   }

   res = p%q;

   while(res != 0){
      p = q;
      q = res;
      res = p%q;
   }

   return q;
}


void escriure(int n, int mat[][2]){
   int i;

   printf("q = %d - quantitat = %d\n", mat[0][1], n);
   printf("%d/%d ", mat[0][0], mat[0][1]);
   for(i = 1; i < n; i++){
      if(i%10 == 0) 
         printf("\n");
      printf("< %d/%d ", mat[i][0], mat[i][1]);
   }
   printf("\n");
}

void inserir(int *cont, int p, int q, int mat[][2]){
   int i, j;

   for(i = 0; i < *cont && p*mat[i][1] >= q*mat[i][0]; i++);

   if(i < *cont){
      for(j = *cont; j > i; j--){
         mat[j][0] = mat[j - 1][0];
         mat[j][1] = mat[j - 1][1];
      }
   } 

   mat[i][0] = p;
   mat[i][1] = q;

   (*cont)++;
}














