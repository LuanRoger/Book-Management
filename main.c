#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Models/encomenda.h"
#include "Models/pedido.h"
#include "Models/usuario.h"
#include "Users/user_verification.h"
#include "Data-structures/list_usuario.h"
#include "Data-structures/queue_pedido.h"
#include "Data-structures/bst_encomenda.h"
#include "Generators/id_generator.h"
#include "Workflows/cadastrar_pedido_workflow.h"
#include "Workflows/cadastrar_encomenda_workflow.h"

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

        if(resp == 1){
            AddNode(bst, CadastrarEncomendaWorkflow(id_generator(bst)));
        }
        else if(resp == 2) {
            PrintInOrder(bst->root);
            AddFilaPedido(filaPedido, CadastrarPedidoWorkflow(bst));
        }
        else if(resp == 3) {

        }
        else if(resp == 4){
            PrintPreOrder(bst->root);
        }
        else if(resp == 5) {
            
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