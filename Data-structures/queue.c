#include <stdio.h>
#include <stdlib.h>


typedef struct prod{
    int cod_prod;
    double preco;
}PROD;

typedef struct No{
   
    int cod_prod;
    double preco;
    
    //mecanismo p/ unir nos!
    struct No * prox;
}NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;

void add(int cod_prod, double preco){
    
        NO * novo = malloc(sizeof(NO));
        novo->cod_prod = cod_prod;
        novo->preco = preco;
        novo->prox = NULL;
    
        if(inicio == NULL){ //fila vazia
            inicio = novo;
            fim = novo;
            tam++;
        }else{ //add usando o antigo add fim da lista
            fim->prox = novo;
            fim = novo;
            tam++;
        }
}


void imprimir(){
    NO * aux = inicio;
    for(int i = 0; i < tam; i++){
        printf("Cod prod: %d\n", aux->cod_prod);
            aux = aux->prox;
    }
}

PROD remover(){
    
    PROD produto;
    if(inicio != NULL){
        //remover usando o antigo remover do inicio da lista!
            
            NO *lixo = inicio;
            inicio = inicio->prox;
            produto.cod_prod = lixo->cod_prod;
            produto.preco = lixo->preco;
            free(lixo);
            tam--;
            if(tam == 1){
                fim = NULL;
            }
            
    }
    return produto;
}


int main(){

    add(29383, 50.0);
    add(29848, 150.0);
    add(29646, 20.0);
    add(29133, 20.0);
    add(4444, 70.0);
    printf("Impressao antes da remocao:\n");
    imprimir();
    PROD teste = remover();
    printf("Cod prod removido eh:%d\n", teste.cod_prod);
    
    return 0;
}




