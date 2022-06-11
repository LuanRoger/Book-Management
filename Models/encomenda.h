#ifndef ENCOMENDA_H
#define ENCOMENDA_H

typedef struct Encomenda{
    int id;
    char *nome_aluno;
    char *matricula;
    char *descricao;
    struct Encomenda *right;
    struct Encomenda *left;
}Encomenda;

void criarEncomenda(int id, char *nome_aluno, char *matricula, char *descricao);
#endif