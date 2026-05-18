/*
 *  Vetor de tamanho dinâmicamente alocado
 *  Leitura de N, alocação do vetor, leitura dos valores, busca do maior valor e liberação de memória
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Lendo o valor de N e guardando na variável
    int n, maior;
    printf("Digite o valor para n:\n");
    scanf("%d", &n);
    if (n <= 0) {
        fprintf(stderr, "Tamanho inválido.\n");
        return 1;
    }
    
    // Declaração do vetor dinamicamente alocado de tamanho N
    int *v;
    v = (int*)malloc(n * sizeof(int));
    if (!v) {
        fprintf(stderr, "Erro de alocação.\n");
        return 1;
    }
    
    // Leitura de valores para o vetor
    printf("Digite os %d valores:\n", n);
    for (int i=0; i<n; i++) {
        printf(" v[%d]: ", i);
        scanf("%d", &v[i]);
    }
    
    // Buscar o maior valor dos elementos
    maior = v[0];
    for (int i=0; i<n; i++) {
        if (maior < v[i]) {
            maior = v[i];
        }
    }
    printf("Maior valor encontrado: %d\n", maior);
    
    // Liberação de memória
    free(v);

    return 0;
}