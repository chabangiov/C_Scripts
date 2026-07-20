typedef struct No{
    int destino;
    int peso;
struct No *prox;
}No;
typedef struct{
    int V;
    No **lista;
}Grafo;