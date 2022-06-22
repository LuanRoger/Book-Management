#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"

Usuario *criar_usuario(char *nome_usuario, char *cpf, char *senha, int cargo){
    Usuario *newUsuario = malloc(sizeof(Usuario));
    newUsuario->nome = nome_usuario;
    newUsuario->cpf = cpf;
    newUsuario->senha = senha;
    newUsuario->cargo = cargo;

    return newUsuario;
}
