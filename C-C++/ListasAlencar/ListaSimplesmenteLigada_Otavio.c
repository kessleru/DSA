//Inserir múltiplos elementos no início da lista
//Buscar um elemento na lista
//Remover um elemento do início da lista

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

void insertFiveValuesAtBeginning(ListaLigadaSimples* lista) {
    int valores[5];
    for (int i = 0; i < 5; i++) {
        printf("Insira o %d valor\n", i + 1);
        scanf("%d", &valores[i]); 
        No* novo = (No*) malloc(sizeof(No));
        novo->dado = valores[i];
        novo->prox = lista->inicio;
        lista->inicio = novo;
    }
}

void searchForValue(ListaLigadaSimples* lista) {
    int valor = 0;
    printf("Insira o valor que deseja procurar: \n");
    scanf("%d", &valor); 
    
    if (lista->inicio == NULL) {
        printf("Lista vazia\n");
        return;
    }

    No* atual = lista->inicio;
    int encontrado = 0;
    
    while (atual != NULL) {
        if(atual->dado == valor) {
            printf("O valor %d foi encontrado na lista\n", valor);
            encontrado = 1;
            break;
        }
        atual = atual->prox;
    }
    
    if (!encontrado) {
        printf("O valor %d nao foi encontrado na lista\n", valor);
    }
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

//Exibir a lista
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

void initializeList(ListaLigadaSimples* lista) {
    lista->inicio = NULL;
}

int main() {
    ListaLigadaSimples lista;
    initializeList(&lista);
    
    insertFiveValuesAtBeginning(&lista);

    display(&lista);

    searchForValue(&lista);
    return 0;
}
