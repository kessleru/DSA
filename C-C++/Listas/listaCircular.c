#include <stdio.h>
#include <stdlib.h>

typedef struct NoCircular {
    int dado;
    struct NoCircular* prox;
} NoCircular;

typedef struct {
    NoCircular* inicio;
} ListaCircular;

void insertAtEndCircle(ListaCircular* lista, int valor) {
    NoCircular* novo = (NoCircular*) malloc(sizeof(NoCircular));
    if (novo == NULL) {
        return;
    }
    novo->dado = valor;

    if (lista->inicio == NULL) {
        novo->prox = novo;
        lista->inicio = novo;
    } else {
        NoCircular* temp = lista->inicio;
        while (temp->prox != lista->inicio) {
            temp = temp->prox;
        }
        temp->prox = novo;
        novo->prox = lista->inicio;
    }
}

void imprimirLista(ListaCircular* lista) {
    if (lista->inicio == NULL) {
        printf("Lista: (vazia)\n");
        return;
    }

    NoCircular* atual = lista->inicio;
    printf("Lista: ");
    do {
        printf("%d ", atual->dado);
        atual = atual->prox;
    } while (atual != lista->inicio);
    
    printf("\n");
}
