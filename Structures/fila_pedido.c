#include "fila_pedido.h"

void AddFilaPedido(FilaPedido* fila, Pedido* pedido){
    FilaItem* newPedido = malloc(sizeof(FilaItem));
    newPedido->valor = pedido;
    newPedido->prox = NULL;
    newPedido->ant = NULL;

    if(fila->inicio == NULL)
        fila->inicio = newPedido;
    else if(pedido->prioridade > fila->inicio->valor->prioridade) {
        fila->inicio->ant = newPedido;
        newPedido->prox = fila->inicio;

        fila->inicio = newPedido;
    }
    else {
        FilaItem* aux = fila->inicio;
        while (aux->prox != NULL && pedido->prioridade <= aux->prox->valor->prioridade)
            aux = aux->prox;
        
        newPedido->prox = aux->prox;
        newPedido->ant = aux;
        
        if(aux->prox != NULL)
        aux->prox->ant = newPedido;

        aux->prox = newPedido;
        
    }

    fila->len++;
}
FilaItem* RemoveFilaPedido(FilaPedido* fila) {
    FilaItem* toRemove = fila->inicio;
    if(toRemove->prox != NULL) {
        fila->inicio = toRemove->prox;
        fila->inicio->ant = NULL;
    }

    fila->len--;
    return toRemove;
}

Pedido* UnwrapFilaItem(FilaItem* filaItem) {
    Pedido* pedido = filaItem->valor;

    free(filaItem);
    return pedido;
}

void PrintFila(FilaPedido* fila) {
    if(fila->inicio == NULL) return;

    FilaItem* aux = fila->inicio;
    for(int i = 0; i < fila->len; i++){
        PrintPedidoFilaItem(aux);
        aux = aux->prox;
    }
}
void PrintPedidoFilaItem(FilaItem* filaItem) {
    Pedido* itemValor = filaItem->valor;

    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf(" ID: %d\n", itemValor->info_encomenda->id);
    printf(" Nome do aluno: %s\n", itemValor->info_encomenda->nome_aluno);
    printf(" Matricula do aluno: %s\n", itemValor->info_encomenda->matricula);
    printf(" Descrição: %s\n", itemValor->info_encomenda->descricao);
    printf(" Campus de saida: %s\n", itemValor->campus_livro);
    printf(" Campus de entrada: %s\n", itemValor->campus_aluno);
    printf(" Responsável: %s\n", itemValor->responsavel_encomenda);
    printf(" Prioridade: %d\n", itemValor->prioridade);
    printf("╚════════════════════════════════════════════════════════════╝\n");
    printf("\n");
}