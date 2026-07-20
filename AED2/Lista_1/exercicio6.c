/* 1) pivot = 22
    26 65 45 73 10 18 78 93 70 49 23 22
    i = -1, j = 0
    i = -1, j = 1
    i = -1, j = 2
    i = -1, j = 3
    i = -1, j = 4 -> swap v[0] and v[4]
    i = 0, j = 5 -> swap v[1] and v[5]
    i = 1, j = 6
    i = 1, j = 7
    i = 1, j = 8
    i = 1, j = 9
    i = 1, j = 10 -> swap v[2] and v[10]
    i = 2, j = 11 -> swap v[3] and v[11]
    i + 1 -> swap v[3] and v[high]
    Vetor no final: [10, 18, 22, 73, 26, 65, 78, 93, 70, 49, 23, 45]
*/


#include <stdio.h>

void partition_quicksort(int* v, int low, int high) {
    int pivot = v[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (v[j] < pivot) {
            i++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    int temp = v[i + 1];
    v[i + 1] = v[high];
    v[high] = temp;
    return i + 1;
}

int main() {
    int v[] = {26, 65, 45, 73, 10, 18, 78, 93, 70, 49, 23, 22};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Vetor no inicio:\n");
    for (int i = 0; i < n; i++) {
        printf("v[%d]: %d\n", i, v[i]);
    }

    partition_quicksort(v, 0, n - 1);

    printf("Vetor depois da ordenacao:\n");
    for (int i = 0; i < n; i++) {
        printf("v[%d]: %d\n", i, v[i]);
    }
    return 0;
}