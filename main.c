#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Models/encomenda.h"


int main(){
    extern Encomenda *root;

    int resp = -1;
    while(resp != 0){
        system("clear");
        printf("\nBOOK MANAGEMENT\n");
        printf("[1] - Encomendar um livro.\n");
        printf("[2] - Remover uma encomenda de livro.\n");
        printf("[3] - Remover um pedido de livro.\n");
        printf("[0] - Sair do sistema!\n");
        printf("\nDigite a funcionalidade desejada: ");
        scanf("%d", &resp);

        if(resp == 1){

            printf("\nDigite o nome do aluno:\n");
            char *nome_aluno = malloc(sizeof(256));
            scanf(" %[^\n]s", nome_aluno);

            printf("\nDigite a matricula:\n");
            char *matricula = malloc(sizeof(256));
            scanf(" %s", matricula);

            printf("\nDigite uma descricao:\n");
            char *descricao = malloc(sizeof(256));
            scanf(" %[^\n]s", descricao);

            criarEncomenda(nome_aluno, matricula, descricao);
            
            sleep(2);
            
        }else if(resp == 4){
            in_ordem(root);
            sleep(5);
        }
        /*if(resp == 1){
            //encomendar um livro
             printf(" Digite o nome do aluno:\n");
             char * nome = malloc(sizeof(char));
             scanf(" %[^\n]s", nome);
             //... matricula e descricao..
             //criar um funcao para gerar id unico (:D)
            //add_abb(id, nome, matricula, descricao);
        }else if(resp == 2){
            //remover uma encomenda de livro da ABB (id)
            //para remover eu preciso:
            //1 - visualizar as encomendas (in_ordem)
            in_ordem();
            //2 - verificar o usuario
            printf(" Digite seu cpf:\n");
            char cpf[100];
            scanf("%s", &cpf);
            printf(" Digite sua senha:\n");
            char senha[100];
            scanf("%s", &senha);
            //int retorno = verificar(cpf, senha);
            if(retorno == 1){
                //3 - chama a funcao remover_abb por id (CADE ESSA FUNCAO?)
                //4 - setar novos dados (faltando)
                //5 - add_fila(....);
            }else if(resp == 3){
               
                //2 - verificar o usuario
                    printf(" Digite seu cpf:\n");
                    char cpf[100];
                    scanf("%s", &cpf);
                    printf(" Digite sua senha:\n");
                    char senha[100];
                    scanf("%s", &senha);
                    //int retorno = verificar(cpf, senha);
                    if(retorno == 1){
                        //remover da fila de prioridade
                    }
            }
        
        }*/
        
    }
    
    return 0;
}