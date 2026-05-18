/*  Inserção no INÍCIO em Lista Encadeada
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaração do Nó
typedef struct No {
  int dado;
  struct No* prox;
} No;

// Funções para iserir no início de uma Lista Encadeada
// POR VALOR
No* inserirElementoNoInicioValor(int elemento, No* antigaCabeca) {
  // A função deve retornar um tipo 'No*'
  No* novoNo = (No*)malloc(sizeof(No));
  if (!novoNo) {
    fprintf(stderr, "Erro na alocação de memoria.\n");
    exit(1);
  }
  novoNo->dado = elemento;
  novoNo->prox = antigaCabeca;

  return novoNo;
}

// POR REFERÊNCIA (modifica o ponteiro diretamente na memória)
void inserirElementoNoInicioReferencia(int elemento, No** lista) {
  No* novoNo = (No*)malloc(sizeof(No));
  if (!novoNo) {
    fprintf(stderr, "Erro na alocação de memória.\n");
    exit(1);
  }
  novoNo->dado = elemento;
  novoNo->prox = *lista;
  *lista = novoNo;
}

int main() {
  No* no;
  no = (No*)malloc(sizeof(No));
  no->dado = 20;
  no->prox = NULL;

  int n1 = 10;
  no = inserirElementoNoInicioValor(n1, no);
  // Adiciona elemento 10 ao início por VALOR

  int n2 = 5;
  inserirElementoNoInicioReferencia(n2, &no);
  // Adiciona elemento 5 ao início por REFERÊNCIA

  return 0;
}