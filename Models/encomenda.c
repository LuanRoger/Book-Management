#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "encomenda.h"

Encomenda* CriarEncomenda(int id, char *nome_aluno, char *matricula, char *descricao) {
    Encomenda* newEncomenda = malloc(sizeof(Encomenda));
    newEncomenda->id = id;
    newEncomenda->nome_aluno = nome_aluno;
    newEncomenda->matricula = matricula;
    newEncomenda->descricao = descricao;

    return newEncomenda;
}
void DeletarEncomenda(Encomenda* encomenda) {
    free(encomenda->nome_aluno);
    free(encomenda->matricula);
    free(encomenda->descricao);
    free(encomenda);
}