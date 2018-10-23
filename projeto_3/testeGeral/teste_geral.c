#include <stdio.h>
#include <stdlib.h>

#include "../biblioteca/contatos.h"



int main(){

  FILE *ponteiroParaArq;
  Contatos *contatos;
  contatos = (Contatos *)malloc(sizeof(Contatos));

  contatos = adicionaContatosDoArquivo(ponteiroParaArq);
  if(contatos == NULL){
    printf("Erro ao abrir o arquivo\n");
    //exit(-3);
    //criar novo arquivo
    ponteiroParaArq = criaArquivoContatos_txt();
  }

  char stringParaRemover[101];
  char stringInformada[101];

  int opcao =0;

  int boolean = 0;

do{
  menu(&opcao); //parametro deve ser ponteiro -> passamos o endereco, entao.

  switch (opcao) {
    case 1:
      printf("Opcao 1\n");
      getchar(); //para evitar que o programa pule o nome
      contatos = inserirNovoRegistro(contatos);
      if(contatos == NULL){
        printf("Nao foi possivel inserir novo registro. Tente novamente\n\n");
        getchar();
        getchar();
      }
      break;
    case 2:
      printf("Opcao 2 : Informe o nome a ser removido\n");
      getchar();
      scanf("%[^\n]", stringParaRemover);
      getchar();
      int remocao;
      remocao = removerContatosPorString(stringParaRemover, contatos);
      if(remocao){
        printf("Nome(s) removido(s) com sucesso!!!\n");
        getchar();
      }
      //boolean = 1;
      break;
    case 3:
      printf("Opcao 3 : Informe o nome a ser pesquisado\n");
      getchar();
      scanf("%[^\n]", stringInformada);
      getchar();
      visualizarContatosPorString(stringInformada, contatos);
      getchar();
      //boolean = 1;
      break;
    case 4:
      printf("Opcao 4 : Mostrando todos os contatos...\n");
      visualizarTodosOsContatos(contatos);
      //boolean = 1;
      break;
    case 5:
      printf("Opcao 5 : OBRIGADO, VOLTE SEMPRE\n"); // implementar a saida do programa
      sair(ponteiroParaArq, contatos);
      boolean = 1;
      break;
    default:
      fflush(stdin);
      opcao = 0; // erro : laco infinito se o usuario digitar algo nao numerico (letra por exemplo)
      printf("Opcao invalida, tente novamente.\n\n\n\n");
  }

}while(!boolean);

fclose(ponteiroParaArq);

  return 0;
}
