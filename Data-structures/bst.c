#include "bst.h"
#include <stdio.h>

BSTEncomendaNode* searchNode(BSTEncomendaNode *aux, int id)
{
  if (aux == NULL)
    return NULL;

  if (aux->valor->id == id)
    return aux;
  else if (aux->valor->id > id)
  {
    if (aux->left != NULL)
      return searchNode(aux->left, id);
    else
      return aux;
  }
  else if (aux->valor->id < id)
  {
    if (aux->right != NULL)
      return searchNode(aux->right, id);
    else
      return aux;
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
void removeNode(BSTEncomendas* aux, int id)
{
  BSTEncomendaNode* toRemove = searchNode(aux->root, id);
  BSTEncomendaNode* dad = searchDad(aux, id);

  if (toRemove->right == NULL && toRemove->left == NULL)
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

  free(toRemove);
}

void printPreOrder(BSTEncomendaNode* aux)
{
  printf("%d\n", aux->valor->id);

  if (aux->left != NULL)
    printPreOrder(aux->left);
  if (aux->right != NULL)
    printPreOrder(aux->right);
}

void PrintInOrder(BSTEncomendaNode *aux)
{
  if (aux->left != NULL)
    PrintInOrder(aux->left);

  printf("%d\n", aux->valor->id);

  if (aux->right != NULL)
    PrintInOrder(aux->right);
}

void PrintPosOrder(BSTEncomendaNode *aux)
{
  if (aux->left != NULL)
    PrintPosOrder(aux->left);
  if (aux->right != NULL)
    PrintPosOrder(aux->right);

  printf("%d\n", aux->valor->id);
}