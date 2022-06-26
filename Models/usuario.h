#include <stdio.h>
#include <stdlib.h>

#ifndef USUARIO_H
#define USUARIO_H

typedef struct Usuario{
    char *nome;
    char *cpf;
    char *senha;
    int cargo;
} Usuario;

Usuario *CriarUsuario(char *nome_usuario, char *cpf, char *senha, int cargo);
void DeleteUsuario(Usuario* usuario);

#endif
