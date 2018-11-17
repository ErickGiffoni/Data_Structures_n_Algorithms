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

/*Tree *createTree(Tree *tree, int *number){
  Tree *temp = newEmptyTree(); //auxiliar
  if(temp == NULL){
    printf("createTree ERROR: not possible to create new temp empty tree\n\n");
    return NULL;
  }// se arvore temp auxiliar nao foi alocada
  //temp = tree;
  Node *node;
  //checar se a arvore tem raiz
  if(tree->empty == 0){
    tree->root = newEmptyNode();
    tree->root->value = *number;
    tree->root->right = NULL;
    tree->root->left = NULL;
    tree->empty = 1; //not empty anymore;
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
        printf("aqui\n\n");
        tree->root->right = node;
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
}//end of createTree */

Tree *createTree(Tree *tree, int *number){
  Tree *temp = newEmptyTree();
  if(temp == NULL){
    printf("createTree ERROR: not possible to create new temp empty tree\n\n");
    return NULL;
  }// se arvore temp auxiliar nao foi alocada
  if(tree->root == NULL){//raiz nula
    tree->root = newEmptyNode();
    if(tree->root == NULL){
      printf("createTree ERROR: not possible to create empty tree->root node\n\n");
      return NULL;
    }//se o no nao foi alocado
    tree->root->value = *number;
    return tree;
  }//end raiz nula
  else{//raiz nao nula
    if(*number > tree->root->value){//go right
      temp->root = tree->root->right;
      temp = createTree(temp, number);
      tree->root->right = temp->root;
      return tree;
    }//end go right
    else{//go left
      temp->root = tree->root->left;
      temp = createTree(temp, number);
      tree->root->left = temp->root;
      return tree;
    }//end go left
  }//end raiz nao nula
}//end of createTree version 2

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
  // printf("chegou");

  int number; //numero que sera lido no arquivo
  do{
    fscanf(arquivo, "%d ", &number);
    //printf("File Number is: %d\n", number);
    tree = createTree(tree, &number);
    //printf("tree->root->value is: %d\n", tree->root->value);
  }while(!feof(arquivo)); //enquanto nao chegamos ao final do arquivo
  fclose(arquivo);
  return tree;
}//end of loadTreeFromFile

void showTree(Node *root){
  if(root == NULL){ //se a raiz for nula, retorna
    //printf("showTree ERROR: passing NULL node to function call\n\n");
    return;
  }//end raiz nula
  else{ //raiz nao nula
    printf("\t\t%d\n", root->value);
    printf("/\\\n");
    showTree(root->left);
    showTree(root->right);
  }//end raiz nao nula
}//end of showTree

// isFull(){

// }//end of isFull

void searchValue(Tree *tree, int value_for_search, int node){
  Node *temp;
  temp = tree->root;

  int t_node = node;

  if (temp == NULL) { // Árvore vazia, sem filho e sem pai.
       printf("\n\t\t---------------VALOR NAO ENCONTRADO---------------\n\t\t---------------TENTE NOVAMENTE---------------\n");
       printf("\n\t\t\\\\\\\\\\\\\\\\\\\\\\\\PRESS ENTER TO CONTINUE//////////\n\n");
       getchar();
     }

  else if(temp->value == value_for_search){//VALOR DO NÓ IGUAL AO VALOR DESEJADO, (sem pai, podendo ter filho).
    int filho_direita, filho_esquerda;
    if(temp->right != NULL && temp->left != NULL){
      filho_direita = temp->right->value;
      filho_esquerda = temp->left->value;
      printf("\t\tNIVEL DO NÓ = %d\n\t\tPAI -> nao tem\n\t\tFILHO DIREITA: %d\n\t\tFILHO ESQUERDA: %d\n\n",t_node, filho_direita, filho_esquerda);
      printf("\n\t\t\\\\\\\\\\\\\\\\\\\\\\\\PRESS ENTER TO CONTINUE//////////\n\n");
      getchar();
    }

    else if(temp->left != NULL){
      filho_esquerda = temp->left->value;
      printf("\t\tNIVEL DO NÓ = %d\n\t\tPAI -> nao tem\n\t\tFILHO DIREITA: nao tem\n\t\tFILHO ESQUERDA: %d\n\n", t_node, filho_esquerda);
      printf("\n\t\t\\\\\\\\\\\\\\\\\\\\\\\\PRESS ENTER TO CONTINUE//////////\n\n");
      getchar();
  }
  else if(temp->right != NULL){
    filho_direita = temp->right->value;
    printf("\t\tNIVEL DO NÓ = %d\n\t\tPAI -> nao tem\n\t\tFILHO DIREITA: %d\n\t\tFILHO ESQUERDA: nao tem\n\n",t_node, filho_direita);
    printf("\n\t\t\\\\\\\\\\\\\\\\\\\\\\\\PRESS ENTER TO CONTINUE//////////\n\n");
    getchar();
  }
  else if(temp -> right == NULL && temp -> left == NULL){
    printf("\t\tNIVEL DO NÓ = %d\n\t\tPAI -> nao tem\n\t\tFILHO DIREITA: nao tem\n\t\tFILHO ESQUERDA: nao tem\n\n",t_node);
    printf("\t\t========= É FOLHA =========\n\n" );
    printf("\n\t\t\\\\\\\\\\\\\\\\\\\\\\\\PRESS ENTER TO CONTINUE//////////\n\n");
    getchar();

  }
}


  else if (temp->value > value_for_search){
       printf("chamou value_for_search > value\n");
       t_node++;
       tree -> root = tree -> root -> left;
       return searchValue (tree, value_for_search, t_node);
     }
  else if(temp->value < value_for_search){
        printf("chamou value_for_search < value\n");
        t_node++;
        tree -> root = tree -> root -> right;
       return searchValue (tree, value_for_search, t_node);

     }

 }//end of searchValue

// int getHeight(Tree *t){
//   if(t == NULL)
//   {
//     return -1; /* se a arvore for vazia ela retornará altura -1 */
//   }
//   else
//   {
//     return 1 + maxSizeNode(getHeight(t->root->left),getHeight(t->root->right)); /* caso contrario ela retornará a altura da arvore */
//   }
// }//end of getHeight

// int maxSizeNode(int *left, int *right){
//   return (left > right) ? left:right;
// }

// removeValue(){

// }//end of removeValue

void printInOrder(Node *root){
  if(root == NULL) return;//raiz nula
  else {
    printInOrder(root->left);//vai para a esquerda
    printf("%d ", root-> value);//print o atual
    printInOrder(root->right);//vai para a direita
  }//raiz nao nula
}//end of printInOrder

void printPreOrder(Node *root){
  if(root == NULL) return;//raiz nula
  else {
    printf("%d ", root->value);//print atual
    printPreOrder(root->left);//vai p esquerda
    printPreOrder(root->right);//vai p direita
  }
}//end of printPreOrder

void printPostOrder(Node *root){
  if(root == NULL) return;//raiz nula
  else {
    printPostOrder(root->left);//vai p esquerda
    printPostOrder(root->right);//vai p direita
    printf("%d ", root->value);//print atual
  }//raiz nao nula
}//end of printPosOrder

// balanceTree(){

// }//end of balanceTree

Tree *freeTree(Tree *t, Node *n)
{
  /* Esta função libera recursivamente todos os elementos das subarvores e em seguida a arvore */
  if (t != NULL)
  {
    freeTree(t, n->left);
    freeTree(t, n->right);
    free(n);
    free(t);
  }
  return NULL;
}
