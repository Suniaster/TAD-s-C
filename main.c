#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"
#include <time.h>
int main(){

    Geral** Varios;
    Tnode* Root =NULL;
    srand(time(NULL));
    Varios = (Geral**)malloc(15*sizeof(Geral*));
    for(int i=0;i<10;i++){
        Varios[i] = (Geral*)malloc(sizeof(Geral));
        Varios[i]->key = i;
        InsereAVL(&Root, Varios[i]);
    }
    Varios[10] = (Geral*)malloc(sizeof(Geral));
    Varios[11] = (Geral*)malloc(sizeof(Geral));
    Varios[12] = (Geral*)malloc(sizeof(Geral));
    
    Varios[10]->key = 55;
    Varios[11]->key = 56;
    Varios[12]->key = 7;

    InsereAVL(&Root, Varios[10]);
    InsereAVL(&Root, Varios[11]);
    InsereAVL(&Root, Varios[12]);  

    printInOrder(Root);

    FreeArvore(&Root);
    free(Varios);
    return 0;
}