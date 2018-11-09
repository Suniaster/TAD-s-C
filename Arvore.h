#ifndef ARVORE
#define ARVORE

typedef struct TreeNode{
    struct TreeNode* left;
    struct TreeNode* right;
    void* inf;
}Tnode;

/* Estrutura Molde para uso da árvore AVL*/ 
typedef struct Something{
    int key;
    // Mais coisa pra baixo
}Geral;
/* Métodos relacionados a árvore AVL */
int InsereAVL(Tnode** N, void *aInserir);
void* ProcuraAVL(Tnode *N, int aProcurar);
void FreeArvore(Tnode **N);

/* Formas diferentes de Print'ss */
void printInOrder(Tnode *N);
void printPosOrder(Tnode *N);
void printPreOrder(Tnode *N);
#endif