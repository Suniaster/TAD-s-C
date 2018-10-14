#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

Fila* CriaFila(){
    Fila* novaFila = (Fila*)malloc(sizeof(Fila));

    novaFila->inicio = (cel*)malloc(sizeof(cel));
    novaFila->fim = novaFila->inicio;

    novaFila->tamanho=0;

    return novaFila;
}

int FilaVazia(Fila* verificando){

    if(verificando->inicio == verificando->fim)return 1;
    else return 0;

}

void InsereFila(Fila* aInserir, void* inf){
    cel* inserindo = (cel*)malloc(sizeof(cel));
    inserindo->info = inf;

    aInserir->fim->prox = inserindo;
    aInserir->fim = aInserir->fim->prox;
    
    aInserir->tamanho++;
}

void* RemoveFila(Fila* aRemover){
    void* removido;
    cel* auxFree;

    auxFree = aRemover->inicio->prox;
    aRemover->inicio->prox = auxFree->prox;

    removido = auxFree->info;
    free(auxFree);
    return removido;
}

void FreeFila(Fila* aLiberar){
    while(!FilaVazia(aLiberar)){
        free(RemoveFila(aLiberar));
    }
    free(aLiberar->inicio);
    free(aLiberar);
}