#include <stdio.h>
#include <stdlib.h>
#include "cod_base.c"

Grafo* criarGrafo(int vertices){
    Grafo *g = (Grafo*)malloc(sizeof(Grafo));
    g->V = vertices;

    g->lista = (No**)malloc(vertices * sizeof(No*));
    for(int i = 0; i < vertices; i++){
        g->lista[i] = NULL;
    }
    return g;
}

void adicionarAresta(Grafo *g, int origem, int destino, int peso){
    No *novo = (No*)malloc(sizeof(No));
    novo->destino = destino;
    novo->peso = peso;
    novo->prox = g->lista[origem];
    g->lista[origem] = novo;
}

void main() {
    Grafo *g = criarGrafo(5);
    adicionarAresta(g, 0, 1, 1);
    adicionarAresta(g, 0, 2, 1);
    adicionarAresta(g, 1, 3, 1);
    adicionarAresta(g, 2, 3, 1);
    adicionarAresta(g, 3, 4, 1);
    adicionarAresta(g, 4, 0, 1);

    // Imprime o grafo
    for(int i = 0; i < g->V; i++){
        No *aux = g->lista[i];
        printf("Vértice %d: ", i);
        while(aux != NULL){
            printf("-> %d (peso: %d) ", aux->destino, aux->peso);
            aux = aux->prox;
        }
        printf("\n");
    }
}

/*  
1) Complexidade da inserção: O(1)

2) Vantagens:
   - Uso eficiente de memória: os nós são alocados conforme necessário

3) Quando a matiz de adjacência é mais eficiente:
   - Grafos densos: onde o número de arestas é próximo ao número máximo possível 
   (V*(V-1)/2 para grafos não direcionados)
*/