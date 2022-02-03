/*
   horner.c
   Fidel Salvia Jordana - 26/02/2019
   Programacio Cientifica - Laboratori
   Fucnio que calcula el valor d un polinomi per la regla de Horner.
   Utilitzada en zeroPol.c
*/ 

double horner(int n, double *p, double z){
   int i;
   double result;

   if(n == 0) return p[0];

   result = p[n]*z + p[n - 1];

   for(i = 2; i <= n; i++){
      result = result*z + p[n - i];
   }

   return result;
}
