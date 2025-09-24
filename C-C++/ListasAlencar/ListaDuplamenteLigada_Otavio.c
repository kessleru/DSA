// Inserir um elemento após um valor específico
//Inserir um elemento em uma posição específica

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

void display(ListaDuplamenteLigada* lista) {
    NoDuplo* atual = lista->inicio;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}

void initializeList(ListaDuplamenteLigada* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
}

void insertAfterValue(ListaDuplamenteLigada* lista, int valorBusca, int novoValor) {
    NoDuplo* atual = lista->inicio;
    

    while (atual != NULL && atual->dado != valorBusca) {
        atual = atual->prox;
    }
    

    if (atual == NULL) {
        printf("Valor %d nao encontrado na lista.\n", valorBusca);
        return;
    }
    

    NoDuplo* novo = (NoDuplo*) malloc(sizeof(NoDuplo));
    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }
    
    novo->dado = novoValor;
    novo->prox = atual->prox;
    novo->ant = atual;
    
    if (atual->prox != NULL) {
        atual->prox->ant = novo;
    } else {
        lista->fim = novo;
    }
    
    atual->prox = novo;
    printf("Valor %d inserido apos %d.\n", novoValor, valorBusca);
}

void insertAtPosition(ListaDuplamenteLigada* lista, int posicao, int valor) {

    // Se posição é 0 insere no início
    if (posicao == 0) {
        NoDuplo* novo = (NoDuplo*) malloc(sizeof(NoDuplo));
        if (novo == NULL) {
            printf("Erro ao alocar memoria.\n");
            return;
        }
        
        novo->dado = valor;
        novo->ant = NULL;
        novo->prox = lista->inicio;
        
        if (lista->inicio != NULL) {
            lista->inicio->ant = novo;
        } else {
            lista->fim = novo;
        }
        
        lista->inicio = novo;
        printf("Valor %d inserido na posicao %d.\n", valor, posicao);
        return;
    }
    
    // Percorre a lista até a posição desejada
    NoDuplo* atual = lista->inicio;
    int contador = 0;
    
    while (atual != NULL && contador < posicao) {
        atual = atual->prox;
        contador++;
    }
    
    // Se chegou ao final da lista antes da posição desejada
    if (atual == NULL) {
        printf("Posicao %d invalida. A lista tem apenas %d elementos\n", posicao, contador);
        return;
    }
    
    // Cria o novo nó
    NoDuplo* novo = (NoDuplo*) malloc(sizeof(NoDuplo));
    if (novo == NULL) {
        return;
    }
    
    novo->dado = valor;
    novo->prox = atual;
    novo->ant = atual->ant;
    
    // Ajusta os ponteiros
    if (atual->ant != NULL) {
        atual->ant->prox = novo;
    } else {
        lista->inicio = novo;
    }
    
    atual->ant = novo;
    printf("Valor %d inserido na posicao %d\n", valor, posicao);
}

int main() {
    ListaDuplamenteLigada lista;
    initializeList(&lista);
    
    // Inserir no final
    insertAtEnd(&lista, 10);
    insertAtEnd(&lista, 20);
    insertAtEnd(&lista, 30);
    display(&lista);
    
    // Inserir após valor específico
    insertAfterValue(&lista, 20, 25);
    display(&lista);
    
    // Inserir em posição específica
    insertAtPosition(&lista, 2, 5);
    display(&lista);
    
    // Remover do final
    removeFromEnd(&lista);
    display(&lista);
    
    return 0;
}