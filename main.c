#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Models/encomenda.h"
#include "Models/pedido.h"
#include "Models/usuario.h"
#include "Users/user_verification.h"
#include "Structures/lista_usuario.h"
#include "Structures/fila_pedido.h"
#include "Structures/bst_encomenda.h"
#include "Generators/id_generator.h"
#include "Workflows/cadastrar_pedido_workflow.h"
#include "Workflows/cadastrar_encomenda_workflow.h"
//TODO: limpar termina depois uma operacao

int main(){
    Usuario* user1 = CriarUsuario("Vinicius de Oliviera Costa", "814.587.813-64", "1234", 1);
    Usuario* user2 = CriarUsuario("Luan Roger dos Santos Clementino", "342.024.603-08", "4002", 1);
    Usuario* user3 = CriarUsuario("Tatiane Fernandes Figueiredo", "832.612.816-08", "1530", 1);
    Usuario* user4 = CriarUsuario("Joao Augusto Silva Ferreira", "334.321.043-91", "1337", 2);
    Usuario* user5 = CriarUsuario("Kaua Magalhaes Paraizo", "583.056.943-48", "2207", 2);
    Usuario* user6 = CriarUsuario("Caio Finotti Bosco", "133.015.753-23", "1834", 2);
    Usuario* user7 = CriarUsuario("Joao Augusto Nogueira de Sousa", "309.345.223-67", "0000", 2);
    Usuario* user8 = CriarUsuario("Avallos Marinho de Oliveira", "012.303.223-70", "9494", 2);
    
    
    ListaUsuario* listaUsers = malloc(sizeof(ListaUsuario));
    AddListUsuario(listaUsers, user1);
    AddListUsuario(listaUsers, user2);
    AddListUsuario(listaUsers, user3);
    AddListUsuario(listaUsers, user4);
    AddListUsuario(listaUsers, user5);
    AddListUsuario(listaUsers, user6);
    AddListUsuario(listaUsers, user7);
    AddListUsuario(listaUsers, user8);

    BSTEncomendas* bst = malloc(sizeof(BSTEncomendas));
    FilaPedido* filaPedido = malloc(sizeof(FilaPedido));

    int resp = -1;
    while(resp != 0){
        
        printf("\n\tBOOK MANAGEMENT\n");
        printf("[1] - Encomendar um livro.\n");
        printf("[2] - Cadastrar pedido.\n");
        printf("[3] - Remover pedido.\n");
        printf("[4] - Exibir encomendas.\n");
        printf("[5] - Exibir pedidos.\n");
        printf("[0] - Sair do sistema!\n");
        printf("\nDigite a funcionalidade desejada: ");
        scanf("%d", &resp);

        if(resp == 1) {
            Encomenda* newEncomenda = CadastrarEncomendaWorkflow(id_generator(bst));
            AddNode(bst, newEncomenda);
            printf("\nENCOMENDA CRIADA COM SUCESSO!\n");
        }
        else if(resp == 2) { //TODO: Create a dedicated workflow
            if(bst->root == NULL)
                printf("NENHUMA ENCOMENDA CADASTRADA.\n");
            else {
                printf("AVISO: SOMENTE SECRETÁRIOS TEM ACESSO.\n");
                
                Usuario* user = VerificationPassword(listaUsers);
                if(user == NULL)
                    printf("\nSENHA E/OU USUARIO INCORRETO!\n");
                else {
                    if(VerificationCargo(user, CARGO_SECRETARIO) != 0)
                        printf("\nUSUARIO SEM PERMISSÃO\n");
                    else {
                        PrintInOrder(bst->root);

                        Pedido* newPedido = CadastrarPedidoWorkflow(bst, user);
                        if(newPedido == NULL)
                            printf("\nESSA ENCOMENDA NÃO EXISTE!\n");
                        else 
                            AddFilaPedido(filaPedido, newPedido);
                    }
                }
            }
        }
        else if(resp == 3) { //TODO: Create a dedicated workflow
            if(filaPedido->len > 0){
                printf("AVISO: SOMENTE TRANSPORTADORES TEM ACESSO\n");

                Usuario* user = VerificationPassword(listaUsers);
                if(user == NULL){
                    printf("\nSENHA E/OU USUARIO INCORRETO!\n");

                }else{
                    if(VerificationCargo(user, CARGO_TRANSPORTADOR) == 0){
                        //pode fazer as coisas aqui dentro, encima tem a verificação completa

                    }else{
                        printf("\nUSUARIO SEM PERMISSÃO\n");
                    }
                    
                }

            }else{
                printf("\nNENHUM PEDIDO CADASTRADO\n");
            }
        }
        else if(resp == 4){
            if(bst->root == NULL){
                printf("\nNENHUMA ENCOMENDA CADASTRADA.\n");
            }else{
                PrintInOrder(bst->root);
            }
        }
        else if(resp == 5){
            if(filaPedido->len == 0){
                printf("\nNENHUM PEDIDO CADASTRADO.\n");
            }else{
                PrintFila(filaPedido);
            }
        }
        
    }
    
    return 0;
}