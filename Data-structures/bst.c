#include "bst.h"
#include <stdio.h>

BSTEncomendaNode* searchNode(BSTEncomendaNode* node, int id)
{
  if (node == NULL)
    return NULL;

  if (node->valor->id == id)
    return node;
  else if (node->valor->id > id)
  {
    if (node->left != NULL)
      return searchNode(node->left, id);
    else
      return node;
  }
  else if (node->valor->id < id)
  {
    if (node->right != NULL)
      return searchNode(node->right, id);
    else
      return node;
  }

  return NULL;
}

void addNode(BSTEncomendas* bst, Encomenda* encomenda)
{
    BSTEncomendaNode* aux = searchNode(bst->root, encomenda->id);
    if (aux != NULL && aux->valor->id == encomenda->id) return;

    BSTEncomendaNode* novo = malloc(sizeof(BSTEncomendaNode));
    novo->valor = encomenda;
    novo->left = NULL;
    novo->right = NULL;

    if (aux == NULL)
        bst->root = novo;
    else
    {
        if (aux->valor->id > encomenda->id)
        aux->left = novo;
        else
        aux->right = novo;
    }
}
BSTEncomendaNode* searchDad(BSTEncomendas* bst, int id)
{
  BSTEncomendaNode *aux = bst->root;
  while (aux->left != NULL && aux->right != NULL)
  {
    if (aux->right != NULL && aux->right->valor->id == id ||
        aux->left != NULL && aux->left->valor->id == id)
      return aux;

    if (id > aux->valor->id)
      aux = aux->right;
    else
      aux = aux->left;
  }

  return aux;
}
BSTEncomendaNode* gotoHigher(BSTEncomendaNode* start)
{
  BSTEncomendaNode* aux = start;
  while (aux->left != NULL)
    aux = aux->left;

  return aux;
}
BSTEncomendaNode* removeNode(BSTEncomendas* node, int id)
{
  BSTEncomendaNode* toRemove = searchNode(node->root, id);
  BSTEncomendaNode* dad = toRemove->valor->id != node->root->valor->id ? searchDad(node, id) : NULL;

  if(dad == NULL) {
    BSTEncomendaNode* temp = gotoHigher(toRemove->right);
    temp = removeNode(node, temp->valor->id);
    temp->left = toRemove->left;
    temp->right = toRemove->right;

    node->root = temp;
  }
  else if (toRemove->right == NULL && toRemove->left == NULL)
  {
    if (dad->right == toRemove)
      dad->right = NULL;
    else
      dad->left = NULL;
  }
  else if (toRemove->right == NULL && toRemove->left != NULL ||
   toRemove->left == NULL && toRemove->right != NULL)
  {
    BSTEncomendaNode* child = toRemove->right != NULL ? toRemove->right : toRemove->left;

    if (dad->left == toRemove)
      dad->left = child;
    else
      dad->right = child;
  }
  else if (toRemove->right != NULL && toRemove->left != NULL)
  {
    BSTEncomendaNode* higher = gotoHigher(toRemove->right);

    if (dad->left == toRemove)
      dad->left = higher;
    else
      dad->right = higher;

    higher->right = toRemove->right != higher ? toRemove->right : NULL;
    higher->left = toRemove->left != higher ? toRemove->left : NULL;
  }

  return toRemove;
}
void deleteNode(BSTEncomendaNode* node) {
  deletar_encomenda(node->valor);
  free(node);
}

void printPreOrder(BSTEncomendaNode* node)
{
  printf("%d\n", node->valor->id);

  if (node->left != NULL)
    printPreOrder(node->left);
  if (node->right != NULL)
    printPreOrder(node->right);
}

void PrintInOrder(BSTEncomendaNode *node)
{
  if (node->left != NULL)
    PrintInOrder(node->left);

  printf("%d\n", node->valor->id);

  if (node->right != NULL)
    PrintInOrder(node->right);
}

void PrintPosOrder(BSTEncomendaNode *node)
{
  if (node->left != NULL)
    PrintPosOrder(node->left);
  if (node->right != NULL)
    PrintPosOrder(node->right);

  printf("%d\n", node->valor->id);
}