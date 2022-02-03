/*
   newton.c
   Fidel Salvia Jordana - 26/02/2019
   Programamcio Cientifica - Laboratori
   Funcio utilitzada en zeroNew.c per calcular el zero
   d una funcio per el metode de Newton-Raphson.
*/

#include <math.h>

double fun(double);
double dfun(double);

int newton(double x0, double tol, int maxIter, double *sol){
   int i;
   double x1;

   x1 = x0 - fun(x0)/dfun(x0);
   for(i = 1; i <= maxIter && 
              fabs(x1 - x0) >= tol && 
              fabs(fun(x1)) >= tol && 
              fabs(dfun(x1)) >= tol; 
   i++){
      x0 = x1;
      x1 = x0 - fun(x0)/dfun(x0);
   }

   if(i > maxIter){
      return 1;
   }
   
   if(fabs(dfun(x1)) < tol){
      return 2;
   }

   *sol = x1;
   return 0;
} 
