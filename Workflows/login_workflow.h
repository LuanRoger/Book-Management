#include "../Models/usuario.h"
#include "../Users/user_verification.h"
#include "../Structures/lista_usuario.h"

#ifndef LOGIN_WORKFLOW_H
#define LOGIN_WORKFLOW_H

Usuario* CheckUserCredentialsWorkflow(ListaUsuario* listaUsers, int cargoId);

#endif