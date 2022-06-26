#include "login_workflow.h"

Usuario* CheckUserCredentialsWorkflow(ListaUsuario* listaUsers, int cargoId) {
    switch (cargoId)
    {
    case 1:
        printf("AVISO: SOMENTE SECRETÁRIOS TEM ACESSO.\n");
        break;
    case 2:
        printf("AVISO: SOMENTE TRANSPORTADORES TEM ACESSO.\n");
        break;
    
    default:
        printf("CARGO NÃO RECONHECIDO.\n");
        return 0;
    }
        
    Usuario* user = VerificationPassword(listaUsers);
    if(user == NULL) {
        printf("\nSENHA E/OU USUARIO INCORRETO!\n");
        return NULL;
    }
    if(VerificationCargo(user, cargoId) != 0) {
        printf("\nUSUARIO SEM PERMISSÃO\n");
        return NULL;
    }
    
    return user;
}