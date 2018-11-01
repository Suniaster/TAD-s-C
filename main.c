#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

int main(){

    Geral** Varios;
    Tnode* Root =NULL;

    Varios = (Geral**)malloc(15*sizeof(Geral*));
    for(int i=0;i<15;i++){
        Varios[i] = (Geral*)malloc(sizeof(Geral));
        Varios[i]->key = i * 13;
        Insere(&Root, Varios[i]);
    }

    printInOrder(Root);

    FreeArvore(&Root);
    free(Varios);
    return 0;
}