/* Bucket Sort é um algoritmo de ordenação que distribui os elementos de um
 array em um número finito de baldes (ou buckets), e depois ordena cada balde
 individualmente.
 Melhor caso: O(n + k), onde k é o número de baldes
 Pior caso: O(n²), quando todos os elementos caem no mesmo balde.
*/

#include <stdio.h>

void bucketSort(int v[], int n) {
  int i, j;
  int buckets[n][n];
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      buckets[i][j] = 0;
    }
  }
}