#include <stdio.h>
#include <stdlib.h>

//Estrutura
typedef struct No {
    int dado;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
} ListaLigadaSimples;

//Inserção no início
void insertAtBeginning(ListaLigadaSimples* lista, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;
}

//Remoção do início
int removeFromBeginning(ListaLigadaSimples* lista) {
    if(lista->inicio == NULL) {
        return -1; // lista vazia
    }
    No* temp = lista->inicio;
    lista->inicio = lista->inicio->prox;
    int valor = temp->dado;
    free(temp);
    return valor;
}


void display(ListaLigadaSimples* lista) {
    if(lista->inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    
    printf("Lista: ");
    No* atual = lista->inicio;
    while(atual != NULL) {
        printf("%d", atual->dado);
        if(atual->prox != NULL) {
            printf(" -> ");
        }
        atual = atual->prox;
    }
    printf(" -> NULL\n");
}
