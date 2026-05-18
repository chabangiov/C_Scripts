/*  Bubble Sort
  a) a complexidade do pior caso é O(n²)
  b) Bubble Sort é estável? SIM, pois as trocas são feitas preservando a ordem
  dos elementos
  c) Inserção da variável 'trocou' para analisar se houve alguma troca durante o
  laço mais interno

*/
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int v[], int n) {
  int i, j, temp;
  for (i = 0; i < (n - 1); i++) {
    int trocou = 0;
    for (j = 0; j < n - i - 1; j++) {
      if (v[j] > v[j + 1]) {
        temp = v[j];
        v[j] = v[j + 1];
        v[j + 1] = temp;
        trocou = 1; /*  Contabiliza na variável 'trocou' que houve troca, ou
                        seja, esse array ainda não está ordenado.
                    */
      }
    }
  }
}

void main() {
  int v[] = {10, 8, -4, 6, 4, 2};
  int n = sizeof(v) / sizeof(v[0]);

  printf("Vetor no inicio:\n");
  for (int i = 0; i < n; i++) {
    printf("v[%d]: %d\n", i, v[i]);
  }

  bubbleSort(v, n);
  
  printf("Vetor depois da ordenacao:\n");
  for (int i = 0; i < n; i++) {
    printf("v[%d]: %d\n", i, v[i]);
  }
}