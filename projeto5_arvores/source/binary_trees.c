#include "../library/binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

Node *newEmptyNode(){
  Node *temp = (Node *)calloc(1,sizeof(Node)); //nova arvore vazia, toda em zero
  if(temp == NULL) {
    printf("newEmptyNode ERROR: Not possible to create new node\n\n");
    return NULL;
  }
  else return temp;
}//end of newEmptyNode

Tree *newEmptyTree(){
  Tree *temp = (Tree *)calloc(1,sizeof(Tree)); //nova arvore vazia, toda em zero
  if(temp == NULL) {
    printf("newEmptyTree ERROR: Not possible to create new tree\n\n");
    return NULL;
  }
  else return temp;
}//end of newEmptyTree

Tree *createTree(Tree *tree, int *number){
  Tree *temp = newEmptyTree(); //auxiliar
  if(temp == NULL){
    printf("createTree ERROR: not possible to create new temp empty tree\n\n");
    return NULL;
  }// se arvore temp auxiliar nao foi alocada
  temp = tree;
  Node *node;
  //checar se a arvore tem raiz
  if(tree->empty == 0){
    tree->root = newEmptyNode();
    tree->root->value = *number;
    tree->root->right = NULL;
    tree->root->left = NULL;
  }//nao tem raiz
  //caso tenha
  else{
    if(*number > tree->root->value){
      if(tree->root->right == NULL){
        node = newEmptyNode();
        if(node == NULL){
          printf("createTree ERROR: not possible to create empty node\n\n");
          return NULL;
        }//se o no nao foi alocado
        node->value = *number;
        tree->root->right = node;
        //printf("aqui\n\n");
      }//if nao tem no depois da raiz
      else{
        temp->root = tree->root->right;
        temp = createTree(temp, number);
        tree->root->right = temp->root;
      }//tem no depois da raiz
    }//go right
    else{
      if(tree->root->left == NULL){
        node = newEmptyNode();
        if(node == NULL){
          printf("createTree ERROR: not possible to create empty node\n\n");
          return NULL;
        }//se o no nao foi alocado
        node->value = *number;
        tree->root->left = node;
      }//if nao tem no depois da raiz
      else{
        temp->root = tree->root->left;
        temp = createTree(temp, number);
        tree->root->left = temp->root;
      }//tem no depois da raiz
    }//else go left
  }//else tem raiz
  return tree;
}//end of createTree

Tree *loadTreeFromFile(char *nome_do_arquivo){
  Tree *tree = newEmptyTree();
  if(tree == NULL){
    printf("loadTreeFromFile ERROR: not possible to create new tree\n\n");
    return NULL;
  }//se ponteiro para nova arvore foi nulo
  FILE *arquivo = fopen(nome_do_arquivo, "r");
  if(arquivo == NULL){
    printf("loadTreeFromFile ERROR: not possible to open file\n\n");
    return NULL;
  }// se ponteiro para arquivo com os dados foi nulo
  int number; //numero que sera lido no arquivo
  do{
    fscanf(arquivo, "%d ", &number);
    tree = createTree(tree, &number);
  }while(!feof(arquivo)); //enquanto nao chegamos ao final do arquivo
  fclose(arquivo);
  return tree;
}//end of loadTreeFromFile

showTree(){

}//end of showTree

isFull(){

}//end of isFull

searchValue(){

}//end of searchValue

getHeight(){

}//end of getHeight

removeValue(){

}//end of removeValue

printInOrder(){

}//end of printInOrder

printPreOrder(){

}//end of printPreOrder

printPosOrder(){

}//end of printPosOrder

balanceTree(){

}//end of balanceTree
