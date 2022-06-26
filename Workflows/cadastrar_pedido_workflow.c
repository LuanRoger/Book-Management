#include "cadastrar_pedido_workflow.h"

Pedido* CadastrarPedidoWorkflow(BSTEncomendas* bst, Usuario* user) {
    if(bst->root == NULL) {
        printf("NENHUMA ENCOMENDA CADASTRADA.\n");
        return NULL;
    }

    int encomendaId;
    printf("Digite o ID da encomenda:\n");
    scanf("%d%*c", &encomendaId);

    BSTEncomendaNode* encomendaNode = RemoveNode(bst, encomendaId);
    Encomenda* encomenda = NULL;
    if(encomendaNode == NULL) return NULL;
    encomenda = UnwrapBSTNode(encomendaNode);

    char* campus_livro = malloc(BUFFER_STRING_SIZE);
    char* campus_aluno = malloc(BUFFER_STRING_SIZE);
    char* responsavel_encomenda = malloc(BUFFER_STRING_SIZE);
    int prioridade;

    printf("\nDigite o campus do livro:\n");
    scanf(" %[^\n]s", campus_livro);
    
    printf("\nDigite o campus do aluno:\n");
    scanf(" %[^\n]s", campus_aluno);

    do {
        printf("\nDigite a prioridade (0 ~ 100):\n");
        scanf("%d%*c", &prioridade);

        if(prioridade < 0 || prioridade > 100)
            printf("\nPRIORIDADE FORA DOS LIMITES\n");
        else break;
        
    }while(1);

    return CriarPedido(encomenda, campus_livro, campus_aluno, user->nome, prioridade);
}