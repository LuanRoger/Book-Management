#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Models/encomenda.h"
#include "Models/pedido.h"
#include "Models/usuario.h"
#include "Users/user_verification.h"
#include "Data-structures/list.h"
#include "Data-structures/queue.h"
#include "Data-structures/bst.h"

int main(){

    Usuario* user1 = criar_usuario("Vinicius de Oliviera Costa", "814.587.813-64", "1234", 1);
    Usuario* user2 = criar_usuario("Luan Roger dos Santos Clementino", "342.024.603-08", "4002", 1);
    Usuario* user3 = criar_usuario("Tatiane Fernandes Figueiredo", "832.612.816-08", "1530", 1);
    Usuario* user4 = criar_usuario("Joao Augusto Silva Ferreira", "334.321.043-91", "1337", 2);
    Usuario* user5 = criar_usuario("Kaua Magalhaes Paraizo", "583.056.943-48", "2207", 2);
    Usuario* user6 = criar_usuario("Caio Finotti Bosco", "133.015.753-23", "1834", 2);
    Usuario* user7 = criar_usuario("Joao Augusto Nogueira de Sousa", "309.345.223-67", "0000", 2);
    Usuario* user8 = criar_usuario("Avallos Marinho de Oliveira", "012.303.223-70", "9494", 2);
    
    
    ListaUsuario* listaUsers = malloc(sizeof(ListaUsuario));
    addListaUsuario(listaUsers, user1);
    addListaUsuario(listaUsers, user2);
    addListaUsuario(listaUsers, user3);
    addListaUsuario(listaUsers, user4);
    addListaUsuario(listaUsers, user5);
    addListaUsuario(listaUsers, user6);
    addListaUsuario(listaUsers, user7);
    addListaUsuario(listaUsers, user8);
    
    BSTEncomendas* bst = malloc(sizeof(BSTEncomendas));
    addNode(bst, criar_encomenda(10, "Roger", "517173", "Ronaldo"));
    addNode(bst, criar_encomenda(5, "Vini", "23423", "Des"));
    addNode(bst, criar_encomenda(3, "Ronaldo", "123456", "Melhor"));
    addNode(bst, criar_encomenda(8, "File", "123456", "asdaf"));
    addNode(bst, criar_encomenda(13, "Titu", "098765", "Description"));
    addNode(bst, criar_encomenda(11, "Pele", "609013", "Fifu"));

    removeNode(bst, 8);

    int resp = -1;
    while(resp != 0){
        system("clear");
        printf("\n\tBOOK MANAGEMENT\n");
        printf("[1] - Encomendar um livro.\n");
        printf("[2] - Remover uma encomenda de livro.\n");
        printf("[3] - Remover um pedido de livro.\n");
        printf("[0] - Sair do sistema!\n");
        printf("\nDigite a funcionalidade desejada: ");
        scanf("%d", &resp);

        if(resp == 1){

            // printf("\nDigite o nome do aluno:\n");
            // char *nome_aluno = malloc(sizeof(char));
            // scanf(" %[^\n]s", nome_aluno);

            // printf("\nDigite a matricula:\n");
            // char *matricula = malloc(sizeof(char));
            // scanf(" %s", matricula);

            // printf("\nDigite uma descricao:\n");
            // char *descricao = malloc(sizeof(char));
            // scanf(" %[^\n]s", descricao);

            // criar_encomenda(nome_aluno, matricula, descricao);
            
            sleep(2);
            
        // }else if(resp == 2){
        //     if(root == NULL){
        //         printf("\nNENHUMA ENCOMENDA CADASTRADA\n");
        //         sleep(2);
        //     }else{
        //         if(verification() == 1){
        //             printf("\nUSUARIO LOGADO\n");
        //             sleep(1);
        //         }else
        //             printf("\nLOGIN E/OU SENHA INCORRETA\n");
        //             sleep(1);

        //     }
        //     printf("\n");
   
        } else if(resp == 4){
            PrintInOrder(bst->root);
            break;
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