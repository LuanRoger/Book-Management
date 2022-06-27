#include "remover_pedido_workflow.h"

int RemoverPedidoWorkflow(FilaPedido* fila) {
    if(fila->inicio == NULL) {
        printf("NÃO HÁ PEDIDOS CADASTRADOS.\n");
        return 0;
    }

    unsigned char confirmationKey = 0x73;

    printf("Você vai remover: \n");
    PrintPedidoFilaItem(fila->inicio);
    printf("Deseja continuar? [s/n]:\n");
    char key;
    scanf(" %c", &key);

    return (unsigned char)key == confirmationKey ? 1 : 0;
}