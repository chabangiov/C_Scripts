/*
 *  Insertion Sort
 *  (Similar to a cards game hand: every time you take a card, you already place it at correct position)
 *  
 */
#include <stdio.h>


void insertion_sort (int *v, int N) {
    int i, j, key;
    for (i = 1; i < N; i++) {
        key = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}


int main() {
    int v[] = {4, 23, -8, 21, 67};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Vetor no inicio:\n");
    for (int i = 0; i < n; i++) {
      printf("v[%d]: %d\n", i, v[i]);
    }

    insertion_sort(v, n);

    printf("Vetor depois da ordenacao:\n");
      for (int i = 0; i < n; i++) {
    printf("v[%d]: %d\n", i, v[i]);
    }
    return 0;
}