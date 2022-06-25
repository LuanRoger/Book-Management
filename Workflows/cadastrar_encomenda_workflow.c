#include "cadastrar_encomenda_workflow.h"

Encomenda* CadastrarEncomendaWorkflow(int id) {
    printf("\nDigite o nome do aluno:\n");
    char *nome_aluno = malloc(STRING_BUFFER_SIZE);
    scanf(" %[^\n]s", nome_aluno);

    printf("\nDigite a matricula:\n");
    char *matricula = malloc(STRING_BUFFER_SIZE);
    scanf(" %s", matricula);

    printf("\nDigite uma descricao:\n");
    char *descricao = malloc(STRING_BUFFER_SIZE);
    scanf(" %[^\n]s", descricao);

    return CriarEncomenda(id, nome_aluno, matricula, descricao);
}