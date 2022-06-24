#include "bst_encomenda.h"

void AddNode(BSTEncomendas* bst, Encomenda* encomenda)
{
    BSTEncomendaNode* aux = SearchNode(bst->root, encomenda->id);
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
BSTEncomendaNode* RemoveNode(BSTEncomendas* bst, int id)
{
  BSTEncomendaNode* toRemove = SearchNode(bst->root, id);
  if(toRemove == NULL) return NULL;

  BSTEncomendaNode* dad = toRemove->valor->id != bst->root->valor->id ? SearchDad(bst, id) : NULL;

  if(dad == NULL) {
    BSTEncomendaNode* rootSub = GotoSmallest(toRemove->right);
    if(rootSub != NULL) {
      rootSub = RemoveNode(bst, rootSub->valor->id);
      rootSub->left = toRemove->left;
      rootSub->right = toRemove->right;
    }

    bst->root = rootSub;
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
    BSTEncomendaNode* higher = GotoSmallest(toRemove->right);

    if (dad->left == toRemove) 
      dad->left = higher;
    else 
      dad->right = higher;

    higher->right = toRemove->right != higher ? toRemove->right : NULL;
    higher->left = toRemove->left != higher ? toRemove->left : NULL;
  }

  return toRemove;
}

BSTEncomendaNode* SearchNode(BSTEncomendaNode* node, int id)
{
  if (node == NULL) return NULL;

  BSTEncomendaNode* aux = node;
  while (aux->left != NULL && aux->right != NULL)
  {
    if(aux->valor->id == id)
      return aux;
    
    if(aux->valor->id < id)
      aux = aux->right;
    else
      aux = aux->left;
  }
  
  return NULL;
}
BSTEncomendaNode* SearchDad(BSTEncomendas* bst, int id)
{
  if(bst->root == NULL) return NULL;

  BSTEncomendaNode *aux = bst->root;
  while (aux->left != NULL && aux->right != NULL)
  {
    if (aux->right != NULL && aux->right->valor->id == id ||
        aux->left != NULL && aux->left->valor->id == id)
      return aux;

    if (aux->valor->id < id)
      aux = aux->right;
    else
      aux = aux->left;
  }

  return NULL;
}
BSTEncomendaNode* GotoSmallest(BSTEncomendaNode* start)
{
  if(start == NULL) return NULL;

  BSTEncomendaNode* aux = start;
  while (aux->left != NULL)
    aux = aux->left;

  return aux;
}

void DeleteBSTNode(BSTEncomendaNode* node) {
  DeletarEncomenda(node->valor);
  free(node);
}

void PrintPreOrder(BSTEncomendaNode* node)
{
  printf("%d\n", node->valor->id);

  if (node->left != NULL)
    PrintPreOrder(node->left);
  if (node->right != NULL)
    PrintPreOrder(node->right);
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