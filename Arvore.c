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
int Altura(Tnode* N){
    int esq, dir;

    if(N == NULL){
        return 0;
    }
    esq = Altura(N->left);
    dir = Altura(N->right);

    if(esq > dir){
        return esq + 1;
    }   
    else{
        return dir + 1;
    } 
}

int FB(Tnode* N){
    if(N==NULL){
        return 0;
    }
    return Altura(N->left) - Altura(N->right);
}

int Repara(Tnode** N){

    int pivo;
    int pLeft, pRight;
    Tnode* aux;
    pivo = FB((*N));

    if(pivo<-1){
        aux = (*N)->right;
        pRight = FB(aux);

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
        pLeft = FB(aux);

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

int InsereAVL(Tnode** N, void *aInserir){
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
            InsereAVL(&(*N)->right,aInserir);
        }
        else{
            InsereAVL(&(*N)->left, aInserir);
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
void printPreOrder(Tnode *N){

    if(N==NULL){
        return ;
    }
    Geral *Aux = N->inf;
    printf("%d ",Aux->key);
    Geral *aux2;
    if(N->left != NULL){
        aux2 = N->left->inf;
        printf("Filho da esquerda: %d ||", aux2->key);
    }
    if(N->right != NULL){
        aux2 = N->right->inf;
        printf("Filho da Direita: %d", aux2->key);
    }

    printf("\n");
    printPreOrder(N->left);
    printPreOrder(N->right);
}
void printPosOrder(Tnode *N){

    if(N==NULL){
        return ;
    }
    Geral *Aux = N->inf;
    printPosOrder(N->left);
    printPosOrder(N->right);
    printf("%d\n",Aux->key);    
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

void* ProcuraAVL(Tnode *N, int aProcurar){

}