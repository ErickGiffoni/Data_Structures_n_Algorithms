#include "../biblioteca/contatos.h"



int main(){

  Contatos *teste;

  teste = criaContatosVazia();

  int opcao =0;

  int boolean = 0;

do{
  menu(&opcao); //parametro deve ser ponteiro -> passamos o endereco, entao.

  switch (opcao) {
    case 1:
      printf("Opcao 1\n");
      getchar(); //para evitar que o programa pule o nome 
      teste = criaElemento();
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
