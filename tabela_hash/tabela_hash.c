#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tabela_hash.h"


int hash(char* chave){
    //retornar a primeira letra
    return (toupper(chave[0])-65)*TAM_ALFABETO + toupper(chave[1])-65;
}

char** tabela_hash(){
    char** tabela = malloc(sizeof(char*)*TAM_TABELA);

    for(int i = 0; i < TAM_TABELA; i++){
        tabela[i] = malloc(sizeof(char)*TAM_VALOR);
        strcpy(tabela[i], "");

    }
    return tabela;
}
//guarda o valor na tabela 
void put(char* chave, char* valor, char** tabela){
    //hash diz qual o indice da tabela que guarda o valor
    strcpy(tabela[hash(chave)], valor);

}
//retorna um valor da tabela 
char* get(char* chave, char** tabela){
    return tabela[hash(chave)];

}
int contains(char* chave, char** tabela){
    int tam = strlen(tabela[hash(chave)]);

    int contains = 0;
    if(tam > 0){
        contains = 1;
    }

    return contains;
}
void remover(char* chave, char** tabela){
    strcpy(tabela[hash(chave)], "");
}