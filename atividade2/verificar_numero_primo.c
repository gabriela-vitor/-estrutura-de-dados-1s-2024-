#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]){

    int num = atoi(argv[1]);

    //se o numero for menor ou igual a um imprimir false, pois nenhum numero menor ou igual a um ehprimo
   if(num <= 1){
    printf("False\n");
    return 0;
  
   }

    //calcular a raiz quadrada para descobrir se e ou nao primo
   int raiz_q = sqrt(num);

   
   for(int i = 2; i <= raiz_q ; i++){
    if(num % i == 0){
        printf("False\n");
        return 0;
      
    }
   }

   printf("True\n");
   exit(0);
}