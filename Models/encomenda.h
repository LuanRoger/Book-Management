#ifndef ENCOMENDA_H
#define ENCOMENDA_H
#include "../Generators/id_generator.h"

typedef struct Encomenda{
    int id;
    char *nome_aluno;
    char *matricula;
    char *descricao;
    struct Encomenda *right;
    struct Encomenda *left;
}Encomenda;

void criarEncomenda(char *nome_aluno, char *matricula, char *descricao);
Encomenda *search(int id, Encomenda* aux);
Encomenda *removal(int id, Encomenda *aux);
void in_ordem(Encomenda *aux);
#endif