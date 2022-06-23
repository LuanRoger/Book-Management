#include "../Models/encomenda.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef BST_ENCOMENDA_H
#define BST_ENCOMENDA_H

typedef struct BSTEncomendaNode {
    Encomenda* valor;
    struct BSTEncomendaNode* left;
    struct BSTEncomendaNode* right;
}BSTEncomendaNode;

typedef struct BSTEncomendas
{
    BSTEncomendaNode* root;
}BSTEncomendas;

BSTEncomendaNode* SearchNode(BSTEncomendaNode *node, int id);
void AddNode(BSTEncomendas* bst, Encomenda* encomenda);
BSTEncomendaNode* SearchDad(BSTEncomendas* bst, int id);
BSTEncomendaNode* GotoHigher(BSTEncomendaNode* start);
BSTEncomendaNode* RemoveNode(BSTEncomendas* node, int id);

void DeleteNode(BSTEncomendaNode* node);

void PrintPreOrder(BSTEncomendaNode* node);
void PrintInOrder(BSTEncomendaNode* node);
void PrintPosOrder(BSTEncomendaNode* node);

#endif