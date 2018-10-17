#include <stdio.h>

/*  Function to print out the options to the user as a menu   */

#define SAIR 1

void menu(int *opcao){
  printf("\t\t\t***** MENU *****\nPor favor, digite o numero da opcao desejada:\n");
  printf("\t1- Inserir novo registro ;\n");
  printf("\t2- Remover registro que contenha certa string no nome ;\n");
  printf("\t3- Visualizar registro que contenha certa string no nome ;\n");
  printf("\t4- Visualizar todos os registros, em ordem alfabetica, de acordo com o nome ;\n");
  printf("\t5- Sair ;\n\n");
  printf("Opcao : ");
  scanf("%d", opcao);
}//end of function MENU

int main(){

  int opcao =0;

inicio:
  menu(&opcao); //parametro deve ser ponteiro -> passamos o endereco, entao.

  switch (opcao) {
    case 1:
      printf("Opcao 1\n");
      break;
    case 2:
      printf("Opcao 2\n");
      break;
    case 3:
      printf("Opcao 3\n");
      break;
    case 4:
      printf("Opcao 4\n");
      break;
    case 5:
      printf("Opcao 5\n"); // implementar a saida do programa
      return SAIR;
    default:
      fflush(stdin);
      opcao = 0; // erro : laco infinito se o usuario digitar algo nao numerico (letra por exemplo)
      printf("Opcao invalida, tente novamente.\n\n\n\n");
      goto inicio;
  }

  return 0;
}
