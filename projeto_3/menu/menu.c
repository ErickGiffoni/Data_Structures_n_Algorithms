#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../biblioteca/contatos.h"
#include "../biblioteca/contatos.c"

/*  Function to print out the options to the user as a menu   */

#define SAIR 1

void menu(int *opcao){
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t***** MENU *****\nPor favor, digite o numero da opcao desejada:\n");
  printf("\t1- Inserir novo registro ;\n");
  printf("\t2- Remover registro que contenha certa string no nome ;\n");
  printf("\t3- Visualizar registro que contenha certa string no nome ;\n");
  printf("\t4- Visualizar todos os registros, em ordem alfabetica, de acordo com o nome ;\n");
  printf("\t5- Sair ;\n\n");
  printf("Opcao : ");
  scanf("%d", opcao);
}//end of function MENU

int main(){
  FILE *ponteiroParaArq;
  Contatos *contatos;
  contatos = (Contatos *)malloc(sizeof(Contatos));


  contatos = adicionaContatosDoArquivo(ponteiroParaArq);
  int opcao =0;

  int boolean = 0;

do{
  menu(&opcao); //parametro deve ser ponteiro -> passamos o endereco, entao.

  switch (opcao) {
    case 1:
      printf("Opcao 1\n");
      //boolean = 1;
      break;
    case 2:
      printf("Opcao 2\n");
      //boolean = 1;
      break;
    case 3:
      printf("Opcao 3\n");
      //boolean = 1;
      break;
    case 4:
      printf("Opcao 4\n");
      //boolean = 1;
      break;
    case 5:
      printf("Opcao 5\n"); // implementar a saida do programa
      boolean = 1;
      break;
    default:
      fflush(stdin);
      opcao = 0; // erro : laco infinito se o usuario digitar algo nao numerico (letra por exemplo)
      printf("Opcao invalida, tente novamente.\n\n\n\n");
  }

}while(!boolean);

  return 0;
}
