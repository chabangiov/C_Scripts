/*
 *  Bubble Sort
 *  (Compara todos os elementos do e vai realizando as trocas, quando
 * necessário, até deixar o último elemento correspondente a regra de ordenação.
 * Depois segue fazendo o mesmo até o penúltimo elemento, e assim por diante.
 */
#include <stdio.h>

void troca(int* x, int* y) {
  int aux;
  aux = *x;
  *x = *y;
  *y = aux;
}

void bubble_sort(int* v, int N) {
  for (int i = 0; i < (N - 1); i++) {
    for (int j = 0; j < (N - i - 1); j++) {
      if (v[j] > v[j + 1]) {
        troca(&v[j], &v[j + 1]);
      }
    }
  }
}

void main() {
  int v[] = {4, 23, -8, 21, 67};
  int n = sizeof(v) / sizeof(v[0]);

  printf("Vetor no inicio:\n");
  for (int i = 0; i < n; i++) {
    printf("v[%d]: %d\n", i, v[i]);
  }

  bubble_sort(v, n);

  printf("Vetor depois da ordenacao:\n");
  for (int i = 0; i < n; i++) {
    printf("v[%d]: %d\n", i, v[i]);
  }
}