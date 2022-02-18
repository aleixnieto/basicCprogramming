/*
   sumes.c
   Aleix Nieto Juscafrea
   Calcula la suma de 1/(j**2) per j:1->N per N element de {1e3, ..., 1e6},
   compara els caluls utilitzan float i double i a més j:1->N i j:N->1.
*/

#include <stdio.h>

int main(void){

   float n_simple;
   double n_doble;
   int i, j;

   printf(" - - - - - - - - - float - - - - - - - - -\n");
   printf(" %5s | %10s%9s | %9s\n", "N  ", "j:1->N", "", "j:N->1");
   
   for(i = 1000; i <= (int)1e6; i *= 10){
      printf(" %5.0e", (float)i);

      n_simple = 0;
      for(j = 1; j <= i; j++){
         n_simple += 1./(j*j);
      }
      printf("   %19.12e", n_simple);

      n_simple = 0;
      for(j = i; j > 0; j--){
         n_simple += 1./(j*j);
      }
      printf("   %19.12e\n", n_simple);
   }


   printf("\n - - - - - - - - - double - - - - - - - - -\n");
   printf(" %5s | %10s%9s | %9s\n", "N  ", "j:1->N", "", "j:N->1");
   
   for(i = 1000; i <= (int)1e6; i *= 10){
      printf(" %5.0e", (float)i);

      n_doble = 0;
      for(j = 1; j <= i; j++){
         n_doble += 1./(j*j);
      }
      printf("   %19.12le", n_doble);

      n_doble = 0;
      for(j = i; j > 0; j--){
         n_doble += 1./(j*j);
      }
      printf("   %19.12le\n", n_doble);
   }

   return 0;
}
