/*
   zeroNew.c
   Aleix Nieto Juscafresa - 26/02/2019
   Programamcio Cientifica - Laboratori
   Programa que apartir de la funcio newton calcula
   el zero d una funcio.
*/

#include <stdio.h>

int newton(double, double, int, double*);
double fun(double);

int main(void){

   double tol, zero, x0;
   int maxIter, result;

   printf("Donam (x0 tol maxIter):\n");
   scanf("%le %le %d", &x0, &tol, &maxIter);

   result = newton(x0, tol, maxIter, &zero);
   switch(result){
   case 0:
      printf("Ha hagut convergencia\n");
      printf("    x  = %17.10le\n", zero);
      printf("  f(x) = %17.10le\n", fun(zero));
      break;
   case 1:
      printf("S'ha arivat al maxim d'iteracions sense tenir convergencia\n");
      break;
   case 2:
      printf("La derivada s'anul la\n");
      break;
   }

   return 0;
} 
