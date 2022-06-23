#include "user_verification.h"

Usuario* VerificationPassword(ListaUsuario* list){
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
            return aux->valor;
    
        }
        aux = aux->prox;   
    }
        
    return NULL;

}


int VerificationCargo(Usuario* user, int cargo){return user->cargo == cargo ? 0 : 1;}


void Verify(ListaUsuario* list, int choice_cargo){
    Usuario* usuario = VerificationPassword(list);

    if(usuario == NULL){
        printf("SENHA E/OU USUARIO INCORRETA\n");
        return;
    }

    int cargo = VerificationCargo(usuario, choice_cargo);

    if(cargo == 1){
        printf("CARGO SEM PERMISSÃO EXIGIDA\n");
    }
}