#include <stdio.h>

int particiona(int v[], int inicio, int fim) {
  int pivo = v[fim];
  int i = inicio - 1;
  int j, temp;
  for (j = inicio; j < fim; j++) {
    if (v[j] <= ) { //
      i++;
      temp = v[i];
      v[i] = v[j];
      v[j] = temp;
    }
  }
  temp = v[i + 1];
  v[i + 1] = v[fim];
  v[fim] = temp;
  return i + 1; //
}
void quickSort(int v[], int inicio, int fim) {
  if (inicio < fim) {
    int p = particiona(v, inicio, fim);
    quickSort(v, inicio, ); //
    quickSort(v, , fim); //
  }
}

int main (void) {
  int v[] = {12, 34, 8, 9, 22};
  int n = sizeof(v) / sizeof(v[0]);

  printf("Vetor no inicio:\n");
  for (int i = 0; i < n; i++) {
    printf("v[%d]: %d\n", i, v[i]);
  }

  quickSort(v, 0, n - 1);

  printf("Vetor depois da ordenacao:\n");
  for (int i = 0; i < n; i++) {
    printf("v[%d]: %d\n", i, v[i]);
  }
  return 0;
}
