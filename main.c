#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"
#include <time.h>

#define SIZE 1048576
int main(){

    Geral** Varios;
    Tnode* Root =NULL;
    srand(time(NULL));
    Varios = (Geral**)malloc((SIZE+10)*sizeof(Geral*));
    /* Testando inserção de elementos ordenados */
    for(int i=0;i < SIZE ;i++){
        Varios[i] = (Geral*)malloc(sizeof(Geral));
        Varios[i]->key = i;
        InsereAVL(&Root, Varios[i]);
    }

    /* Testando inserção de elementos desordeandos */
    Varios[SIZE] = (Geral*)malloc(sizeof(Geral));
    Varios[SIZE+1] = (Geral*)malloc(sizeof(Geral));
    Varios[SIZE+2] = (Geral*)malloc(sizeof(Geral));
    
    Varios[SIZE]->key = 58;
    Varios[SIZE+1]->key = 5;
    Varios[SIZE+2]->key = 7;

    InsereAVL(&Root, Varios[SIZE]);
    InsereAVL(&Root, Varios[SIZE+1]);
    InsereAVL(&Root, Varios[SIZE+2]);  

    /* Conferindo Formato da arvore */
    printPreOrder(Root);

    /* Testando Procura de elementos */
    Geral* Aux;
    Aux = ProcuraAVL(Root, 2);
    if(Aux != NULL)printf("Elemento Achado!: %d\n", Aux->key);
    else printf("Elemento Não achado\n");


    /* Testando os Free's */
    FreeArvore(&Root);
    free(Varios);
    return 0;
}