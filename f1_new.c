 /*
   f1_new.c
   Fidel Salvia Jordana - 26/02/2019
   Programamcio Cientifica - Laboratori
   Funcio i derivada utilitzada en newton.c per tal de calcular
   els seus zeros.
*/

#include <math.h>

double fun(double x){
   return x - cos(x);
}

double dfun(double x){
   return 1 + sin(x);
}
