#ifndef ENCOMENDA_H
#define ENCOMENDA_H

typedef struct Encomenda{
    int id;
    char *nome_aluno;
    char *matricula;
    char *descricao;
}Encomenda;

Encomenda* criar_encomenda(int id, char *nome_aluno, char *matricula, char *descricao);
void deletar_encomenda(Encomenda* encomenda);
#endif