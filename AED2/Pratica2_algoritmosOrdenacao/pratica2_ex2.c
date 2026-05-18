/* Selection Sort.
  a) A ideia principal do Selection Sort é
*/

void selectionSort(int v[], int n) {
  int i, j, min, temp;
  for (i = 0; i < n - 1; i++) {
    min = i;
    // Supõe que o menor elemento seja o primeiro mesmo
    for (j = i + 1; j < n; j++) {
      if (v[j] < v[min]) {
        min = j;
        // Se o primeiro elemento ja não for o menor, efetua uma troca.
      }
    }
    temp = v[i];
    v[i] = v[min];
    v[min] = temp;
  }
}

int main() {
  int v[] = {12, 34, 8, 9, 22};
  int n = sizeof(v) / sizeof(v[0]);

  printf("Vetor no inicio:\n");
  for (int i = 0; i < n; i++) {
    printf("v[%d]: %d\n", i, v[i]);
  }

  selectionSort(v, n);

  printf("Vetor depois da ordenacao:\n");
  for (int i = 0; i < n; i++) {
    printf("v[%d]: %d\n", i, v[i]);
  }
  return 0;
}