#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

int main(int argc, char* argv[]){

    No* H = no('A', NULL);
    No* n2 = no('B', NULL);
    No* n3 = no('C', NULL);
    No* n4 = no('D', NULL);
    No* n5 = no('E', NULL);
    No* Hc = copiar_lista(H);

    inserir_no(H, n2);
    inserir_no(H, n3);
    inserir_no(H, n4);
    inserir_no(H, n5);


    imprimir_lista(H);
    printf("\n copia\n");
    imprimir_lista(Hc);
    
    H->proximo_no->valor = 'X';
    Hc->valor = 'U';

    printf("\n");
    imprimir_lista(H);
    printf("\n copia\n");
    imprimir_lista(Hc);

    liberar_lista(Hc);
    

    printf("\n qtd = %d", quantidade_nos(H));

    printf("\n E existe na lista? %d", verificar_existencia(H, 'E'));
    printf("\n E ocorre qnts vezes na lista? %d\n", verificar_ocorrencias(H, 'E'));

    imprimir_inversa(H);

    printf("\n");
    inserir_no_i(H, 2, no('J', NULL));
    imprimir_lista(H);
    printf("\n");

    remover_no_i(H, 6, NULL);
    imprimir_lista(H);
    printf("\n");


   
    exit(0);
}

