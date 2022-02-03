#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float recu2ordre (int,float,float, float, float);
void funcionorecursiva (int, float, float, float, float);

int main(void){

   int n;
   float a,b,x0,x1,xn;
   clock_t t_ini, t_fin;
   double secs;

   printf("Introdueix a i b\n");
   scanf("%e %e",&a,&b);

   printf("Introdueix x_0 i x_1\n");
   scanf("%e %e",&x0,&x1);

   printf("Quina n vols calcular?\n");
   scanf("%d",&n);

   switch(n){
      case 0:
         xn=x0;
         break;
      case 1:
         xn=x1;
         break;
      default:
	 
	 printf("Funció recursiva\n");

	 t_ini=clock();
         xn=recu2ordre(n,a,b,x0,x1);
	 printf("x_n=%e\n", xn);
	 t_fin=clock();
	 secs=(double)(t_fin-t_ini)/CLOCKS_PER_SEC;
	 printf("%.16g milisegons\n",secs*1000);
	
	 printf("Funció no recursiva\n");

         t_ini=clock();
	 funcionorecursiva(n,a,b,x0,x1);
	 t_fin=clock();
         secs=(double)(t_fin-t_ini)/CLOCKS_PER_SEC;
         printf("%.16g milisegons\n",secs*1000);
         break;
   }

    return 0;
}



float recu2ordre(int n, float a, float b, float x0,float x1){
	float resul;
	
	if(n==0 || n==1){
		if(n==0){
			resul=x0;
		}else{
			resul=x1;
		}
	}else{
		resul=a*recu2ordre(n-1, a, b, x0, x1)+b*recu2ordre(n-2,a,b,x0,x1);
	}

return resul;	
}
void funcionorecursiva (int n, float a, float b, float x0, float x1){

	int i;
	float x2;

	for(i=2;i<=n;i++){
	x2 = a*x1+b*x0;
	x0=x1;
	x1=x2;
	}
	printf("x_n=%e\n", x2);

	return;
}
