/*
   newPol.c
   Aleix Nieto Juscafrea
   Funció que calcula pel mètode de Newton el zero d'un polinomi.
   Utilitzada en zeroPol.c.
*/

#include <math.h>
#include <stdlib.h>

double *der_pol(int, double*);
double horner(int, double *, double);

int newton(int n, double *p, double x0, double tol,
           int maxIter, double *sol){
   int i;
   double x1;
   double *dPol = NULL;
   
   dPol = der_pol(n, p);

   x1 = x0 - horner(n, p, x0)/horner(n - 1, dPol, x0);
   for(i = 1; i <= maxIter &&
              fabs(x1 - x0) >= tol &&
              fabs(horner(n, p, x1)) >= tol &&
              fabs(horner(n - 1, dPol, x1)) >= tol;
       i++){
      x0 = x1;
      x1 = x0 - horner(n, p, x0)/horner(n - 1, dPol, x0);
   }

   if(i > maxIter){
      free(dPol);
      return 1;
   }

   if(fabs(horner(n - 1, dPol, x1)) < tol){
      free(dPol);
      return 2;
   }

   *sol = x1;
   free(dPol);
   return 0;
} 
