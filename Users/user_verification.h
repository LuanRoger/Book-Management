#ifndef VERIFICATION_H
#define VERIFICATION_H

#include <stdbool.h>


typedef struct pessoa{
    char nome[50];
    char login[20];
    char senha[20];
    char cargo[3];

}Pessoa;

int verification();

#endif