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

Fila *criaFila(){
  Fila *fila = (Fila *) malloc(sizeof(Fila));
  if(fila == NULL) printf("Criacao da fila falhou\n\n");
  fila->primeiro = NULL;
  fila->ultimo = NULL;
  return fila;
}

void adicionaVooNaFila(Voo *novo_voo, Voo *ultimo){
  ultimo->proximo = novo_voo;
  ultimo = novo_voo;
  novo_voo->proximo = NULL;
}

void preencheFilas(Voo *voo, Fila *fila_de_aproximacao, Fila *fila_de_decolagem){
  Voo *percorre_voos = (Voo *) malloc(sizeof(Voo)); //alocaao dinamica de um auxuliar para percorrer a lista de voos
  Voo *aux_percorre = (Voo *) malloc(sizeof(Voo)); //alocaao dinamica de um auxuliar para apontar para o percorre_voos
  if(percorre_voos == NULL) printf("Alocacao do percorre_voos falhou\n\n");
  if(aux_percorre == NULL) printf("Alocacao do aux do percorre_voos falhou\n\n");

  //percorre_voos = voo; //aponta para a lista de voos

  for(percorre_voos = voo; voo!=NULL; ){
    //verificar o tipo e adicionar a fila correta, fazer percorre_voos = percorre_voos->proximo
      //tipo A
        if(voo->tipo == 'A'){
          percorre_voos = voo->proximo; //atualizacao do percorre_voos na lista

          //ja tem elemento na fila ?
            if(fila_de_aproximacao->primeiro == NULL){ //nao tem elemento na fila
              fila_de_aproximacao->primeiro = voo;
              voo->proximo = NULL;
              fila_de_aproximacao->ultimo = voo;
              //printf("Voo tipo = %c\n", voo->tipo);

            } // end if nao tem elemento na fila
            else{ //tem elemento na fila
              adicionaVooNaFila(voo, fila_de_aproximacao->ultimo);
              //printf("Voo codigo na fila A = %s\n", voo->codigo_de_voo);

            }// end else tem elemento na fila

        }//end if tipo A

      //tipo D
        else{
          percorre_voos = voo->proximo; //atualizacao do percorre_voos na lista

          //ja tem elemento na fila ?
          if(fila_de_decolagem->primeiro == NULL){ //nao tem elemento na fila
            fila_de_decolagem->primeiro = voo;
            voo->proximo = NULL;
            fila_de_decolagem->ultimo = voo;
            //printf("Voo tipo = %c\n", voo->tipo);

          } // end if nao tem elemento na fila
          else{ //tem elemento na fila
            adicionaVooNaFila(voo, fila_de_decolagem->ultimo);
            //printf("Voo codigo na fila D = %s\n", voo->codigo_de_voo);

          }// end else tem elemento na fila

        }//end else tipo D

    voo = percorre_voos; //atualiza o aux_percorre
  }// end for percorrer os voos

}// end preencheFilas
