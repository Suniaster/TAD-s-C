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
            RSE((*N));
        }
        else{
            RSD(aux);
            RSE((*N));
        }
        return 1;
    }
    if(pivo>1){
        aux = (*N)->left;
        pLeft = FB(aux->left)-FB(aux->right);

        if(pLeft > 0){
            RSD((*N));
        }
        else{
            RSE(aux);
            RSD((*N));
        }
        return 1;
    }
    return 0;

}

int Insere(Tnode** N, void *aInserir){
    if((*N)==NULL){
        (*N) = (Tnode*) malloc(sizeof(Tnode));
        (*N)->inf = aInserir;
        return 1;
    }
    else{

        if((Geral*)aInserir->key > (*N)->inf->key ){
            Insere((*N)->right,aInserir);
        }
        else{
            Insere((*N)->left, aInserir);
        }
        Repara((*N));
        return 0;
    }
}

void printInOrder(Tnode *N){

    if(N==NULL){
        return ;
    }
    printInOrder(N->left);
    printf("%d\n",N->inf->key);
    printInOrder(N->right);
}