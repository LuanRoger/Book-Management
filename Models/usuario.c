#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"

Usuario *CriarUsuario(char *nome_usuario, char *cpf, char *senha, int cargo){
    Usuario *newUsuario = malloc(sizeof(Usuario));
    newUsuario->nome = nome_usuario;
    newUsuario->cpf = cpf;
    newUsuario->senha = senha;
    newUsuario->cargo = cargo;

    return newUsuario;
}
void DeleteUsuario(Usuario* usuario) {
    free(usuario->nome);
    free(usuario->cpf);
    free(usuario->senha);
}