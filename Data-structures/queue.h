#include "../Models/pedido.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef QUEUE_H
#define QUEUE_H
typedef struct FilaItem{
    Pedido* valor;
    
    struct FilaItem* prox;
}FilaItem;
typedef struct PedidoFila{
    FilaItem* inicio;
    int len;
}PedidoFila;

void add_fila_pedido(PedidoFila* fila, Pedido* pedido);
Pedido* remove_file_pedido(PedidoFila* fila);
void imprimir_fila(PedidoFila* fila);
#endif