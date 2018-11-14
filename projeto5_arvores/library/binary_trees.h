#ifndef BINARY_TREES_H
#define BINARY_TREES_H

typedef struct node{
  int value; //informacao
  struct node *right; //ponteiro para no da direita
  struct node *left; //ponteiro para no da esquerda
}Node;

typedef struct tree{
  Node *root; //ponteiro para o no raiz
  int height; //altura
  int empty; //0 -> arvore vazia ; 1 -> arvore com pelo menos a raiz
}Tree;

Node *newEmptyNode();
Tree *newEmptyTree();
Tree *createTree(Tree *tree, int *number);
Tree *loadTreeFromFile(char *nome_do_arquivo);
showTree();
isFull();
searchValue();
getHeight();
removeValue();
printInOrder();
printPreOrder();
printPosOrder();
balanceTree();

#endif