#include "lista_usuario.h"

void AddListUsuario(ListaUsuario* list, Usuario* usuario){

    ItemListUsuario* novoItem = malloc(sizeof(ItemListUsuario));
    novoItem->valor = usuario;
    
    novoItem->prox = NULL;
    
    
    if(list->inicio == NULL){ //lista vazia
        list->inicio = novoItem;

    }else if(list->len > 0){ //inicio
        novoItem->prox = list->inicio;
        list->inicio = novoItem;
    }

    list->len++;
}

void ImprimirLista(ListaUsuario* list){
    ItemListUsuario* aux = list->inicio;
    for(int i = 0; i < list->len; i++){
        printf("Nome: %s\n", aux->valor->nome);
        printf("CPF: %s\n", aux->valor->cpf);
        if(aux->valor->cargo == 1){
            printf("Cargo: Secretario(a)\n");
        }else{
            printf("Cargo: Transportador(a)\n");
        }
        aux = aux->prox;
    }
}