/*
   derPol.c
   Fidel Salvia Jordana - 26/02/2019
   Programacio Cientifica - Laboratori
   Fucnio que retorna la derivada d'un polinomi, com a
   vector utilitzan memoria dinamica. S'utilitza en zeroPol.c
*/

#include <stdlib.h>
#include <stdio.h>

double *der_pol(int n, double *p){
   
   double *tmp_der = NULL;
   int i;

   if(n == 0){
      tmp_der = (double *) malloc(sizeof(double));
      if(tmp_der == NULL){
         printf("Error al reservar memoria dinamica.\n");
         exit(1);
      }
      tmp_der[0] = 0;
      return tmp_der;
   }

   tmp_der = (double *) malloc(n * sizeof(double));
   if(tmp_der == NULL){
      printf("Error al reservar memoria dinamica.\n");
      exit(1);
   }

   for(i = 1; i <= n; i++){
      tmp_der[i - 1] = p[i];
   }

   return tmp_der; 
} 
