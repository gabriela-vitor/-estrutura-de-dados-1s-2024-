#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(int argc,char *argv[]) {
    TreeNode* root = NULL;

    // Inserindo nós
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Percursos
    printf("Percorrendo em ordem (in-order): ");
    inorder(root);
    printf("\n");

    printf("Percorrendo em pré-ordem (pre-order): ");
    preorder(root);
    printf("\n");

    printf("Percorrendo em pós-ordem (post-order): ");
    postorder(root);
    printf("\n");

    // Buscando um nó
    int chaveBusca = 40;
    TreeNode* resultadoBusca = search(root, chaveBusca);
    if (resultadoBusca != NULL) {
        printf("Nó %d encontrado na árvore.\n", chaveBusca);
    } else {
        printf("Nó %d não encontrado na árvore.\n", chaveBusca);
    }

    // Deletando um nó
    int chaveDelecao = 30;
    root = deleteNode(root, chaveDelecao);
    printf("Depois de deletar %d, percorrendo em ordem: ", chaveDelecao);
    inorder(root);
    printf("\n");

    return 0;
}