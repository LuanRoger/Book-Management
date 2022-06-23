#include "user_verification.h"



int verification(ListaUsuario* list){
    ItemListUsuario* aux = list->inicio;
    char cpf[20];
    char senha[10];
    int cargo;


    printf("LOGIN: ");
    scanf(" %s", cpf);

    printf("SENHA: ");
    scanf(" %s", senha);

    for(int i = 0; i < list->len; i++){
        
        if((strcmp(aux->valor->cpf, cpf) == 0) && (strcmp(aux->valor->senha, senha) == 0)){
            
            return 1;
        }
        aux = aux->prox;   
    }

    return 0;
}

int verification_t(ListaUsuario* list){
    ItemListUsuario* aux = list->inicio;
    char cpf[20];
    char senha[10];
    int cargo;


    printf("LOGIN: ");
    scanf(" %s", cpf);

    printf("SENHA: ");
    scanf(" %s", senha);

    for(int i = 0; i < list->len; i++){
        
        if((strcmp(aux->valor->cpf, cpf) == 0) && (strcmp(aux->valor->senha, senha) == 0) && aux->valor->cargo == 2){
            return 1;
        }   
        aux = aux->prox;
    }

    return 0;
}