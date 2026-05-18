/* Insertion Sort
  a) O Insertion Sort é eficiente para pequenos conjuntos de dados ou para
  arrays que já estão quase ordenados, pois ele insere cada elemento na posição
  correta em relação aos elementos anteriores.
  b) O melhor caso ocorre quando o
  array já está ordenado, resultando em uma complexidade de O(n). O pior caso
  ocorre quando o array está ordenado em ordem inversa, resultando em uma
  complexidade de O(n²).
  c) É adaptativo? Sim, pois se adapta ao conjunto de
  dados e pode ser mais eficiente para arrays quase ordenados.
*/

#include <stdio.h>
void insertionSort(int v[], int n) {
  int i, j, chave;
  for (i = 1; i < n; i++) {
    chave = v[i];
    j = i - 1;
    while (j >= 0 && v[j] > chave) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = chave;
  }
}

void main() {
int v[] = {10, 8, -4, 6, 4, 2};
  int n = sizeof(v) / sizeof(v[0]);

  printf("Vetor no inicio:\n");
  for (int i = 0; i < n; i++) {
    printf("v[%d]: %d\n", i, v[i]);
  }

  insertionSort(v, n);
  
  printf("Vetor depois da ordenacao:\n");
  for (int i = 0; i < n; i++) {
    printf("v[%d]: %d\n", i, v[i]);
  }
}