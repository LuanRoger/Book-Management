#include "cadastrar_pedido_workflow.h"

Pedido* CadastrarPedidoWorkflow(BSTEncomendas* bst, Usuario* user) {
    int encomendaId;

    printf("Digite o ID da encomenda:\n");
    scanf("%d%*c", &encomendaId);

    BSTEncomendaNode* encomenda = RemoveNode(bst, encomendaId);
    if(encomenda == NULL) return NULL;

    char* campus_livro = malloc(BUFFER_STRING_SIZE);
    char* campus_aluno = malloc(BUFFER_STRING_SIZE);
    char* responsavel_encomenda = malloc(BUFFER_STRING_SIZE);
    int prioridade;

    printf("Digite o campus do livro:\n");
    fgets(campus_livro, BUFFER_STRING_SIZE, stdin);
    
    printf("Digite o campus do aluno:\n");
    fgets(campus_aluno, BUFFER_STRING_SIZE, stdin);

    do{
        printf("Digite a prioridade (0 ~ 100):\n");
        scanf("%d%*c", &prioridade);
        if(prioridade < 0 || prioridade > 100){
            printf("\nPRIORIDADE FORA DOS LIMITES\n");

        }else{
            break;
        }
        
    }while(1);

    return CriarPedido(encomenda->valor, campus_livro, campus_aluno, user->nome, prioridade);
}