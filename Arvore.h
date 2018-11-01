#ifndef ARVORE
#define ARVORE

typedef struct TreeNode{
    struct TreeNode* left;
    struct TreeNode* right;
    void* inf;
}Tnode;

typedef struct Something{
    int key;
    // Mais coisa pra baixo
}Geral;

int Insere(Tnode** N, void *aInserir);
void printInOrder(Tnode *N);
void FreeArvore(Tnode **N);

#endif