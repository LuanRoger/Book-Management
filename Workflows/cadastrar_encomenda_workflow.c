#include "cadastrar_encomenda_workflow.h"

//TODO: Tamanho da frase
Encomenda* CadastrarEncomendaWorkflow(int id) {
    printf("Digite o nome do aluno:\n");
    char *nome_aluno = malloc(STRING_BUFFER_SIZE);
    scanf(" %[^\n]s", nome_aluno);

    printf("Digite a matricula:\n");
    char *matricula = malloc(STRING_BUFFER_SIZE);
    scanf(" %s", matricula);

    printf("Digite uma descricao:\n");
    char *descricao = malloc(STRING_BUFFER_SIZE);
    scanf(" %[^\n]s", descricao);

    return CriarEncomenda(id, nome_aluno, matricula, descricao);
}