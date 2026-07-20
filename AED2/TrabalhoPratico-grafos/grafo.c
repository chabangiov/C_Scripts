#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

Grafo* carregarGrafo(char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    
    // Tratamento de erro
    if (arquivo == NULL) {
        printf("Erro: Arquivo '%s' nao encontrado.\n", nomeArquivo);
        return NULL; 
    }

    // Aloca a estrutura principal do Grafo
    Grafo *g = (Grafo*) malloc(sizeof(Grafo));
    if (g == NULL) {
        printf("Erro: Falha na alocacao de memoria.\n");
        fclose(arquivo);
        return NULL;
    }

    // Lê a primeira linha
    fscanf(arquivo, "%d %d", &g->V, &g->A);

    // Aloca o vetor de listas de adjacencia
    g->lista = (No**) malloc(g->V * sizeof(No*));
    for (int i = 0; i < g->V; i++) {
        g->lista[i] = NULL;
    }

    // Lê as arestas e insere no grafo
    int origem, destino, peso;
    for (int i = 0; i < g->A; i++) {
        fscanf(arquivo, "%d %d %d", &origem, &destino, &peso);
        adicionarAresta(g, origem, destino, peso);
    }

    fclose(arquivo);
    return g;
}

void adicionarAresta(Grafo *g, int origem, int destino, int peso) {
    // 1. Cria e inicializa o novo nó
    No *novoNo = (No*) malloc(sizeof(No));
    novoNo->destino = destino;
    novoNo->peso = peso;
    novoNo->prox = NULL;

    // 2. Ponteiros auxiliares para percorrer a lista da 'origem'
    No *atual = g->lista[origem];
    No *anterior = NULL;

    // 3. Encontra a posição correta (ordenado de forma crescente pelo 'destino')
    while (atual != NULL && atual->destino < destino) {
        anterior = atual;
        atual = atual->prox;
    }

    // 4. Faz a inserção na posição encontrada
    if (anterior == NULL) {
        // Insere no início da lista (ou a lista estava vazia)
        novoNo->prox = g->lista[origem];
        g->lista[origem] = novoNo;
    } else {
        // Insere no meio ou no fim da lista
        novoNo->prox = atual;
        anterior->prox = novoNo;
    }
}

