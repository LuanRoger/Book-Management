#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../Data-structures/list.h"
#ifndef VERIFICATION_H
#define VERIFICATION_H

typedef struct pessoa{
    char nome[50];
    char login[20];
    char senha[20];
    char cargo[3];

}Pessoa;

int verification_s(ListaUsuario* list);
int verification_t(ListaUsuario* list);

#endif