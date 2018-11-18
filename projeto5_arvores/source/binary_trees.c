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
    printf("\t\t |\n\t   ------ ------\n");
    printf("\t  %d \t\t %d\n", root->left->value, root->right->value);
    //if(root->left && root->right){//se tem esquerda e direita
    //  printf("\t\t |\n\t   ------ ------\n");
    //  showTree(root->left);
    //  showTree(root->right);
    //}//end se tem esquerda e direita
    //else if(root->left && root->right == NULL){//se tem so esquerda
    //  printf("\t  ------ \n");
    //  showTree(root->left);
    //}//end se tem so esquerda
    //else if(root->left == NULL && root->right){//se tem so direita
    //  printf("\t         ------\n");
    //  showTree(root->right);
    //}//end se tem so direita
    //printf("/\\\n");
    showTree(root->left);
    showTree(root->right);
  }//end raiz nao nula
}//end of showTree

/*  void isFull(Tree *tree){

    Tree *temp_right;
    temp_right = tree;

    Tree *temp_left;
    temp_left = tree;

    if(temp->right != NULL && temp->left != NULL){
      temp = temp->right;

    }
    else if()



 }//end of isFull */

  void searchValue(Tree *tree, int pai, int value_for_search, int node){
    Node *temp;
    temp = tree->root;

    int temp_pai;
    temp_pai = pai;

    Tree *temp_tree;
    temp_tree = tree;

    int t_node = node;

  if (temp == NULL) { // Árvore vazia, sem filho e sem pai.
       printf("\n\t\t---------------VALOR NAO ENCONTRADO---------------\n\t\t---------------TENTE NOVAMENTE---------------\n");
       printf("\n\t\t\\\\\\\\\\\\\\\\\\\\\\\\PRESS ENTER TO CONTINUE//////////\n\n");
       getchar();
     }

  else if(temp->value == value_for_search){//VALOR DO NÓ IGUAL AO VALOR DESEJADO, (sem pai, podendo ter filho).
    int filho_direita, filho_esquerda, value_pai;

    if(t_node == 0){
      filho_direita = temp->right->value;
      filho_esquerda = temp->left->value;
      value_pai = temp_pai;
      printf("\t\tNIVEL DO NÓ = %d\n\t\tPAI -> sem pai\n\t\tFILHO DIREITA: %d\n\t\tFILHO ESQUERDA: %d\n\n",t_node, filho_direita, filho_esquerda);
      printf("\n\t========= RAÍZ ==========\n");
      printf("\n\t\t\\\\\\\\\\\\\\\\\\\\\\\\PRESS ENTER TO CONTINUE//////////\n\n");
      getchar();
    }
    else if(temp->right != NULL && temp->left != NULL){
      filho_direita = temp->right->value;
      filho_esquerda = temp->left->value;
      value_pai = temp_pai;
      printf("\t\tNIVEL DO NÓ = %d\n\t\tPAI -> %d\n\t\tFILHO DIREITA: %d\n\t\tFILHO ESQUERDA: %d\n\n",t_node,value_pai, filho_direita, filho_esquerda);
      printf("\n\t\t\\\\\\\\\\\\\\\\\\\\\\\\PRESS ENTER TO CONTINUE//////////\n\n");
      getchar();
    }

    else if(temp->left != NULL){
      filho_esquerda = temp->left->value;
      value_pai = temp_pai;
      printf("\t\tNIVEL DO NÓ = %d\n\t\tPAI ->  %d\n\t\tFILHO DIREITA: nao tem\n\t\tFILHO ESQUERDA: %d\n\n", t_node,value_pai, filho_esquerda);
      printf("\n\t\t\\\\\\\\\\\\\\\\\\\\\\\\PRESS ENTER TO CONTINUE//////////\n\n");
      getchar();
  }
  else if(temp->right != NULL){
    filho_direita = temp->right->value;
    value_pai = temp_pai;
    printf("\t\tNIVEL DO NÓ = %d\n\t\tPAI -> %d\n\t\tFILHO DIREITA: %d\n\t\tFILHO ESQUERDA: nao tem\n\n",t_node, value_pai, filho_direita);
    printf("\n\t\t\\\\\\\\\\\\\\\\\\\\\\\\PRESS ENTER TO CONTINUE//////////\n\n");
    getchar();
  }
  else if(temp -> right == NULL && temp -> left == NULL){
    value_pai = temp_pai;
    printf("\t\tNIVEL DO NÓ = %d\n\t\tPAI -> %d\n\t\tFILHO DIREITA: nao tem\n\t\tFILHO ESQUERDA: nao tem\n\n",t_node, value_pai);
    printf("\t\t========= É FOLHA =========\n\n" );
    printf("\n\t\t\\\\\\\\\\\\\\\\\\\\\\\\PRESS ENTER TO CONTINUE//////////\n\n");
    getchar();

  }
}


  else if (temp->value > value_for_search){
       t_node++;
       temp_pai = temp->value;
       temp_tree -> root = temp_tree -> root -> left;
       return searchValue (temp_tree,temp_pai, value_for_search, t_node);
     }
  else if(temp->value < value_for_search){
        t_node++;
        temp_pai = temp->value;
        temp_tree -> root = temp_tree -> root -> right;
       return searchValue (temp_tree, temp_pai, value_for_search, t_node);

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

//int isBalanced(Node *root){// 0 -> not balanced | 1 -> balanced
//  if(root == NULL) return 1; //raiz nula, logo esta balanceado, pois nao ha direita nem esquerda
//  else{
//    if(abs(getHeight(root->right) - getHeight(root->left)) > 1){//se a diferenca das alturas da esquerda e da direita for > 1
//      return 0; //desbalanceada
//    }//end verifica diferenca nas alturas right e left
//    else{//se a diferenca nas alturas for <= 1
//      if(isBalanced(root->right)&&isBalanced(root->left)){//se esta balanceada dos dois lados
//        return 1; //balanceada
//      }//end if balanceada dos dois lados
//      else return 0; //se nao esta balanceada dos dois lados -> desbalanceada
//    }//end diferenca de alturas <= 1
//  }//end raiz nao nula
//}//end of isBalanced

/*Tree *balanceTree(Tree *tree){
  if(tree == NULL){//se a arvore for nula
    printf("balanceTree ERROR: NULL tree function call\n\n");
    return NULL;
  }//end if arvore nula
  int balanced = isBalanced(tree->root);//verifica se esta balanceada
  if(balanced){//se esta balanceada
    return tree; //retorna a arvore
  }//end if esta balanceada
  else{//se nao esta balanceada
//TODO rotacionar
  }//end nao esta balanceada
}//end of balanceTree */

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
