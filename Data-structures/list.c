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
    struct No * ant;
}NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;

void add(int cod_prod, double preco, int pos){
    
    if(pos >= 0 && pos <= tam){
    
        NO * novo = malloc(sizeof(NO));
        novo->cod_prod = cod_prod;
        novo->preco = preco;
        novo->prox = NULL;
        novo->ant = NULL;
    
        if(inicio == NULL){ //lista vazia
            inicio = novo;
            fim = novo;
            tam++;
        }else if(pos == 0){ //inicio
            inicio->ant = novo;
            novo->prox = inicio;
            inicio = novo;
            tam++;
        }else if(pos == tam){ //fim
            novo->ant = fim;
            fim->prox = novo;
            fim = novo;
            tam++;
        }else{ // "no meio"
            
            NO * aux = inicio;
            for(int i = 0; i < pos; i++){
                //OPERACAO DE CAMINHADA - MUITO IMPORTANTE
                aux = aux->prox;
            
            }
            novo->prox = aux;
            aux->ant->prox = novo;
            novo->ant = aux->ant;
            aux->ant = novo;
            tam++;
            
        }
    
    }else{
        printf("deu ruim!!\n");
    }
}


void imprimir(){
    NO * aux = inicio;
    for(int i = 0; i < tam; i++){
        printf("Cod prod: %d\n", aux->cod_prod);
            aux = aux->prox;
    }
}

int main(){

    add(29383, 50.0, 0);
    add(29848, 150.0, 0);
    add(29646, 20.0, 2);
    add(29133, 20.0, 0);
    add(4444, 70.0, 3);
    printf("Impressao antes da remocao:\n");
    imprimir();
   
    return 0;
}




