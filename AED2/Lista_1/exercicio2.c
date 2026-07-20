#include <stdio.h>

void verificarOrdemCrescente (int* v, int n) {
    int conta = 0;
    for(int i=0; i<n-1; i++) {
        if(v[i] < v[i + 1]) {
            conta ++;
        }
    }
    if (conta == n-1) {
            printf("ORDENADO\n");
        }
}

int main() {
    int v[] = {1, 2, 3, 4, 5};
    int n = sizeof(v) / sizeof(v[0]);
    verificarOrdemCrescente(v, n);
    return 0;
}