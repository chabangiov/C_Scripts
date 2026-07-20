// Ordenação Topológica

void topoDFS(Grafo *g,int v,int visitado[],int pilha[],int *topo){
    visitado[v] = 1;
    No *aux = g->lista[v];

    while(aux){
        if(!visitado[aux->destino]){
        topoDFS(g, aux->destino, );
        }
        aux = aux->prox;
    }
    pilha[(*topo)++] = ____________________;
}