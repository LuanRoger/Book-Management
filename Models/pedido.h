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

Pedido* criar_pedido(Encomenda* info_encomenda,
    char* campus_livro,
    char* campus_aluno,
    char* responsavel_encomenda,
    int prioridade);
void deletar_pedido(Pedido* pedido);

#endif