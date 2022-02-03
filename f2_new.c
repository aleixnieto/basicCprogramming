 /*
   f2_new.c
   Fidel Salvia Jordana - 26/02/2019
   Programamcio Cientifica - Laboratori
   Funcio i derivada utilitzada en newton.c per tal de calcular
   els seus zeros.
*/

#include <math.h>

double fun(double x){
   return sin(x) - 2 - 0.3*x;
}

double dfun(double x){
   return cos(x) - 0.3;
} 
