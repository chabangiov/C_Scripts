#include <stdio.h>

void inserirElemento (int* v_ordenado, int n, int elem) {
    int i, j, aux;
    for(i=0; i<n; i++) {
        if(elem < v_ordenado[i]) {
            aux = v_ordenado[i];
            v_ordenado[i] = elem;
            elem = aux;
        }
    }
}

int main() {
    int v_ordenado[] = {1, 3, 5, 7, 9};
    int n = sizeof(v_ordenado) / sizeof(v_ordenado[0]);
    int elem = 6;
    inserirElemento(v_ordenado, n, elem);
    for(int i=0; i<n; i++) {
        printf("v[%d]: %d\n", i, v_ordenado[i]);
    }
    return 0;
}