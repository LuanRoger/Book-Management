#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "encomenda.h"
#include "../Generators/id_generator.h"

Encomenda* criar_encomenda(char *nome_aluno, char *matricula, char *descricao) {
    Encomenda* newEncomenda = malloc(sizeof(Encomenda));
    newEncomenda->nome_aluno = nome_aluno;
    newEncomenda->matricula = matricula;
    newEncomenda->descricao = descricao;

    return newEncomenda;
}
void deletar_encomenda(Encomenda* encomenda) {
    free(encomenda);
}