#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "aeroLibrary.h"



  Voo *criarVoo(char *codigo_de_voo){ //Cria nova Struct voo
    Voo *temp;
    temp = (Voo *)malloc(sizeof(Voo));
    if(temp==NULL)printf("Alocacao temp criarVoo falhou\n");

    strcpy(temp->codigo_de_voo,codigo_de_voo);
    //printf("%s\n\n\n",temp->codigo_de_voo);
    temp->proximo = NULL;
    return temp;
}

Voo *insereInicio(Voo *voo, Voo *novo_voo){ //Recebe dois elementos da struct Voo e os ordena em uma Lista
  novo_voo->proximo = voo;
  return novo_voo;
}

void imprimeVoos(Voo *voo){
  Voo *temp;
  temp = (Voo *)malloc(sizeof(Voo));
  if(temp==NULL)printf("erro ao alocar temp imprime\n" );

  temp = voo;
  while(temp!=NULL){
    printf("%s\n",temp->codigo_de_voo);
    printf("%c\n",temp->tipo);
    printf("%d\n",temp->combustivel);
    printf("\n\n");
    temp = temp->proximo;
  }
  free(temp);
}

void randomizeModo(Voo *voo){ //Seleciona o modo de Voo randomicamente
  Voo *temp;
  temp = (Voo *)malloc(sizeof(Voo));
  if(temp == NULL)printf("falha na alocacao temp randomize\n");

  srand( (unsigned)time(NULL) );
  int aux;
  temp = voo;
  while(temp!=NULL){
    aux = rand() % 2;
    if(aux == 0){
      temp->tipo = 'A';
    }
    else if(aux == 1){
      temp->tipo = 'D';
    }
    temp = temp->proximo;
  }
  free(temp);
}

void randomizeNivelDeCombustivel(Voo *voo){
  Voo *temp;
  temp = (Voo *)malloc(sizeof(Voo));
  if(temp == NULL)printf("falha na alocacao temp randomize de combustivel\n");
  temp = voo;

  srand( (unsigned)time(NULL) );
  int aux;
  while (temp!=NULL) {
    if(temp->tipo == 'A'){
      aux = rand() % 13;
      temp->combustivel = aux;
      temp = temp->proximo;
    }
    else{
      temp = temp->proximo;
    }
  }
  free(temp);
}
