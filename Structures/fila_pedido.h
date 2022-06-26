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
typedef struct FilaPedido{
    FilaItem* inicio;
    FilaItem* fim;
    int len;
}FilaPedido;

void AddFilaPedido(FilaPedido* fila, Pedido* pedido);
FilaItem* RemoveFilaPedido(FilaPedido* fila);

Pedido* UnwrapFilaItem(FilaItem* filaItem);

void PrintFila(FilaPedido* fila);
#endif