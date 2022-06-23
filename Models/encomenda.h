#ifndef ENCOMENDA_H
#define ENCOMENDA_H

typedef struct Encomenda{
    int id;
    char *nome_aluno;
    char *matricula;
    char *descricao;
}Encomenda;

Encomenda* CriarEncomenda(int id, char *nome_aluno, char *matricula, char *descricao);
void DeletarEncomenda(Encomenda* encomenda);
#endif