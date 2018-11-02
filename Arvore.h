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

int InsereAVL(Tnode** N, void *aInserir);
void FreeArvore(Tnode **N);
void* ProcuraAVL(Tnode *N, int aProcurar);

void printInOrder(Tnode *N);
void printPosOrder(Tnode *N);
void printPreOrder(Tnode *N);
#endif