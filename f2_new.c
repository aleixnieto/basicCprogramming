 /*
   f2_new.c
   Aleix Nieto Juscafresa - 26/02/2019
   Programamció Científica - Laboratori
   Funció i derivada utilitzada en newton.c per tal de calcular
   els seus zeros.
*/

#include <math.h>

double fun(double x){
   return sin(x) - 2 - 0.3*x;
}

double dfun(double x){
   return cos(x) - 0.3;
} 
