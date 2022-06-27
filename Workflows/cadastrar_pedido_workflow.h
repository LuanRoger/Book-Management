#include "../Structures/bst_encomenda.h"
#include "../Models/pedido.h"
#include "../Models/usuario.h"
#include <stdio.h>

#ifndef CADASTRAR_PEDIDO_WORKFLOW_H
#define CADASTRAR_PEDIDO_WORKFLOW_H

#define BUFFER_STRING_SIZE 256*sizeof(char)

Pedido* CadastrarPedidoWorkflow(BSTEncomendas* bst, Usuario* user);

#endif