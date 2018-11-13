#ifndef BINARY_TREES_H
#define BINARY_TREES_H

typedef struct node{
  int value; //informacao
  struct node *right = NULL; //ponteiro para no da direita
  struct node *left = NULL; //ponteiro para no da esquerda
}Node;

typedef struct tree{
  Node *root; //ponteiro para o no raiz
  int height; //altura
}Tree;

loadTreeFromFile();
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
