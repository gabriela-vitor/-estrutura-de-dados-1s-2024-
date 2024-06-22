#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"


Arvore_no* criar_no(int data) {
    Arvore_no* novo_no = (Arvore_no*) malloc(sizeof(Arvore_no));
    if (novo_no == NULL) {
        perror("Erro ao criar um novo nó.");
        exit(EXIT_FAILURE);
    }
    novo_no->data = data;
    novo_no->left = NULL;
    novo_no->right = NULL;
    return novo_no;
}


Arvore_no* inserir(Arvore_no* root, int data) {
    if (root == NULL) {
        return criar_no(data);
    } else {
        if (data <= root->data) {
            root->left = inserir(root->left, data);
        } else {
            root->right = inserir(root->right, data);
        }
        return root;
    }
}

void inorder(Arvore_no* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


void preorder(Arvore_no* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(Arvore_no* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}


Arvore_no* busca(Arvore_no* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return busca(root->left, data);
    } else {
        return busca(root->right, data);
    }
}

Arvore_no* minValueNode(Arvore_no* node) {
    Arvore_no* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Arvore_no* deletar_no(Arvore_no* root, int data) {
    if (root == NULL) return root;

    if (data < root->data) {
        root->left = deletar_no(root->left, data);
    } else if (data > root->data) {
        root->right = deletar_no(root->right, data);
    } else {
        if (root->left == NULL) {
            Arvore_no* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Arvore_no* temp = root->left;
            free(root);
            return temp;
        }

        Arvore_no* temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deletar_no(root->right, temp->data);
    }
    return root;
}