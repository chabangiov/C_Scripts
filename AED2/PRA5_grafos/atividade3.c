// BFS - Breadth First Search (Busca em Largura)

#include <stdio.h>
#include <stdlib.h>
#include "atividade1.c"

void BFS(Grafo *g,int origem){
    int fila[100];
    int inicio = 0;
    int fim = 0;
    int visitado[100]={0};
    fila[fim++] = origem;
    visitado[origem] = 1;

    while(inicio < fim){
        int v = fila[inicio++];
        printf("%d ",v);
        No *aux = ;

        while(aux){
            if(!visitado[aux->destino ]){
                visitado[aux->destino ] = 1;
                __________________;
            }
        aux = aux->prox;
        }
    }   
}

/*
1) Qual estrutura é essencial?
    - A fila é a estrutura essencial para a BFS, pois ela garante que os vértices sejam processados na ordem em que foram descobertos.

2) A BFS encontra o menor caminho em grafos sem peso?
    - Sim, a BFS garante encontrar o menor caminho em grafos sem peso, pois ela explora todos os vértices de um nível antes de passar para o próximo nível.

3) Compare DFS e BFS:
    - DFS é mais adequada para explorar profundamente um grafo, enquanto BFS é melhor para encontrar o caminho mais curto em grafos sem peso. DFS pode ser implementada usando recursão ou uma pilha, enquanto BFS utiliza uma fila.

*/