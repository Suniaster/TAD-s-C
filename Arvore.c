#include "Arvore.h"
#include <stdio.h>
#include <stdlib.h>

/*  Rotação Simples Direita:
    Feita quando há um desebalanceamento a esquerda do nó passado como paramêtro
    e também um desbalanceamento a esquerda em seu filho da esquerda.
        X                    Y
       /                    / \
      Y       RSD(X) ->    Z   X
     / 
    Z  
    É passado como parâmetro o nó onde o desbalanceamento é maior que 1.
*/
void RSD(Tnode** N){
    Tnode* aux;
    aux = (*N)->left;
    (*N)->left = aux->right;
    aux->right = (*N);
    (*N) = aux;
}

/*  Rotação Simples Esquerda:
    Feita quando há um desebalanceamento a direita do nó passado como paramêtro
    e também um desbalanceamento a direita em seu filho da direita.
    X                       Y
     \                     / \
      Y       RSE(X)->    X   Z
       \
        Z     
    É passado como parâmetro o nó onde o Fator de Balancealemto é menor que -1.    
*/
void RSE(Tnode** N){
    Tnode* aux;
    aux = (*N)->right;
    (*N)->right = aux->left;
    aux->left = (*N);
    (*N) = aux;
}

//  Calcula a altura de determinado nó, usando estratégia recursiva
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

/*  Fator de Balanceamento:
    O FB de um determinado nó é dado pela altura da arvore do seu filho a esquerda menos
    a altura da arvore do seu filho a direita.
    Dessa forma é possível saber se algum dos lados da arvore está maior que o outro.
*/
int FB(Tnode* N){
    if(N==NULL){
        return 0;
    }
    return Altura(N->left) - Altura(N->right);
}

/* Função para concertar o balanceamento de determinado nó:
    Primeiramente é chamada a função do Fator de Balancemento.
    Caso haja algum desbalaceamento, ele é concertado usando
    uma rotação simples, ou uma rotação dupla.
    --Rotação dupla:
      0               0
     /                 \
    0         ou        0
     \                 /
      0               0
    A rotação dupla consiste de duas rotações simples em sequencia, uma
    aplicada no filho que esteja desbalanceado e outra no próprio nó.
    Exemplo:
      X                  X                Z
     /                  /                / \
    Y      RSE(Y)->    Z    RSD(X)->    Y   X
     \                /  
      Z              Y
    Analogamente, para o caso inverso onde há a necessidade de Rotação dupla, é 
    usado o mesmo procedimento, porém é primeiro feito RSD e depois RSE.

    Retorna 1 caso tenha acontecido alguma mudança na árvore.
    Retorna 0 caso contrário.
*/
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

/*  Função de Inserção na Ávore AVL:
    Recebe como parâmetro a raiz da Arvore que está o elemento será inserido,
    e também um ponteiro para alguma estrutura que possua o atributo "key" (IMPORTANTE).
    Na forma como foi implementada, há o uso de uma estrutura auxiliar chamada "Geral",
    portanto, para casos específicos de uso, é necessária a troca dessa estrutura.

    Para a inserção de elementos na Árvore AVL, o o filho da esquerda deve ser menor ou 
    igual a seu pai, e o filho da direita deve ser maior ou igual ao mesmo. 

    Função Recursiva.

    Para chegar a uma folha é necessário log(n) chamadas recursivas.

    Inserções só são feitas nas folhas da arvore, e caso essa inserção crie algum desba-
    lanceamento, para cada nó que estava no caminho até a inserção é verificado se ele possui
    algum desbalanceamento.

*/
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

    /* Funções de Print */
/*  Método Pre-Order:
    -> É feito determinado processo no nó; 
    -> Chama-se recursivamente a função pro seu filho a esquerda;
    -> Chama-se recursivamente a função pro seu filho a direita;
    Usado para conferir formato da árvore,
    elementos são printados mostrando quem são seus filhos.
     Ex:    A
           / \
          B   C
         / \ / \
        D  E F  G
    Ordem: A B D E C F G
*/
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

/*  Método In-Order:
    -> Chama-se recursivamente a função pro seu filho a esquerda;
    -> É feito determinado processo no nó; 
    -> Chama-se recursivamente a função pro seu filho a direita;
    Elementos são printados em ordem crescente
*/
void printInOrder(Tnode *N){

    if(N==NULL){
        return ;
    }
    Geral *Aux = N->inf;
    printInOrder(N->left);
    printf("%d\n",Aux->key);
    printInOrder(N->right);
}

/* Método Pós-Order:
    -> Chama-se recursivamente a função pro seu filho a esquerda;
    -> Chama-se recursivamente a função pro seu filho a direita;    
    -> É feito determinado processo no nó;
    Passa por cada nivel de altura da arvore, começando do mais inferior e indo
    da equerda para a direita.
    Ex:     A
           / \
          B   C
         / \ / \
        D  E F  G
    Ordem: D E F G B C A;     
*/     
void printPosOrder(Tnode *N){

    if(N==NULL){
        return ;
    }
    Geral *Aux = N->inf;
    printPosOrder(N->left);
    printPosOrder(N->right);
    printf("%d\n",Aux->key);    
}

/*  Procura por determinada "key" na árvore AVL:
    - Verifica se o elemento já foi encontrado;
    - Caso sim: retorna-o;
    - Caso não: Chama recursivamente a função:
        -Para seu filho a esquerda, caso a "key" seja menor do que a informação do nó;
        -Para seu filho a direita, caso a "key" seja maior do que a informação do nó;
    Em caso ne não encontrar a key, ou seja, quando chegar em uma folha inexistente, retorna "NULL"
*/
void* ProcuraAVL(Tnode *N, int aProcurar){
    if(N == NULL){
        return NULL;
    }
    Geral* Aux;
    Aux = N->inf;
    if(aProcurar > Aux->key){
        return ProcuraAVL(N->right, aProcurar);
    }
    if(aProcurar < Aux->key){
        return ProcuraAVL(N->left, aProcurar);
    }
    return N->inf;
}

/*  Liberação dos dados alocados pela árvore.
    As estruturas que nela estão armazenadas também são
    liberadas.
    Utiliza-se do metodo Pós-Order.
*/
void FreeArvore(Tnode **N){
    if((*N) == NULL){
        return;
    }
    FreeArvore(&(*N)->left);
    FreeArvore(&(*N)->right);
    free((*N)->inf);
    free((*N));
}