#include "encomenda.h"
#include <stdlib.h>

#ifndef PEDIDO_H
#define PEDIDO_H

typedef struct Pedido {
    Encomenda* info_encomenda;
    char* campus_livro;
    char* campus_aluno;
    char* responsavel_encomenda;
    int prioridade;
}Pedido;

Pedido* CriarPedido(Encomenda* info_encomenda, char* campus_livro, char* campus_aluno, char* responsavel_encomenda, int prioridade);
void DeletePedido(Pedido* pedido);

#endif