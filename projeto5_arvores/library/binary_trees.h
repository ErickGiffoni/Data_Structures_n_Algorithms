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

void searchValue(Tree *,int , int, int);
void getElement(Node *, int *, int *);
void showTree(Node *);

int getHeight(Node *t);
int maxSizeNode(int left, int right);
Node *removeValue(Node *root, int numb);
Node *findMinimum(Node *n);
void printInOrder(Node *);
void printPreOrder(Node *);
void printPostOrder(Node *);

int isFull(Node *root);
int isBalanced(Node *);
Tree *balanceTree(Tree *);
void freeTree(Node *n);

#endif
