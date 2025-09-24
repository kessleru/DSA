//Inserção simples no final
//Contagem de elementos
//Função de soma

#include <stdio.h>
#include <stdlib.h>

typedef struct NoCircular {
    int dado;
    struct NoCircular* prox;
} NoCircular;

typedef struct {
    NoCircular* inicio;
} ListaCircular;

void initializeList(ListaCircular* lista) {
    lista->inicio = NULL;
}

void insertAtEnd(ListaCircular* lista, int valor) {
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

void display(ListaCircular* lista) {
    if (lista->inicio == NULL) {
        printf("Lista vazia\n");
        return;
    }

    NoCircular* atual = lista->inicio;
    printf("Lista: \n");
    do {
        printf("%d ", atual->dado);
        atual = atual->prox;
    } while (atual != lista->inicio);
    printf("\n");
}

int countElements(ListaCircular* lista) {
    if (lista->inicio == NULL) {
        return 0;
    }
    
    int contador = 0;
    NoCircular* atual = lista->inicio;
    
    do {
        contador++;
        atual = atual->prox;
    } while (atual != lista->inicio);
    
    return contador;
}

int sumElements(ListaCircular* lista) {
    if (lista->inicio == NULL) {
        return 0;
    }
    
    int soma = 0;
    NoCircular* atual = lista->inicio;
    
    do {
        soma += atual->dado;
        atual = atual->prox;
    } while (atual != lista->inicio);
    
    return soma;
}

int main() {
    ListaCircular lista;
    initializeList(&lista);
    
    printf("Soma da lista vazia: %d\n", sumElements(&lista));
    
    insertAtEnd(&lista, 10);
    insertAtEnd(&lista, 20);
    insertAtEnd(&lista, 30);
    
    display(&lista);
    printf("Total de elementos: %d\n", countElements(&lista));
    printf("Soma dos elementos: %d\n", sumElements(&lista));
    
    return 0;
}