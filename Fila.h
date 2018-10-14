#ifndef FILA
#define FILA

typedef struct singleLinkedNode{
    void* info;
    struct singleLinkedNode* prox;
}cel;

typedef struct Fila{

    cel* inicio;
    cel* fim;
    int tamanho;
}Fila;

Fila* CriaFila();
int FilaVazia(Fila* verificando);
void InsereFila(Fila* aInserir, void* inf);
void* RemoveFila(Fila* aRemover);
void FreeFila(Fila* aLiberar);

#endif FILA