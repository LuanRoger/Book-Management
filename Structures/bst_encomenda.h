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

void AddNode(BSTEncomendas* bst, Encomenda* encomenda);
BSTEncomendaNode* RemoveNode(BSTEncomendas* bst, int id);
BSTEncomendaNode* SearchNode(BSTEncomendaNode* node, int id);
BSTEncomendaNode* SearchDad(BSTEncomendas* bst, int id);
BSTEncomendaNode* GotoSmallest(BSTEncomendaNode* start);
BSTEncomendaNode* GotoHigher(BSTEncomendaNode* start);

Encomenda* UnwrapBSTNode(BSTEncomendaNode* node);

void PrintPreOrder(BSTEncomendaNode* node);
void PrintInOrder(BSTEncomendaNode* node);
void PrintPosOrder(BSTEncomendaNode* node);

#endif