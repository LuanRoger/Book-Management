#include "fila_pedido.h"

void AddFilaPedido(FilaPedido* fila, Pedido* pedido){
    FilaItem* novoItem = malloc(sizeof(FilaItem));
    novoItem->valor = pedido;
    novoItem->prox = NULL;

    if(fila->inicio == NULL){
        fila->inicio = novoItem;
        fila->fim = novoItem;
    }
    else if(fila->inicio->valor->prioridade < pedido->prioridade){
        novoItem->prox = fila->inicio;
        fila->inicio = novoItem;
    }
    else if(fila->fim->valor->prioridade > pedido->prioridade){
        fila->fim->prox = novoItem;
        novoItem = fila->fim;
    }
    else {
        FilaItem* aux = fila->inicio;
        while (aux->valor->prioridade < pedido->prioridade)
            aux = aux->prox;

        novoItem->prox = aux->prox;
        aux->prox = novoItem;
    }

    fila->len++;
}
FilaItem* RemoveFilaPedido(FilaPedido* fila) {
    FilaItem* toRemove = fila->inicio;
    if(toRemove->prox != NULL)
        fila->inicio = toRemove->prox;

    return toRemove;
}

Pedido* UnwrapFilaItem(FilaItem* filaItem) {
    Pedido* pedido = filaItem->valor;

    free(filaItem);
    return pedido;
}

void PrintFila(FilaPedido* fila) {
    FilaItem* aux = fila->inicio;
    for(int i = 0; i < fila->len; i++){
        printf("╔════════════════════════════════════════════════════════════╗\n");
        printf(" ID: %d\n", aux->valor->info_encomenda->id);
        printf(" Nome do aluno: %s\n", aux->valor->info_encomenda->nome_aluno);
        printf(" Matricula do aluno: %s\n", aux->valor->info_encomenda->matricula);
        printf(" Descrição: %s\n", aux->valor->info_encomenda->descricao);
        printf(" Campus de saida: %s", aux->valor->campus_livro);
        printf(" Campus de entrada: %s", aux->valor->campus_aluno);
        printf(" Responsável: %s\n", aux->valor->responsavel_encomenda);
        printf(" Prioridade: %d\n", aux->valor->prioridade);
        printf("╚════════════════════════════════════════════════════════════╝\n");
        printf("\n");
        aux = aux->prox;
    }
}