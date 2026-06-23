// Estrutura base da árvore

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição do nó
typedef struct No {
    int dado;
    struct No* esquerda;
    struct No* direita;
} No;
// Função para criar um novo nó
No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}
void libera_NO(struct No* no) {
    if(no == NULL) {
        return;
    }
    libera_NO(no->esquerda);
    libera_NO(no->direita);
    free(no);
    no = NULL;
}
// ------------------ PARTE I -----------------------
void preOrdem(No* raiz) { // Percurso pré-ordem (raiz -> esquerda -> direita)
    if(raiz == NULL) return;
    printf("%d ", raiz->dado);
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
}
void emOrdem(No* raiz) { // Percurso em-ordem (esquerda -> raiz -> direita)
    if(raiz == NULL) return;
    emOrdem(raiz->esquerda);
    printf("%d ", raiz->dado);
    emOrdem(raiz->direita);
}
void posOrdem(No* raiz) {// Percurso pós-ordem (esquerda -> direita -> raiz)  
    if(raiz == NULL) return; 
    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    printf("%d ", raiz->dado);
}

int contarNos(No* raiz) {
    if(raiz == NULL) return 0;
    // O total é 1 (este nó) + nós à esquerda + nós à direita
    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}

int altura(No*raiz) {
    if(raiz == NULL) return -1;
    
    int altEsq = altura(raiz->esquerda);
    int altDir = altura(raiz->direita);

    if(altEsq>altDir) return altEsq + 1;
    else return altDir + 1;
}

// ------------------ PARTE II -----------------------
No* inserirABB(No* raiz, int valor) { // Insere um valor na ABB mantendo a propriedade (sem repetições)
    // COMPLETE AQUI
    if(raiz == NULL) { 
        return criarNo(valor); // Dica: se raiz == NULL, crie um novo nó e retorne
    }
    if(valor < raiz->dado) { // Caso contrário, compare valor com raiz->dado e insira na subárvore adequada
        raiz->esquerda = inserirABB(raiz->esquerda, valor);
    }
    else if(valor > raiz->dado) {
        raiz->direita = inserirABB(raiz->direita, valor);
    }

    return raiz;
}
// Busca otimizada em ABB (aproveita a ordenação)
bool buscarABB(No* raiz, int alvo) {
    // COMPLETE AQUI
    if(raiz == NULL) return false; // Dica: se raiz == NULL, retorne false
    if(alvo == raiz->dado) return true; // Se alvo == raiz->dado, true
    if(alvo < raiz->dado) { // Se alvo < raiz->dado, busque na esquerda, senão na direita
        return buscarABB(raiz->esquerda, alvo); 
    }
    else {
        return buscarABB(raiz->direita, alvo);
    }
}
// Função para liberar toda a memória da árvore (pós-ordem)
void liberarArvore(No* raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}
// ------------------ PARTE III -----------------------
No* menorValor(No* raiz) { // Encontra o nó com o menor valor (mais à esquerda)
    // COMPLETE AQUI
    No* atual = raiz;
    // O menor valor de uma ABB fica o mais à esquerda possível
    while(atual != NULL && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}
// Remove um valor da ABB
No* removerABB(No* raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }
    // Busca o nó a ser removido
    if (valor < raiz->dado) {
        raiz->esquerda = removerABB(raiz->esquerda, valor);
    }
    else if (valor > raiz->dado) {
        raiz->direita = removerABB(raiz->direita, valor);
    }
    else {
    // Nó encontrado!
    // CASO 1: sem filhos ou com um filho
        if (raiz->esquerda == NULL) {
            // COMPLETE AQUI (nó com filho direito ou folha)
            No* temp = raiz ->direita;
            free(raiz);
            return temp;
        }
        else if (raiz->direita == NULL) {
            // COMPLETE AQUI (nó com filho esquerdo)
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        // CASO 2: dois filhos
        // Encontra o menor nó da subárvore direita
        // COMPLETE AQUI
        No* temp = menorValor(raiz->direita);
        raiz->dado = temp->dado;
        raiz->direita = removerABB(raiz->direita, temp->dado);
        
    }
    return raiz;
}
bool checarABB(No* raiz, int min, int max) {
    if (raiz == NULL) return true;
    // Se quebrar a regra de limites da ABB, retorna falso
    if (raiz->dado <= min || raiz->dado >= max) return false;
    // Verifica subárvores estreitando os limites
    return checarABB(raiz->esquerda, min, raiz->dado) && checarABB(raiz->direita, raiz->dado, max);
}
// Na main a chamada seria: checarABB(raiz, -999999, 999999);
// -------------- Main para parte I -------------------
/* 
int main() {
// Construindo uma árvore manualmente:
//       10
//       / \
//      5   15
//     / \   \
//    3   7   20

    No* raiz = criarNo(10);

    raiz->esquerda = criarNo(5);
    raiz->direita = criarNo(15);

    raiz->esquerda->esquerda = criarNo(3);
    raiz->esquerda->direita = criarNo(7);
    raiz->direita->direita = criarNo(20);

    printf("Pre-ordem: ");
    preOrdem(raiz);
    // Deveria: 10 5 3 7 15 20

    printf("\n");
    printf("Em-ordem: ");
    emOrdem(raiz);
    // Deveria: 3 5 7 10 15 20

    printf("\n");
    printf("Pos-ordem: ");
    posOrdem(raiz);
    // Deveria: 3 7 5 20 15 10

    printf("\n");
    printf("Total de nos: %d\n", contarNos(raiz));
    // 6

    printf("Altura: %d\n", altura(raiz));
    // 3 (caminho 10-15-20)

    inserirABB(raiz, 30);
    // Deveria: Pre-ordem: 10 5 3 7 15 20 30, Em-ordem: 3 5 7 10 20 15 30, Pos-ordem: 3 7 5 20 30 15 10
    printf("---- Depois da inserção ----\n");

    printf("Pre-ordem: ");
    preOrdem(raiz);
    // Deveria: 10 5 3 7 15 20 30

    printf("\n");
    printf("Em-ordem: ");
    emOrdem(raiz);
    // Deveria: 3 5 7 10 20 15 30

    printf("\n");
    printf("Pos-ordem: ");
    posOrdem(raiz);
    // Deveria: 3 7 5 20 30 15 10

    return 0;
}
*/
// -------------- Main para parte II -------------------
/*
int main() {
    No* raizABB = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 35, 45};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++) {
        raizABB = inserirABB(raizABB, valores[i]);
    }
    // Construindo uma árvore manualmente:
//          50
//         /   \
//       30      70
//      /  \     / \
//    20   40   60  80
//         / \
//       35   45
    
    printf("Em-ordem da ABB: ");
    emOrdem(raizABB);
    // Deve imprimir em ordem crescente
    printf("\n");

    printf("Buscar 45: %s\n", buscarABB(raizABB, 45) ? "Sim" : "Nao");
    printf("Buscar 100: %s\n", buscarABB(raizABB, 100) ? "Sim" : "Nao");
    
    liberarArvore(raizABB);

    return 0;
}
*/
// -------------- Main para parte III -------------------

int main() {
    No* raiz = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 35, 45};
    for (int i = 0; i < 9; i++) raiz = inserirABB(raiz, valores[i]);

    printf("ABB original (em-ordem): ");
    emOrdem(raiz);
    printf("\n");

    // Remover folha (20)
    raiz = removerABB(raiz, 20);
    printf("Apos remover 20: ");
    emOrdem(raiz);
    printf("\n");

    // Remover nó com um filho (30 tem filho 40)
    raiz = removerABB(raiz, 30);
    printf("Apos remover 30: ");
    emOrdem(raiz);
    printf("\n");

    // Remover nó com dois filhos (50)
    raiz = removerABB(raiz, 50);
    printf("Apos remover 50: ");
    emOrdem(raiz);
    printf("\n");
    
    liberarArvore(raiz); return 0;
}