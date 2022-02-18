/*
   newPol.c
   Aleix Nieto Juscafrea
   Programa que llegueix un polinomi i en calcula un zero per el metode de newton.
*/

#include <stdio.h>
#include <stdlib.h>

#define TOL 1e-12
#define I_MAX 8

int newton(int n, double *p, double x0, double tol,
           int maxIter, double *sol);
double horner(int, double *, double);

int main(void){

   int n, i;
   double *pol = NULL;
   double aprox_zero, sol;

   /*Demanem dades*/
   scanf("%d", &n);
   if(n < 1){
      printf("Error, grau massa petit.\n");
      return 1;
   }

   pol = (double*) malloc((n + 1) * sizeof(double));
   if(pol == NULL){
      printf("Error al reservar memoria\n");
      return 1;
   }

   for(i = n; i >= 0; i--){
      scanf("%le", &pol[i]);
   }

   scanf("%le", &aprox_zero);

   /*Newton*/
   switch(newton(n, pol, aprox_zero, TOL,
           I_MAX, &sol)){
      case 0:
         printf("El polinomi te un zero en:\n");
         printf("     x  = %17.10le\n", sol);
         printf("   f(x) = %17.10le\n", horner(n, pol, sol));
         break;
      case 1:
         printf("S'han superat el nombre d'iteracions maximes.\n");
         break;
      case 2:
         printf("La derivada del polinomi s'ha anulat.\n");
         break;
   }

   free(pol);

   return 0;
}
