#include "contatos.h"

void menu(int *opcao){
  printf("\t\t\t***** MENU *****\nPor favor, digite o numero da opcao desejada:\n");
  printf("\t1- Inserir novo registro ;\n");
  printf("\t2- Remover registro que contenha certa string no nome ;\n");
  printf("\t3- Visualizar registro que contenha certa string no nome ;\n");
  printf("\t4- Visualizar todos os registros, em ordem alfabetica, de acordo com o nome ;\n");
  printf("\t5- Sair ;\n\n");
  printf("Opcao : ");
  scanf("%d", opcao);

}//end menu

FILE *criaArquivoContatos_txt(){

}//end criaArquivoContatos_txt

Contatos *criaContatosVazia(){
  return NULL;

}// end criaContatosVazia

Contatos *criaElemento(){
  Contatos *temp;
  temp = (Contatos *)malloc(sizeof(Contatos));
  if(temp==NULL)printf("ALOCACAO FALHOU!\n");

  printf("Informe o nome nome_completo\n");
  scanf("%[^\n]", temp -> nome_completo);
  getchar();

  printf("Informe o número de celular\n");
  scanf("%[^\n]", temp -> celular );
  getchar();


  printf("Informe o endereco\n");
  scanf("%[^\n]", temp -> endereco);
  getchar();

  unsigned int aux=0;

  printf("Informe o CEP\n");
  scanf("%u", &aux);
  temp -> CEP = (unsigned int)aux;
  getchar();

  printf("Informe a data de nascimento\n");
  fgets(temp -> data_de_nascimento, sizeof(temp -> data_de_nascimento), stdin);

  return temp;

}// end criaElemento

Contatos *adicionaContatosDoArquivo(FILE *ponteiroParaArquivo){

}// end adicionaContatosDoArquivo

void liberaContatos(Contatos *contatos){

}// end liberaContatos

int inserirNovoContato(Contatos *ondeInserir){

}// end inserirNovoContato

int removerContatosPorString(char *stringParaRemover, Contatos *deOndeRemover){

}// end removerContatosPorString

Contato *visualizarContatosPorString(char *stringInformada, Contatos *ondePesquisar){

}// end visualizarContatosPorString

void visualizarTodosOsContatos(Contatos *primeiroContato){

}// end visualizarTodosOsContatos

void sair(){

}// end sair

Contatos *insertionSort(Contatos *contato){

}// end insertionSort
