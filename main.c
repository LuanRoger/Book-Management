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


int main(){

    Usuario* user1 = CriarUsuario("Vinicius de Oliviera Costa", "90459959301", "1234", 2);
    Usuario* user2 = CriarUsuario("Luan Roger dos Santos Clementino", "34202460308", "4002", 1);
    Usuario* user3 = CriarUsuario("Tatiane Fernandes Figueiredo", "83261281608", "1530", 1);
    Usuario* user4 = CriarUsuario("Joao Augusto Silva Ferreira", "33432104391", "1337", 2);
    Usuario* user5 = CriarUsuario("Kaua Magalhaes Paraizo", "58305694348", "2207", 2);
    Usuario* user6 = CriarUsuario("Caio Finotti Bosco", "13301575323", "1834", 2);
    Usuario* user7 = CriarUsuario("Joao Augusto Nogueira de Sousa", "30934522367", "0000", 2);
    Usuario* user8 = CriarUsuario("Avallos Marinho de Oliveira", "01230322370", "9494", 2);
    
    
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
    AddNode(bst, CriarEncomenda(10, "Roger", "517173", "Ronaldo"));
    AddNode(bst, CriarEncomenda(8, "Vini", "23423", "Des"));
    AddNode(bst, CriarEncomenda(5, "Ronaldo", "123456", "Melhor"));
    AddNode(bst, CriarEncomenda(10, "File", "123456", "asdaf"));
    AddNode(bst, CriarEncomenda(13, "Titu", "098765", "Description"));
    AddNode(bst, CriarEncomenda(11, "Pele", "609013", "Fifu"));
    

    int resp = -1;
    while(resp != 0){
        
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
            PrintPreOrder(bst->root);
            break;
            
        } else if(resp == 5){
            Verify(listaUsers, CARGO_SECRETARIO);
        }else if(resp == 6){
            ImprimirLista(listaUsers);
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