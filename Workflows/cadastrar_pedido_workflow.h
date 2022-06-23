#include <stdio.h>
#include "../Data-structures/bst_encomenda.h"
#include "../Models/pedido.h"

#ifndef CADASTRAR_PEDIDO_WORKFLOW_H
#define CADASTRAR_PEDIDO_WORKFLOW_H

//TODO: Criar um arquivo com as constantes
#define BUFFER_STRING_SIZE 256*sizeof(char)

Pedido* CadastrarPedidoWorkflow(BSTEncomendas* bst);

#endif