/*
 *         Matriz de tamanho dinamicamente alocado
 */

#include <stdlib.h>
#include <stdio.h>

int main()
{
    // Declaração das variáveis
    int n, m;
    int **mat;
    long soma = 0;
    
    // Lendo o valor de N e guardando na variável
    printf("Digite o valor para N (linhas):\n");
    scanf("%d", &n);
    printf("Digite o valor para M (colunas):\n");
    scanf("%d", &m);
    if (n <= 0 || m <= 0) {
        fprintf(stderr, "Tamanho inválido.\n");
        return 1;
    }
    
    // Criando matriz dinamicamente alocada
    // Aloca vetor de ponteiros (linhas)
    mat = (int **)malloc(n * sizeof(int *));
    if (!mat) { fprintf(stderr, "Erro de alocação.\n"); return 1; }
    
    // Aloca cada linha
    for (int i= 0; i < n; i++) {
        mat[i] = (int *)malloc(m * sizeof(int));
        if (!mat[i]) { fprintf(stderr, "Erro de alocação.\n"); return 1; }
    }
    
    // Leitura de valores para a Matriz
    int tamanho;
    tamanho = n * m;
    printf("Digite os %d valores:\n", tamanho);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf(" m[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    // Cálculo da soma dos elementos da Matriz
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            soma += mat[i][j];
        }
    }
    printf("Soma dos elementos: %ld", soma);
    
    
    // liberação de memória
    for (int i = 0; i < n; i++) {
        free(mat[i]); // Libera cada linha
    }
    free(mat); // Libera o vetor de ponteiros

    
    return 0;
}