#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    int num = atoi(argv[1]);
    int ehprimo = 1;

    //se o numero for menor ou igual a um imprimir false, pois nenhum numero menor ou igual a um ehprimo
   if(num <= 1){
    printf("False\n");
    return 0;
  
   }

    //um nao e primo comecamos com 2
   for(int i = 2; i <= num / 2 ; i++){
    if(num % i == 0){
       ehprimo = 0;
       return 0;
   }

   if(ehprimo){
        printf("true");
    } else {
        printf("false");
    }

   exit(0);
}
}