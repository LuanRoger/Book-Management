#ifndef USUARIO_H
#define USUARIO_H

typedef struct Usuario{
    char *nome;
    char *cpf;
    char *senha;
    int cargo;
} Usuario;

Usuario *criar_usuario(char *nome_usuario, char *cpf, char *senha, int cargo);

#endif
