#include "queue.h"

void add_fila_pedido(PedidoFila* fila, Pedido* novo){
    FilaItem* novoItem = malloc(sizeof(novoItem));
    novoItem->valor = novo;
    novoItem->prox = NULL;

    if(fila->inicio == NULL)
        fila->inicio = novoItem;
    else if(fila->inicio->valor->prioridade < novoItem->valor->prioridade) {
        novoItem->prox = fila->inicio;
        fila->inicio = novoItem;
    }
    else {
        FilaItem* aux = fila->inicio;
        while (aux->valor->prioridade < novo->prioridade)
            aux = aux->prox;

        novoItem->prox = aux->prox;
        aux->prox = novoItem;
    }

    fila->len++;
}

Pedido* remove_file_pedido(PedidoFila* fila) {
    FilaItem* lixo = fila->inicio;
    if(lixo->prox != NULL)
        fila->inicio = lixo->prox;

    Pedido* isolated_pedido = lixo->valor;
    free(lixo);
    return isolated_pedido;
}

void imprimir_fila(PedidoFila* fila) {
    FilaItem* aux = fila->inicio;
    for(int i = 0; i < fila->len; i++){
        printf("Responsavel encomenda: %s\n", aux->valor->responsavel_encomenda);
        printf("Nome aluno: %s", aux->valor->info_encomenda->nome_aluno);
            aux = aux->prox;
    }
}