#include "../Models/encomenda.h"
#include <stdlib.h>

#ifndef BST_H
#define BST_H

typedef struct BSTEncomendaNode {
    Encomenda* valor;
    struct BSTEncomendaNode* left;
    struct BSTEncomendaNode* right;
}BSTEncomendaNode;

typedef struct BSTEncomendas
{
    BSTEncomendaNode* root;
}BSTEncomendas;

BSTEncomendaNode* searchNode(BSTEncomendaNode *aux, int id);
void addNode(BSTEncomendas* bst, Encomenda* encomenda);
BSTEncomendaNode* searchDad(BSTEncomendas* bst, int id);
BSTEncomendaNode* gotoHigher(BSTEncomendaNode* start);
void removeNode(BSTEncomendas* aux, int id);

void printPreOrder(BSTEncomendaNode* aux);
void PrintInOrder(BSTEncomendaNode *aux);
void PrintPosOrder(BSTEncomendaNode *aux);

#endif