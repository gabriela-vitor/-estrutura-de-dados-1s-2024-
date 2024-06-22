typedef struct Arvore_no {
    int data;
    struct Arvore_no *left;
    struct Arvore_no *right;
} Arvore_no;

Arvore_no* criar_no(int data);
Arvore_no* inserir(Arvore_no* root, int data);
void inorder(Arvore_no* root);
void preorder(Arvore_no* root);
void postorder(Arvore_no* root);
Arvore_no* busca(Arvore_no* root, int data);
Arvore_no* minValueNode(Arvore_no* node);
Arvore_no* deletar_no(Arvore_no* root, int data);