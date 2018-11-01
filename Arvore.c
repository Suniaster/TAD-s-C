#include "Arvore.h"
#include <stdio.h>
#include <stdlib.h>


void RSD(Tnode** N){
    Tnode* aux;
    aux = (*N)->left;
    (*N)->left = aux->right;
    aux->right = (*N);
    (*N) = aux;
}

void RSE(Tnode** N){
    Tnode* aux;
    aux = (*N)->right;
    (*N)->right = aux->left;
    aux->left = (*N);
    (*N) = aux;
}

int FB(Tnode* N){

    if(N==NULL){
        return 0;
    }
    int left = FB(N->left)+1;
    int right = FB(N->right)+1;

    return (left > right ? left:right);
}

int Repara(Tnode** N){

    int pivo;
    int pLeft, pRight;
    Tnode* aux;
    pivo = FB((*N)->left)-FB((*N)->right);

    if(pivo<-1){
        aux = (*N)->right;
        pRight = FB(aux->left)-FB(aux->right);

        if(pRight < 0){
            RSE(&(*N));
        }
        if(pRight > 0){
            RSD(&aux);
            RSE(&(*N));
        }
        return 1;
    }
    if(pivo>1){
        aux = (*N)->left;
        pLeft = FB(aux->left)-FB(aux->right);

        if(pLeft > 0){
            RSD(&(*N));
        }
        if(pLeft < 0){
            RSE(&aux);
            RSD(&(*N));
        }
        return 1;
    }
    return 0;

}

int Insere(Tnode** N, void *aInserir){
    if((*N)==NULL){
        (*N) = (Tnode*) malloc(sizeof(Tnode));
        (*N)->inf = aInserir;
        (*N)->left =NULL;
        (*N)->right =NULL;
        return 1;
    }
    else{
        Geral *auxInsere = aInserir;
        Geral *auxNode = (*N)->inf;
        if(auxInsere->key > auxNode->key ){
            Insere(&(*N)->right,aInserir);
        }
        else{
            Insere(&(*N)->left, aInserir);
        }
        Repara(&(*N));
        return 0;
    }
}

void printInOrder(Tnode *N){

    if(N==NULL){
        return ;
    }
    Geral *Aux = N->inf;
    printInOrder(N->left);
    printf("%d\n",Aux->key);
    printInOrder(N->right);
}

void FreeArvore(Tnode **N){
    if((*N) == NULL){
        return;
    }
    FreeArvore(&(*N)->left);
    FreeArvore(&(*N)->right);
    free((*N)->inf);
    free((*N));
}