#include <stdio.h>
#define MAX 5

//Definição do tipo Lista Seq.
typedef struct {
  int dados[MAX]; // array que guarda os elementos
  int tamanho;  // quantidade atual de elementos na lista
} ListaSequencial;

//Inserção no final da lista
int insertAtEnd(ListaSequencial *lista, int valor) { // declara a lista como ponteiro, assim as alteracoes permanecem fora da funcao
  if(lista->tamanho == MAX) {
    return 0; // lista cheia
  }
  lista->dados[lista->tamanho] = valor; //Essa funcao add o valor ao indice do tamanho e aumenta ele
  lista->tamanho++;
  return 1; // inserção com sucesso
}

int search(ListaSequencial *lista, int valor) {
  int i;
  for(i = 0; i < lista->tamanho; i++) {
    if(lista->dados[i] == valor) {
      return i; // posição do elemento
    }
  }
  return -1; // não encontrado
}

int removeElemento(ListaSequencial *lista, int valor) {
  int i, k = 0;
  for(i = 0; i < lista->tamanho; i++) {
    if(lista->dados[i] == valor) {
      for(k = i; k < lista->tamanho - 1; k++) {
        lista->dados[k] = lista->dados[k+1]; //deslocamento de dados
      }
      lista->tamanho--;
      return 1;
    }
  }
  return 0; // elemento não encontrado
}

void printLista(ListaSequencial *lista) {
    int i;
    printf("[ ");
    for(i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->dados[i]);
    }
    printf("]\n");
}


int main() {
  ListaSequencial lista;
  lista.tamanho = 0; // inicializa lista vazia

  insertAtEnd(&lista, 3);
  insertAtEnd(&lista, 8);
  insertAtEnd(&lista, 6);
  insertAtEnd(&lista, 5);
  insertAtEnd(&lista, 9);

  printf("Lista inicial: ");
  printLista(&lista);

  removeElemento(&lista, 6);
  printf("Depois de remover 6: ");
  printLista(&lista);

  insertAtEnd(&lista, 7);
  printf("Depois de inserir 7: ");
  printLista(&lista);

  return 0;
}

