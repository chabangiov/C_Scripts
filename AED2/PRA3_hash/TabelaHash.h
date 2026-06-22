#ifndef TABELAHASH_H
#define TABELAHASH_H

struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct hash Hash;

Hash* criaHash(int TABLE_SIZE);

void liberaHash(Hash* ha);

void insereHash_SemColisao (Hash* ha, struct aluno al);

void insereHash_EnderAberto (Hash* ha, struct aluno al);

void buscaHash_SemColisao (Hash* ha, int matricula);

void buscaHash_EnderAberto (Hash* ha, int matricula);

int removeHash_EnderAberto(Hash* ha, int mat);


#endif // TABELAHASH_H