/* a) Sequência: 8, 9, 7, 9, 3, 2, 3, 8, 4, 6

Selection sort:
[2, 9, 7, 9, 3, 8, 3, 8, 4, 6] (trocou 8 e 2)

[2, 3, 7, 9, 9, 8, 3, 8, 4, 6] (trocou 9 e 3)

[2, 3, 3, 9, 9, 8, 7, 8, 4, 6] (trocou 7 e 3)

[2, 3, 3, 4, 9, 8, 7, 8, 9, 6] (trocou 9 e 4)

[2, 3, 3, 4, 6, 8, 7, 8, 9, 9] (trocou 9 e 6)

[2, 3, 3, 4, 6, 7, 8, 8, 9, 9] (trocou 8 e 7)

b) Sequência: 89, 79, 32, 38, 46, 26, 43, 38, 32, 79

Shell_sort: Comparações: 18. Trocas: 10. 
Merge_sort: Comparações: 25. Trocas: 34.
Quick_sort: Comparações: 22. Trocas: 14.



*/

#include <stdio.h>

void selection_sort(int* v, int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }
        temp = v[i];
        v[i] = v[min_idx];
        v[min_idx] = temp;
    }
}

void bubble_sort(int* v, int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

void shell_sort(int* v, int n) {

    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = v[i];
            for (j = i; j >= gap && v[j - gap] > temp; j -= gap) {
                v[j] = v[j - gap];
            }
            v[j] = temp;
        }
    }
}

void merge_sort(int* v, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(v, l, m);
        merge_sort(v, m + 1, r);
        merge(v, l, m, r);
    }
}

void quick_sort(int* v, int low, int high) {
    if (low < high) {
        int pi = partition(v, low, high);
        quick_sort(v, low, pi - 1);
        quick_sort(v, pi + 1, high);
    }
}

int main() {
    int v[] = {80, 4, 23, -8, 21, 67};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Vetor no inicio:\n");
    for (int i = 0; i < n; i++) {
        printf("v[%d]: %d\n", i, v[i]);
    }

    selection_sort(v, n);
    // bubble_sort(v, n);
    // shell_sort(v, n);

    printf("Vetor depois da ordenacao:\n");
    for (int i = 0; i < n; i++) {
        printf("v[%d]: %d\n", i, v[i]);
    }
    return 0;
}