#ifndef GRAFO_H
#define GRAFO_H

typedef struct No {
    int destino;
    int peso;
    struct No *prox;
} No;

typedef struct {
    int V;           // Número de vértices
    int A;           // Número de arestas
    No **lista;      // Lista de adjacência
} Grafo;

Grafo* carregarGrafo(char *nomeArquivo);
void adicionarAresta(Grafo *g, int origem, int destino, int peso);


#endif