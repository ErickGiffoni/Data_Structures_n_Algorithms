#include "../library/binary_trees.h"
#include <string.h>
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
        printf("\t-----------FILE OPENED SUCCESSFULLY-----------\n");
        break;
      case 2: //showTree
      //  showTree(tree->root);
        break;
      case 3: //isFull

        break;
      case 4: //searchValue
      printf("\n\nType the file's name: \nOPTIONS:\n\tbst1.txt\n\tbst2.txt\n\tbst3.txt\n\tbst4.txt\n\tbst5.txt\n\tbst6.txt:\n\n -");
      scanf("%s[^\n]", nome_do_arquivo);
      strcpy(caminho_completo, caminho);
      strcat(caminho_completo, nome_do_arquivo);
      tree = loadTreeFromFile(caminho_completo);

      printf("Informe o valor a ser pesquisado\n");
      scanf("%d", &value_for_search);
      searchValue(tree,tree -> root -> value, value_for_search, 0);
      getchar();
        break;
      case 5: //getHeight

        break;
      case 6: //removeValue

        break;
      case 7: //printInOrder
        puts("\n");
        printInOrder(tree->root);
        puts("\n");
        break;
      case 8: //printPreOrder
        puts("\n");
        printPreOrder(tree->root);
        puts("\n");
        break;
      case 9: //printPosOrder
      puts("\n");
      printPostOrder(tree->root);
      puts("\n");
        break;
      case 10: //balanceTree

        break;
      case 11: //sair
        // tree = freeTree(tree, tree->root);
        printf("Thank you, teacher, for your support!!!\n\n");
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
  printf("Choose an option below. Type down its number\n\n");
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
