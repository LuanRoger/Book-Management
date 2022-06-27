#include "usuario.h"

Usuario *CriarUsuario(char *nome_usuario, char *cpf, char *senha, int cargo){
    Usuario *newUsuario = malloc(sizeof(Usuario));

    newUsuario->nome = malloc(STRING_USER_BUFFER);
    strcpy(newUsuario->nome, nome_usuario);

    newUsuario->cpf = malloc(STRING_USER_BUFFER);
    strcpy(newUsuario->cpf, cpf);

    newUsuario->senha = malloc(STRING_USER_BUFFER);
    strcpy(newUsuario->senha, senha);

    newUsuario->cargo = cargo;

    return newUsuario;
}
void DeleteUsuario(Usuario* usuario) {
    free(usuario->nome);
    free(usuario->cpf);
    free(usuario->senha);
}