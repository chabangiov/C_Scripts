#include <stdio.h>

void procurarElemento (int* v_ordenado, int n, int elem) {
    int i;
    for(i=0; i<n; i++) {
        if(elem == v_ordenado[i]) {
            printf("Elemento encontrado na posicao: %d\n", i);
            return;
        }
    }
    printf("Elemento nao encontrado\n");
}

int main() {
    int v_ordenado[] = {1, 3, 5, 7, 9};
    int n = sizeof(v_ordenado) / sizeof(v_ordenado[0]);
    int elem = 5;

    procurarElemento(v_ordenado, n, elem);
    
    return 0;
}