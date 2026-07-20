#include <stdio.h>

void ordenaDecrescente(int* v, int n) { // Bubble Sort
    int i, j, aux;
    for(i=0; i<(n-1); i++) {
        for(j=0; j<(n-i-1); j++) {
            if(v[j] < v[j+1]) {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }

}

void main() {
  int v[] = {80, 4, 23, -8, 21, 67};
  int n = sizeof(v) / sizeof(v[0]);

  printf("Vetor no inicio:\n");
  for (int i = 0; i < n; i++) {
    printf("v[%d]: %d\n", i, v[i]);
  }

  ordenaDecrescente(v, n);

  printf("Vetor depois da ordenacao:\n");
  for (int i = 0; i < n; i++) {
    printf("v[%d]: %d\n", i, v[i]);
  }
}