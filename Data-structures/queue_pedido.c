#include "queue_pedido.h"

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

Pedido* RemoveFilaPedido(FilaPedido* fila) {
    FilaItem* lixo = fila->inicio;
    if(lixo->prox != NULL)
        fila->inicio = lixo->prox;

    Pedido* isolated_pedido = lixo->valor;
    free(lixo);
    return isolated_pedido;
}

void PrintFila(FilaPedido* fila) {
    FilaItem* aux = fila->inicio;
    for(int i = 0; i < fila->len; i++){
        printf("ID: %d\n", aux->valor->info_encomenda->id);
        printf("Nome do aluno: %s\n", aux->valor->info_encomenda->nome_aluno);
        printf("Matricula do aluno: %s\n", aux->valor->info_encomenda->matricula);
        printf("Descricao %s\n", aux->valor->info_encomenda->descricao);
        printf("CAMPUS DE SAIDA: %s\n", aux->valor->campus_livro);
        printf("CAMPUS DE ENTRADA: %s\n", aux->valor->campus_aluno);
        printf("Responsavel encomenda: %s\n", aux->valor->responsavel_encomenda);
        printf("Prioridade: %d\n", aux->valor->prioridade);
        printf("\n");
        aux = aux->prox;
    }
}