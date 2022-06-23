#include "../Models/pedido.h"
#include "../Models/encomenda.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef QUEUE_PEDIDO_H
#define QUEUE_PEDIDO_H
typedef struct FilaItem{
    Pedido* valor;
    
    struct FilaItem* prox;
}FilaItem;
typedef struct filaPedido{
    FilaItem* inicio;
    FilaItem* fim;
    int len;
}filaPedido;

void add_fila_pedido(filaPedido* fila, Pedido* pedido);
Pedido* remove_file_pedido(filaPedido* fila);
void imprimir_fila(filaPedido* fila);
#endif