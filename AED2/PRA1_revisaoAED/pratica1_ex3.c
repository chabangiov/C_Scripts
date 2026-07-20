/*  Lista encadeada
 *  Define uma lista encadeada em C, onde cada nó contém um inteiro e um
 *  ponteiro para o próximo nó. Listas encadeadas são sempre feitas por nós, onde
 *  cada nó tem um ponteiro para o próximo nó. O último nó aponta para NULL.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
  int data;
  struct No* next;
} No;

int main(void) {
  // Criando o primeiro nó
  No* primeiroNo;
  primeiroNo = (No*)malloc(sizeof(No));
  if (!primeiroNo) {
    fprintf(stderr, "Erro na alocação de memória.\n");
    return 1;
  }
  primeiroNo->data = 10;
  primeiroNo->next = NULL;

  // Criando o segundo nó
  No* segundoNo;
  segundoNo = (No*)malloc(sizeof(No));
  if (!segundoNo) {
    fprintf(stderr, "Erro na alocação de memória.\n");
    return 1;
  }
  segundoNo->data = 20;
  segundoNo->next = NULL;
  primeiroNo->next = segundoNo;

  free(primeiroNo);
  free(segundoNo);

  return 0;
}