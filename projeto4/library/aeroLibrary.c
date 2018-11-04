#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aeroLibrary.h"


  Voo *criarVooNull(){
  return NULL;
}

  Voo *criarVoo(char *codigo_de_voo){
    Voo *temp;
    temp = (Voo *)malloc(sizeof(Voo));
    if(temp==NULL)printf("Alocacao temp criarVoo falhou\n");

    strcpy(temp->codigo_de_voo,codigo_de_voo);
    printf("%s\n\n\n",temp->codigo_de_voo);
    temp->proximo = NULL;
    return temp;
}

Voo *insereInicio(Voo *voo, Voo *novo_voo){
  novo_voo->proximo = voo;
  return novo_voo;
}

void imprimeVoos(Voo *voo){
  Voo *temp;
  temp = (Voo *)malloc(sizeof(Voo));
  if(temp==NULL)printf("erro ao alocar temp imprime\n" );

  temp = voo;
  while(temp->proximo!=NULL){
    printf("%s\n",temp->codigo_de_voo);
    temp = temp->proximo;
  }
}
