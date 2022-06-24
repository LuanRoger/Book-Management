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
BSTEncomendaNode* GotoHigher(BSTEncomendaNode* start)
{
  BSTEncomendaNode* aux = start;
  while (aux->left != NULL)
    aux = aux->left;

  return aux;
}
BSTEncomendaNode* RemoveNode(BSTEncomendas* node, int id)
{
  BSTEncomendaNode* toRemove = SearchNode(node->root, id);
  BSTEncomendaNode* dad = toRemove->valor->id != node->root->valor->id ? SearchDad(node, id) : NULL;

  if(dad == NULL) {
    BSTEncomendaNode* temp = GotoHigher(toRemove->right);
    temp = RemoveNode(node, temp->valor->id);
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
    BSTEncomendaNode* higher = GotoHigher(toRemove->right);

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

  printf("ID: %d\n", node->valor->id);
  printf("Nome: %s\n", node->valor->nome_aluno);
  printf("Matricula: %s\n", node->valor->matricula);
  printf("Descrição: %s\n", node->valor->descricao);
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