#include "user_verification.h"
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>


int verification(){
    
    Pessoa Pessoas[10];
    char login[20];
    char senha[10];

    strcpy(Pessoas[0].nome, "VINICIUS DE OLIVEIRA COSTA");
    strcpy(Pessoas[0].login, "vinicius");
    strcpy(Pessoas[0].senha, "1234");
    strcpy(Pessoas[0].cargo, "ST");
    
    strcpy(Pessoas[1].nome, "LUAN ROGER DOS SANTOS CLEMENTINO");
    strcpy(Pessoas[1].login, "roger");
    strcpy(Pessoas[1].senha, "1234");
    strcpy(Pessoas[1].cargo, "TD");


    printf("LOGIN: ");
    scanf(" %s", login);

    printf("SENHA: ");
    scanf(" %s", senha);

    for(int i = 0; i < 10; i++){
        
        if((strcmp(login, Pessoas[i].login) == 0) && (strcmp(senha, Pessoas[i].senha) == 0)){
            return 1;
        }   
    }

    return 0;
}