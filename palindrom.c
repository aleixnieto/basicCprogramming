/*
   palindorm.c
   Fidel Salvia Jordana - 05/03/2019
   Programamcio Cientifica - Laboratori
   Comprova si una paraula es palindroma
*/

#include <stdio.h>
#include <stdlib.h>

#define DIM_MAX_FRASE 500

char* invertir(char *);

int main(void){

   char frase[DIM_MAX_FRASE];
   char *invFrase;
   int i;

   /*lleguir frase*/
   printf("Donam una frase (Max %d caracters):\n", DIM_MAX_FRASE - 1);
   scanf("%[^\n]s", frase);

   invFrase = invertir(frase);
   if(invFrase == NULL){
      printf("Error al inveritr la frase.\n");
      return 1;
   }

   printf("Frase invertida: %s\n", invFrase);
   
   for(i = 0; frase[i] != '\0' && invFrase[i] == frase[i]; i++);
   
   if(frase[i] == '\0') printf("Es palindrom.\n");
   else printf("No es palindrom.\n");

   free(invFrase);

   return 0;
}

/*Funcio que inverteix una cadena de caracters*/
char* invertir(char *tira){
   int i, dim;
   char *invTira;

   for(dim = 0; tira[dim] != '\0'; dim++);

   invTira = (char*) malloc((dim + 1)*sizeof(char));
   if(invTira == NULL){
      return NULL;
   }

   for(i = 0; i < dim; i++){
      invTira[i] = tira[dim - 1 - i];
   }
   invTira[i] = '\0';

   return invTira;
} 








