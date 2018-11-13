#include "../library/binary_trees.h"
#include <stdio.h>

void menu();

int main(){

  printf("\n\t\tWelcome to the jungle!\n\t\tLet's build some trees?\n\n\n");
  int opcao = 0;
  int True = 1;
  do{
    menu();
    scanf("%d", &opcao);
    switch (opcao) {
      case 1: //loadTreeFromFile

        break;
      case 2: //showTree

        break;
      case 3: //isFull

        break;
      case 4: //searchValue

        break;
      case 5: //getHeight

        break;
      case 6: //removeValue

        break;
      case 7: //printInOrder

        break;
      case 8: //printPreOrder

        break;
      case 9: //printPosOrder

        break;
      case 10: //balanceTree

        break;
      case 11: //sair
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
  printf("Choose an option below. Type donw its number\n\n");
  printf("\t1 - load Tree From File\n");
  printf("\t2 - show Tree\n");
  printf("\t3 - is Full ?\n");
  printf("\t4 - search Value\n");
  printf("\t5 - get Height\n");
  printf("\t6 - remove Value\n");
  printf("\t7 - print In Order\n");
  printf("\t8 - print Pre Order\n");
  printf("\t9 - print Pos Order\n");
  printf("\t10 - balance Tree\n");
  printf("\t11 - Exit\n\n");
  printf("Option ");
}
