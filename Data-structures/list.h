#include "../Models/encomenda.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef LIST_H
#define LIST_H
typedef struct ItemListEncomenda {
   Encomenda* valor;
   struct ItemListEncomenda* prox;
   struct ItemListEncomenda* ant;
}ItemListEncomenda;
typedef struct ListaEncomenda
{
    ItemListEncomenda* inicio;
    ItemListEncomenda* fim;
    int len;  
}ListaEncomenda;

void add_encomenda(ListaEncomenda* list, int pos, int id, char* nome_aluno, char* matricula, char* descricao);
void imprimir();

#endif