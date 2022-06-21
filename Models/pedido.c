#include "pedido.h"

Pedido* criar_pedido(Encomenda* info_encomenda,
    char* campus_livro,
    char* campus_aluno,
    char* responsavel_encomenda,
    int prioridade) 
    {
        Pedido* pedido = malloc(sizeof(Pedido));
        pedido->info_encomenda = info_encomenda;
        pedido->campus_livro = campus_livro;
        pedido->campus_aluno = campus_aluno;
        pedido->responsavel_encomenda = responsavel_encomenda;
        pedido->prioridade = prioridade;
    }
void deletar_pedido(Pedido* pedido) {
    free(pedido);
}