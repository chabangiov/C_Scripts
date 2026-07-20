#include <stdio.h>
#include <string.h>

struct pessoa {
    int matricula;
    char nome[30];
    float nota;
};


void ordenarPessoas(struct pessoa arr[], int n, int criterio) {
    int i, j;
    struct pessoa chave;
    
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;

        while (j >= 0) {
            int deveTrocar = 0;
            
            if (criterio == 1 && arr[j].matricula > chave.matricula) {
                deveTrocar = 1;
            } 
            else if (criterio == 2 && strcmp(arr[j].nome, chave.nome) > 0) {
                deveTrocar = 1;
            } 
            else if (criterio == 3 && arr[j].nota > chave.nota) {
                deveTrocar = 1;
            }

            if (deveTrocar) {
                arr[j + 1] = arr[j];
                j = j - 1;
            } else {
                break;
            }
        }
        arr[j + 1] = chave;
    }
}