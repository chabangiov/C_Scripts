#include <stdio.h>
#include <stdlib.h>
#include "TabelaHash.h" // inclui os Protótipos

struct hash{
    int qtd; // qtd: quantos elementos já guardamos lá dentro
    int TABLE_SIZE; // TABLE_SIZE: tamanho máximo do nosso array
    struct aluno **itens; // cada caixinha guarda o endereço da memória de um 'struct aluno'
};

/*
A tabela é criada por:
Hash* criaHash(int TABLE_SIZE)

e destruída por:
void liberaHash(Hash* ha);
*/
Hash* criaHash(int TABLE_SIZE){
    Hash* ha = (Hash*) malloc(sizeof(Hash));
    if(ha != NULL){
        int i;
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (struct aluno**) malloc(TABLE_SIZE * sizeof(struct aluno*));
        if(ha->itens == NULL){
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        for(i=0; i<TABLE_SIZE; i++)
            ha->itens[i] = NULL;
    }
    return ha;
}
void liberaHash(Hash* ha){
    if(ha != NULL){
        for(int i=0; i < ha->TABLE_SIZE; i++){
            if(ha->itens[i] != NULL){
                free(ha->itens[i]);
            }
        }
        free(ha->itens);
        free(ha);
    }
}

// Função de hash usando o método da divisão
int chaveDivisao(int chave, int TABLE_SIZE){
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

void insereHash_SemColisao (Hash* ha, struct aluno al){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return;
    int chave = al.matricula; // a chave é a matrícula do aluno
    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    if(ha->itens[pos] != NULL)
        return; // posição já ocupada, não insere
    struct aluno* novo = (struct aluno*) malloc(sizeof(struct aluno));
    if(novo == NULL)
        return; // falha na alocação
    *novo = al; // copia os dados do aluno para a nova estrutura
    ha->itens[pos] = novo; // armazena o endereço do novo aluno na tabela
    ha->qtd++; // incrementa a quantidade de elementos na tabela
}

void insereHash_EnderAberto (Hash* ha, struct aluno al){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return;
    int chave = al.matricula; // a chave é a matrícula do aluno
    int pos = chaveDivisao(chave, ha->TABLE_SIZE);
    int i = 0;
    while(ha->itens[pos] != NULL){
        if(ha->itens[pos]->matricula == chave)
            return; // aluno já existe, não insere
        i++;
        pos = (chaveDivisao(chave, ha->TABLE_SIZE) + i) % ha->TABLE_SIZE; // sondagem linear
    }
    struct aluno* novo = (struct aluno*) malloc(sizeof(struct aluno));
    if(novo == NULL)
        return; // falha na alocação
    *novo = al; // copia os dados do aluno para a nova estrutura
    ha->itens[pos] = novo; // armazena o endereço do novo aluno na tabela
    ha->qtd++; // incrementa a quantidade de elementos na tabela
}

void buscaHash_SemColisao (Hash* ha, int matricula){
    if(ha == NULL)
        return;
    int pos = chaveDivisao(matricula, ha->TABLE_SIZE);
    if(ha->itens[pos] != NULL && ha->itens[pos]->matricula == matricula){
        printf("Aluno encontrado: %s\n", ha->itens[pos]->nome);
    } else {
        printf("Aluno não encontrado.\n");
    }
}

void buscaHash_EnderAberto (Hash* ha, int matricula){
    if(ha == NULL)
        return;
    int pos = chaveDivisao(matricula, ha->TABLE_SIZE);
    int i = 0;
    while(ha->itens[pos] != NULL){
        if(ha->itens[pos]->matricula == matricula){
            printf("Aluno encontrado: %s\n", ha->itens[pos]->nome);
            return;
        }
        i++;
        pos = (chaveDivisao(matricula, ha->TABLE_SIZE) + i) % ha->TABLE_SIZE; // sondagem linear
    }
    printf("Aluno não encontrado.\n");
}

#define DELETED ((struct aluno*) -1)
int removeHash_EnderAberto(Hash* ha, int mat) {
    if (ha == NULL)
        return 0;
    int pos = chaveDivisao(mat, ha->TABLE_SIZE);
    int i = 0;
    while (ha->itens[pos] != NULL) {
        if (ha->itens[pos] != DELETED && ha->itens[pos]->matricula == mat) {
            free(ha->itens[pos]);
            ha->itens[pos] = DELETED; // marca como deletado
            ha->qtd--;
            return 1; // sucesso
        }
        i++;
        pos = (chaveDivisao(mat, ha->TABLE_SIZE) + i) % ha->TABLE_SIZE; // sondagem linear
    }
    return 0; // não encontrado
}

/* 
int sondagemLinear(int pos, int i, int TABLE_SIZE);
int sondagemQuadratica(int pos, int i, int TABLE_SIZE);
int duploHash(int H1, int chave, int i, int TABLE_SIZE);
*/

// Na inserção com endereçamento aberto ('insereHash_EnderAberto') a posição é recalculada, por exemplo, com sondagem linear:
// newPos = sondagemLinear(pos,i,ha->TABLE_SIZE);
