/*
   llista_2_exe_5.c
   Aleix Nieto Juscafrea
   Programam que conte diferents 'mains' i s'ha d'observar que fa.
*/

#include <stdio.h>

int main_1(void);
int main_2(void);
int main_3(void);

int main(void){

   main_1();
   main_2();
   main_3();

   return 0;
}

int main_1(void){
   int *p, x = 3210, b;

   printf("\n- - - main (1) - - -\n");
   printf("adreces de les variables:\n &p = %p &x = %p &b = %p\n",
           &p, &x, &b);
   printf("continguts: p = %p x = %d b = %d\n", p, x, b);n
   p = &x;
   b = *p + 4;
   printf("continguts: p = %p x = %d b = %d\n", p, x, b);
   
   return 0;
}

int main_2(void){
   int *p, x = 3210, b;

   printf("\n- - - main (2) - - -\n");
   printf("adreces de les variables:\n &p = %p &x = %p &b = %p\n",
           &p, &x, &b);
   printf("continguts: p = %p x = %d b = %d\n", p, x, b);
   p = &x;
   b = *p;
   printf("continguts: p = %p x = %d b = %d\n", p, x, b);
   b = *p + 4;
   printf("continguts: p = %p x = %d b = %d\n", p, x, b);
   p = p + 4;
   printf("adreces de les variables:\n &p = %p &x = %p &b = %p\n",
           &p, &x, &b);
   printf("continguts: p = %p x = %d b = %d\n", p, x, b);

   return 0;
}

int main_3(void){
  int i;
  double x, *px, sum = 0.;

  printf("\n- - - main (3) - - -\n");
  printf("&x = %p &px = %p\n", &x, &px);
  x = 0.1;
  px = &x;
  printf("&x = %p &px = %p\n", &x, &px);
  printf("x = %23.15e *px = %23.15e\n", x, *px);
  for(i = 1; i <= 1000; i++)
     sum += *px;
  printf("sum = %23.15e \n", sum);
  return 0;
}
