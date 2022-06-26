#include "../Structures/lista_usuario.h"
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef VERIFICATION_H
#define VERIFICATION_H
#define CARGO_SECRETARIO 1
#define CARGO_TRANSPORTADOR 2

typedef struct pessoa{
    char nome[50];
    char login[20];
    char senha[20];
    char cargo[3];

}Pessoa;

Usuario* VerificationPassword(ListaUsuario* list);
int VerificationCargo(Usuario* user, int cargo);
void Verify(ListaUsuario* list, int choice_cargo);
#endif