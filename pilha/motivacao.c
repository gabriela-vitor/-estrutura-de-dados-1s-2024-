#include <stdio.h>
#include <stdlib.h>

void funcao1(){
    printf("Executando função 1\n");
}

void funcao2(){
    funcao1();
    printf("Executando função 2")
}

void funcao3(){
    funcao2();
    printf("Executando função 3")
}