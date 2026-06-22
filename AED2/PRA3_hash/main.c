/*
UFU/FACOM/BCC
Disciplina: Algoritmos e Estruturas de Dados II
Ref: Atividade Prática relacionada à Tabela Hash
*/

#include <stdio.h>
#include <stdlib.h>
#include "TabelaHash.h"

#define TABLE_SIZE 10

int main() {
    Hash* ha = criaHash(TABLE_SIZE);

    struct aluno a1 = {123, "João", 7.5, 8.0, 9.0};
    struct aluno a2 = {456, "Maria", 6.0, 7.5, 8.0};
    struct aluno a3 = {789, "Pedro", 8.0, 9.0, 10.0};

    insereHash_SemColisao(ha, a1);
    insereHash_SemColisao(ha, a2);
    insereHash_SemColisao(ha, a3); // Pode causar colisão dependendo do tamanho da tabela

    return 0;
}

/*  
1) O que acontece se duas matrículas produzirem a mesma posição na tabela quando usamos insereHash_SemColisao?
Por que isso é um problema?

    Se ocorrer uma colisão usando essa função,
    o novo aluno será alocado e seu endereço simplesmente sobrescreverá o endereço 
    do aluno anterior na tabela (ha->itens[pos] = novo;).
    Isso é um grande problema porque o dado antigo será perdido na tabela. 

    Além disso, como o ponteiro anterior foi perdido sem usarmos a função free(), 
    ocorrerá um vazamento de memória (memory leak).


2)Em main.c, por que as inserções utilizam insereHash_SemColisao e não a função com endereçamento aberto? 
Em qual cenário a versão "sem colisão" é segura de usar?

    A função insereHash_SemColisao é usada em main.c para demonstrar o que acontece quando ocorre uma colisão. 
    Ela é segura de usar apenas quando temos certeza de que as chaves (matrículas) são únicas e não causarão colisões, 
    ou seja, quando o número de elementos a serem inseridos for menor que o tamanho da tabela e as chaves forem 
    distribuídas de forma a evitar colisões.

    Por exemplo: As palavras destinadas de uma linguagem de programação,
    onde cada palavra tem um código único, poderiam ser armazenadas usando insereHash_SemColisao,


3)A sondagem linear sempre termina em, no máximo, 'TABLE_SIZE' passos. Explique
por que isso é verdadeiro.

    A sondagem linear verifica sequencialmente as posições da tabela 
    usando a fórmula (pos + i) % TABLE_SIZE.  

    Como a variável de tentativa i é incrementada de 1 em 1 em um loop, 
    após iterar uma quantidade exata de vezes igual ao tamanho da tabela (TABLE_SIZE), 
    o algoritmo terá "dado a volta" completa e percorrido todos os índices do array exatamente uma única vez. 
    Se todos estiverem cheios, ele encerra as tentativas.


4)Compare sondagem linear, quadrática e duplo hashing. Qual delas tende a espalhar
melhor os elementos na tabela? Justifique sua resposta.

    Sondagem Linear: Apresenta o problema de AGRUPAMENTO PRIMÁRIO, 
    onde longas sequências de posições ocupadas começam a se formar (clusters),
    e prejudicam o desempenho, busca demorada.

    Sondagem Quadrática: Resolve o agrupamento primário dando "saltos" maiores (i2), 
    mas sofre de AGRUPAMENTO SECUNDÁRIO (chaves que caem na mesma posição inicial 
    vão seguir sempre os mesmos saltos).

    Duplo Hashing: É a que espalha melhor os elementos. 
    Ele usa uma segunda função de hash para definir o tamanho do "salto" durante a colisão. 
    Como esse salto agora depende do valor da chave (e não só da tentativa i), 
    chaves que colidem inicialmente na mesma posição terão rotas de escape diferentes pela tabela, 
    evitando os dois tipos de agrupamentos citados.


5)Por que não podemos simplesmente colocar NULL na posição removida ao usar
endereçamento aberto com sondagem?

    Porque colocar um NULL (espaço vazio) quebraria a corrente de busca 
    para outras chaves que colidiram ali no passado.  

    Imagine o cenário: As chaves A, B e C colidiram na posição 0. 
    A ficou em 0, B em 1 e C em 2. Se você deletar o elemento B colocando NULL na posição 1, 
    na hora em que for buscar a chave C (que tem hash original 0), o algoritmo vai olhar o 
    índice 0 (verá A), depois olhará o índice 1. Ao encontrar o NULL no índice 1, o seu 
    algoritmo vai presumir que a busca acabou e retornará que o C não existe.

    É por isso que marcamos a posição de B com uma "flag" (como DELETED). 
    Isso sinaliza: "Essa posição está livre para inserção, mas para fins de busca, 
    continue procurando adiante".


FINAL)Com base nas estatísticas, qual estratégia de endereçamento aberto apresentou
melhor desempenho (menos colisões médias)? Há diferença significativa entre elas para o conjunto de
dados utilizado?

    O Duplo Hashing deverá apresentar o melhor desempenho nas suas medições 
    (menos colisões médias).

    Sim, há diferença significativa. Especialmente à medida que a tabela vai 
    ficando mais cheia (alto fator de carga), a sondagem linear sofrerá um salto 
    drástico no número de colisões pelo agrupamento em massa, seguida pela quadrática. 
    O duplo hashing se manterá muito mais estável, distribuindo os dados de forma 
    pseudo-aleatória por toda a estrutura.


*/