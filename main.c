#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"
#include <time.h>
int main(){

    Geral** Varios;
    Tnode* Root =NULL;
    srand(time(NULL));
    Varios = (Geral**)malloc(15*sizeof(Geral*));
    /* Testando inserção de elementos ordenados */
    for(int i=0;i<10;i++){
        Varios[i] = (Geral*)malloc(sizeof(Geral));
        Varios[i]->key = i;
        InsereAVL(&Root, Varios[i]);
    }

    /* Testando inserção de elementos desordeandos */
    Varios[10] = (Geral*)malloc(sizeof(Geral));
    Varios[11] = (Geral*)malloc(sizeof(Geral));
    Varios[12] = (Geral*)malloc(sizeof(Geral));
    
    Varios[10]->key = 58;
    Varios[11]->key = 5;
    Varios[12]->key = 7;

    InsereAVL(&Root, Varios[10]);
    InsereAVL(&Root, Varios[11]);
    InsereAVL(&Root, Varios[12]);  

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