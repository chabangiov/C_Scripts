#include <stdio.h>
#include <stdlib.h>
#include "atividade1.c"

// DFS - Depth First Search (Busca em Profundidade)
void DFS(Grafo *g, int vertice, int *visitado){

    visitado[vertice] = 1;
    printf("%d ", vertice);

    No *aux = g->lista[vertice];

    while(aux != NULL){
        if(!visitado[aux->destino]){
            DFS(g, aux->destino, visitado);
        }
        aux = aux->prox;
    }
}

int main(){
    int V = 5;
    Grafo g;
    g.V = V;
    g.lista = (No**)malloc(V * sizeof(No*));
    for(int i = 0; i < V; i++){
        g.lista[i] = NULL;
    }

    // Adicionando arestas
    adicionarAresta(&g, 0, 1, 1);
    adicionarAresta(&g, 0, 2, 1);
    adicionarAresta(&g, 1, 3, 1);
    adicionarAresta(&g, 2, 3, 1);
    adicionarAresta(&g, 3, 4, 1);

    int visitado[V];
    for(int i = 0; i < V; i++){
        visitado[i] = 0;
    }

    printf("DFS a partir do vértice 0: ");
    DFS(&g, 0, visitado);
    printf("\n");

    return 0;
}

/*
1) Qual é a estrutura implícita? 
    - A pilha é a estrutura implícita utilizada pela DFS.

2) A DFS encontra sempre o menor caminho? 
    - NÃO, a Busca em Profundidade busca um valor por caminhos que podem
    não ser os mais curtos.

3) Duas aplicações para DFS:
   - Detecção de ciclos em um grafo.
   - Ordenação topológica de um grafo acíclico dirigido.
*/
