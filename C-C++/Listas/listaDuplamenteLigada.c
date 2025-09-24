#include <stdio.h>
#include <stdlib.h>

typedef struct NoDuplo {
    int dado;
    struct NoDuplo* prox;
    struct NoDuplo* ant;
} NoDuplo;

typedef struct {
    NoDuplo* inicio;
    NoDuplo* fim;
} ListaDuplamenteLigada;

void insertAtEnd(ListaDuplamenteLigada* lista, int valor) {
    NoDuplo* novo = (NoDuplo*) malloc(sizeof(NoDuplo));
    if (novo == NULL) {
        return;
    }
    
    novo->dado = valor;
    novo->prox = NULL;
    novo->ant = lista->fim;

    if (lista->fim != NULL) {
        lista->fim->prox = novo;
    } else {
        lista->inicio = novo;
    }
    
    lista->fim = novo;
}

int removeFromEnd(ListaDuplamenteLigada* lista) {
    if (lista->fim == NULL) {
        return -1;
    }

    NoDuplo* temp = lista->fim;
    int valor = temp->dado;

    lista->fim = lista->fim->ant;

    if (lista->fim != NULL) {
        lista->fim->prox = NULL;
    } else {
        lista->inicio = NULL;
    }

    free(temp);
    return valor;
}

void imprimirLista(ListaDuplamenteLigada* lista) {
    NoDuplo* atual = lista->inicio;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}
