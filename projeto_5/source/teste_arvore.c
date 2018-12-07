#include "../library/binary_trees.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define caminho "../BSTs/"

void menu();

int main(){
  Tree *tree = newEmptyTree();
  if(tree == NULL){
    printf("main ERROR: not possible to create new tree\n\n");
  }//se ponteiro para nova arvore foi nulo

  char nome_do_arquivo[9] = {};
  char caminho_completo[17] = {};

  printf("\n\t\tWelcome to the jungle!\n\t\tLet's build some trees?\n\n\n");

  int value_for_search = 0;
  int treeSize = 0;
  int find_del = 0;

  int response = 0;
  int balanced;
  int opcao = 0;
  int True = 1;
  do{
    menu();
    scanf("%d", &opcao);
    switch (opcao) {
      case 1: //loadTreeFromFile
        printf("\n\nType the file's name: \nOPTIONS:\n\tbst1.txt\n\tbst2.txt\n\tbst3.txt\n\tbst4.txt\n\tbst5.txt\n\tbst6.txt:\n\n -");
        scanf("%s[^\n]", nome_do_arquivo);
        strcpy(caminho_completo, caminho);
        strcat(caminho_completo, nome_do_arquivo);
        tree = loadTreeFromFile(caminho_completo);
        if (tree)printf("\t-----------FILE OPENED SUCCESSFULLY-----------\n");
        break;
      case 2: //showTree
        if(tree) showTree(tree->root);
        else printf("option 2 ERROR: not possible to show a null tree\n\n");
        break;
      case 3: //isFull
        response = isFull(tree->root);
        printf("Tree is %s!\n", (response == 1) ? "Full": "Not Full");
        break;
      case 4: //searchValue
        if(tree->root){
          printf("Informe o valor a ser pesquisado\n");
          scanf("%d", &value_for_search);
          Node *temp;
          temp = newEmptyNode();
          temp = tree->root;

          searchValue(temp,temp-> value, value_for_search, 1);
          getchar();
          //tree = loadTreeFromFile(caminho_completo);
        }
        else printf("option 4 ERROR: not possible to search in a null tree\n\n");
        break;
      case 5: //getHeight
        treeSize = getHeight(tree->root);
        printf("Height: %d\n", treeSize);
        tree->height = treeSize;
        break;
      case 6:
        printf("Type a value that'll be selected:\n");
        scanf("%d", &find_del);
        tree->root = removeValue(tree->root, find_del);
        break;
      case 7: //printInOrder
        puts("\n");
        if (tree->root)printInOrder(tree->root);
        else printf("option 7 ERROR: not possible to print a null tree\n\n");
        puts("\n");
        break;
      case 8: //printPreOrder
        puts("\n");
        if (tree->root)printPreOrder(tree->root);
        else printf("option 8 ERROR: not possible to print a null tree\n\n");
        puts("\n");
        break;
      case 9: //printPosOrder
        puts("\n");
        if(tree->root)printPostOrder(tree->root);
        else printf("option 9 ERROR: not possible to print a null tree\n\n");
        puts("\n");
        break;
      case 10: //balanceTree
        if (tree->root){
          balanced = isBalanced(tree->root);
          printf("balanced = %d\n", balanced);
          if(balanced == 0)
          {
            tree = balanceTree(tree);
            printf("\nThe Tree is balanced now!\n\n");
          }
          else
          {
            printf("\nThe Tree was balanced!\n\n");
          }
        }
        else printf("option 10 ERROR: not possible to balance a null tree\n\n");
        break;
      case 11: //sair
        if (tree->root == NULL)
        {
          printf("impossible to free a NULL tree\n");
          printf("Thank you, teacher, for your support!!!\n\n");
        }
        else
        {
          printf("\nFreeing elements tree");
          printf("\n-----------------------------------------------\n");
          freeTree(tree->root);
          printf("-----------------------------------------------\n");
          printf("Thank you, teacher, for your support!!!\n\n");
        }
        True = 0;
        break;
      default :
        printf("Option does not exist\nTry again\n\n");
        getchar();

    }//end of switch opcao
  }while(True);

  return 0;
}//end main

void menu(){
  printf("\nChoose an option below. Type down its number\n\n");
  printf("\t1 - Load Tree From File\n");
  printf("\t2 - Show Tree\n");
  printf("\t3 - Is Full ?\n");
  printf("\t4 - Search Value\n");
  printf("\t5 - Get Height\n");
  printf("\t6 - Remove Value\n");
  printf("\t7 - Print In Order\n");
  printf("\t8 - Print Pre Order\n");
  printf("\t9 - Print Post Order\n");
  printf("\t10 - Balance Tree\n");
  printf("\t11 - Exit\n\n");
  printf("Option ");
}
