#include "list.h"

void add_encomenda(ListaEncomenda* list, int pos, int id, char* nome_aluno, char* matricula, char* descricao){
    if(pos < 0 && pos > list->len) return;

    Encomenda* nova_encomenda = malloc(sizeof(Encomenda));
    nova_encomenda->nome_aluno = nome_aluno;
    nova_encomenda->matricula = matricula;
    nova_encomenda->descricao = descricao;

    ItemListEncomenda* new_item = malloc(sizeof(ItemListEncomenda));
    new_item->valor = nova_encomenda;
    new_item->prox = NULL;
    new_item->ant = NULL;
    
    if(list->inicio == NULL){ //lista vazia
        list->inicio = new_item;
        list->fim = new_item;
    }else if(pos == 0){ //inicio
        new_item->ant = new_item;
        new_item->prox = list->inicio;
        list->inicio = new_item;
    }else if(pos == list->len){ //fim
        new_item->ant = list->fim;
        list->fim->prox = new_item;
        list->fim = new_item;
    }else{ // "no meio"
        ItemListEncomenda* aux = list->inicio;
        for(int i = 0; i < pos; i++)
            aux = aux->prox;

        new_item->prox = aux;
        new_item->ant->prox = new_item;
        new_item->ant = aux->ant;
        aux->ant = new_item;
    }

    list->len++;
}

void imprimir(ListaEncomenda* list){
    ItemListEncomenda* aux = list->inicio;
    for(int i = 0; i < list->len; i++){
        printf("Cod prod: %s\n", aux->valor->nome_aluno);
            aux = aux->prox;
    }
}