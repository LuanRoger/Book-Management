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

BSTEncomendaNode* searchNode(BSTEncomendaNode *node, int id);
void addNode(BSTEncomendas* bst, Encomenda* encomenda);
BSTEncomendaNode* searchDad(BSTEncomendas* bst, int id);
BSTEncomendaNode* gotoHigher(BSTEncomendaNode* start);
BSTEncomendaNode* removeNode(BSTEncomendas* node, int id);

void deleteNode(BSTEncomendaNode* node);

void printPreOrder(BSTEncomendaNode* node);
void PrintInOrder(BSTEncomendaNode* node);
void PrintPosOrder(BSTEncomendaNode* node);

#endif