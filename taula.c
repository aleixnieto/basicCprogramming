/*
  taula.c
  Aleix Nieto Juscafrea
  Programa que escriu una taula de les imatges de f1(x) i f2(x) per
  uns punts x-espaiats.
*/

#include <stdio.h>
#include <math.h>

#define PI 4*atan(1)
#define MAX_PUNTS 50

double f1(double);
double f2(double);

int main(void){

    int n, i;
    double h, x;

    printf("#  taula.c\n");

    /*Lleguim n*/
    scanf("%d", &n);
    if(n < 1 || n > MAX_PUNTS){
       printf("#  Error! Valor n incorrecte.\n");
       return 1;
    }
    printf("#  n = %d\n", n);

    h = 2 * PI / n;
    
    printf("#\n#%9s%25s%23s\n", "x", "f1(x)", "f2(x)");


    /*Calculem els punts x-espaiats*/
    for(i = 0; i <= n; i++){
       x = -PI + i * h;
       printf("%19.12le    %19.12le    %19.12le\n", x, f1(x), f2(x));
    }
    

    return 0;
}
