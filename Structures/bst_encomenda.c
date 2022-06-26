#include "bst_encomenda.h"

BSTEncomendaNode* SearchNode(BSTEncomendaNode* node, int id)
{
  if (node == NULL)
    return NULL;

  if (node->valor->id == id)
    return node;
  else if (node->valor->id > id)
  {
    if (node->left != NULL)
      return SearchNode(node->left, id);
    else
      return node;
  }
  else if (node->valor->id < id)
  {
    if (node->right != NULL)
      return SearchNode(node->right, id);
    else
      return node;
  }

  return NULL;
}

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
BSTEncomendaNode* SearchDad(BSTEncomendas* bst, int id)
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
BSTEncomendaNode* GotoSmallest(BSTEncomendaNode* start)
{
  BSTEncomendaNode* aux = start;
  while (aux->left != NULL)
    aux = aux->left;

  return aux;
}
BSTEncomendaNode* GotoHigher(BSTEncomendaNode* start) {
  BSTEncomendaNode* aux = start;
  while (aux->right != NULL)
    aux = aux->right;
  
  return aux;
}
BSTEncomendaNode* RemoveNode(BSTEncomendas* bst, int id)
{
  BSTEncomendaNode* toRemove = SearchNode(bst->root, id);
  BSTEncomendaNode* dad = toRemove->valor->id != bst->root->valor->id ? SearchDad(bst, id) : NULL;
  if(toRemove->valor->id != id) return NULL;

  if(dad == NULL) {
    BSTEncomendaNode* rootSub = NULL;
    if(toRemove->right != NULL)
      rootSub = GotoSmallest(toRemove->right);
    else if(toRemove->left != NULL)
      rootSub = GotoHigher(toRemove->left);

    if(rootSub != NULL) {
      rootSub = RemoveNode(bst, rootSub->valor->id);
      rootSub->left = toRemove->left;
      rootSub->right = toRemove->right;
      bst->root = rootSub;
    }
    else bst->root = NULL;
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
void DeleteNode(BSTEncomendaNode* node) {
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

  printf("╔════════════════════════════════════════════════════════════╗\n");
  printf(" ID: %d\n", node->valor->id);  
  printf(" Nome: %s\n", node->valor->nome_aluno);
  printf(" Matricula: %s\n", node->valor->matricula);
  printf(" Descrição: %s\n", node->valor->descricao);
  printf("╚════════════════════════════════════════════════════════════╝\n");
  printf("\n");


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