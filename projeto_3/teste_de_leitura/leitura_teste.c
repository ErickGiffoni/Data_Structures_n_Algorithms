/*  Programa teste para inicio do projeto 3 - leitura do arquivo contatos   */

#include <stdlib.h>
#include <stdio.h>

int main(){

  FILE *arquivo_contatos_txt;

  arquivo_contatos_txt = fopen("../contatos/contatos.txt", "r");

  if(!arquivo_contatos_txt) printf("Erro ao abrir o arquivo\n");

  char nome1[50];
  fscanf(arquivo_contatos_txt, "%[^\n]s", nome1);

  printf("%s\n", nome1);

  return 0;
}
