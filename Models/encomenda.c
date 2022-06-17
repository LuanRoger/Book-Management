#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "encomenda.h"
#include "../Generators/id_generator.h"

Encomenda *root = NULL;

Encomenda* search(int id, Encomenda* aux){
    if(aux != NULL){   
        if(aux->id == id){
            return root;

        }else if(aux->id > id){
            if(aux->left != NULL){
                return search(id, aux->left);

            }else{
                return aux;
            }

        }else if(aux->id < id){
            if(aux->right != NULL){
                return search(id, aux->right);
            
            }else{
                return aux;
            }

        }
    }else{
        return NULL;
    }
}


void criarEncomenda(char *nome_aluno, char *matricula, char *descricao){

    int id = id_generator();
    //busca
    Encomenda *aux = search(id, root);

    //condicao de existencia com base na busca
    if(aux != NULL && aux->id == id){ //se aux->id vinhesse como primeira condição daria estouro de memoria
        while(aux->id == id){
            id = id_generator();
        }
        

    }else{
        Encomenda* novaEncomenda = malloc(sizeof(Encomenda));        
        novaEncomenda->id = id;
        novaEncomenda->nome_aluno = nome_aluno;
        novaEncomenda->matricula = matricula;
        novaEncomenda->descricao = descricao;
        novaEncomenda->right = NULL;
        novaEncomenda->left = NULL;

        if(aux == NULL){
            root = novaEncomenda;

        }else{
            if(aux->id > id){
                aux->left = novaEncomenda;

            }else{
                aux->right = novaEncomenda;
            }
        }
        printf("\nEncomenda Cadastrada com sucesso!\n");
    }
     
}

Encomenda *removal(int id, Encomenda *aux){
    
    //checar se o elemento existe
    if(aux != NULL){

        //checar se o aux é o elemento escolhido
        if(aux->id == id){  
            //remover folha
            if(aux->left == NULL && aux->right == NULL){
                free(aux);
                return NULL;

            //remover com 1 filho
            }else if(aux->left == NULL || aux->right == NULL){
                Encomenda *storage;

                //armazena dependendo do ponteiro
                if(aux->left != NULL){
                    storage = aux->left;
                }else{
                    storage = aux->right;
                }
                free(aux);
                return storage;

            //remover com 2 filhos
            }else{
                Encomenda *storage = aux->left;
                while(storage->right != NULL){
                    storage = storage->right;
                }
                aux->id = storage->id;
                storage->id = id; 
                aux->left = removal(id, aux->left);
                return root;
            }
            
        }else{
            //caminhar na arvore de forma recursiva e depois retornar a raiz
            if(aux->id > id){
                aux->left = removal(id, aux->left);

            }else{
                aux->right = removal(id, aux->right);

            }
            return aux;
        }
    }else{
        printf("Valor nao encontrado!\n");
        return NULL;
    }
}


void in_ordem(Encomenda *aux){
    if(aux->left != NULL){
        in_ordem(aux->left);
    }
    
    printf("\n");
    printf("ID: %d\n", aux->id);
    printf("Nome do aluno: %s\n", aux->nome_aluno);
    printf("Matricula: %s\n", aux->matricula);
    printf("Descricao: %s\n", aux->descricao);

    if(aux->right != NULL){
        in_ordem(aux->right);
    }
}
