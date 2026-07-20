#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

// Função auxiliar para visualizar a lista de adjacência (Opção 2)
void mostrarGrafo(Grafo *g) {
    if (g == NULL) {
        printf("Erro: Nenhum grafo carregado na memoria!\n");
        return;
    }
    
    printf("\n=== LISTA DE ADJACENCIA ===\n");
    for (int i = 0; i < g->V; i++) {
        printf("Vertice %d: ", i);
        No *atual = g->lista[i];
        while (atual != NULL) {
            printf("-> (Dest %d, Peso %d) ", atual->destino, atual->peso);
            atual = atual->prox;
        }
        printf("\n");
    }
    printf("===========================\n");
}

int main() {
    Grafo *meuGrafo = NULL; // Inicializa o ponteiro do grafo vazio
    int opcao;
    char nomeArquivo[50];

    do {
        printf("\n=== SISTEMA DE GRAFOS ===\n");
        printf("1. Carregar grafo de arquivo\n");
        printf("2. Mostrar grafo (lista de adjacencia)\n");
        printf("9. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o nome do arquivo (ex: grafo1.txt): ");
                scanf("%s", nomeArquivo);
                
                meuGrafo = carregarGrafo(nomeArquivo);
                
                if (meuGrafo != NULL) {
                    printf("Sucesso: Grafo carregado!\n");
                }
                break;
                
            case 2:
                mostrarGrafo(meuGrafo);
                break;
                
            case 9:
                printf("Encerrando o sistema...\n");
                break;
                
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 9);

    return 0;
}