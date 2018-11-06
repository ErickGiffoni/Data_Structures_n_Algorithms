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

void randomizeModo(Voo *voo, int NAproximacoes){ //Seleciona o modo de Voo randomicamente
  Voo *temp;
  temp = (Voo *)malloc(sizeof(Voo));
  if(temp == NULL)printf("falha na alocacao temp randomize\n");


  int aux=1;
  temp = voo;
  while(temp!=NULL){
    if(aux <= NAproximacoes){
      temp->tipo = 'A';
      aux++;
    }
    else if(aux > NAproximacoes){
      temp->tipo = 'D';
      aux++;
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

void adicionaVooNaFila(Voo *novo_voo, Fila *fila){
  fila->ultimo->proximo = novo_voo;
  fila->ultimo = novo_voo;
  novo_voo->proximo = NULL;
}

void preencheFilas(Voo *voo, Fila *fila_de_aproximacao, Fila *fila_de_decolagem){
  int cont_aprox=0, cont_decol=0;
  Voo *percorre_voos = (Voo *) malloc(sizeof(Voo)); //alocaao dinamica de um auxuliar para percorrer a lista de voos
  if(percorre_voos == NULL) printf("Alocacao do percorre_voos falhou\n\n");

  //percorre_voos = voo; //aponta para a lista de voos

  for(percorre_voos = voo; voo!=NULL; ){
    //verificar o tipo e adicionar a fila correta, fazer percorre_voos = percorre_voos->proximo
      //tipo A
        if(voo->tipo == 'A'){
          percorre_voos = voo->proximo; //atualizacao do percorre_voos na lista
          cont_aprox++;
          //ja tem elemento na fila ?
            if(fila_de_aproximacao->primeiro == NULL){ //nao tem elemento na fila
              fila_de_aproximacao->primeiro = voo;
              voo->proximo = NULL;
              fila_de_aproximacao->ultimo = voo;
              //printf("Voo codigo na fila A = %s\n", voo->codigo_de_voo);

            } // end if nao tem elemento na fila
            else{ //tem elemento na fila
              adicionaVooNaFila(voo, fila_de_aproximacao);
              //printf("Voo codigo na fila A = %s\n", voo->codigo_de_voo);

            }// end else tem elemento na fila

        }//end if tipo A

      //tipo D
        else{
          percorre_voos = voo->proximo; //atualizacao do percorre_voos na lista
          cont_decol++;
          //ja tem elemento na fila ?
          if(fila_de_decolagem->primeiro == NULL){ //nao tem elemento na fila
            fila_de_decolagem->primeiro = voo;
            voo->proximo = NULL;
            fila_de_decolagem->ultimo = voo;
            //printf("Voo tipo = %c\n", voo->tipo);

          } // end if nao tem elemento na fila
          else{ //tem elemento na fila
            adicionaVooNaFila(voo, fila_de_decolagem);
            //printf("Voo codigo na fila D = %s\n", voo->codigo_de_voo);

          }// end else tem elemento na fila

        }//end else tipo D

    voo = percorre_voos; //atualiza o aux_percorre
  }// end for percorrer os voos
//printf("Cont aprox %d e cont decol %d\n", cont_aprox, cont_decol);
  free(percorre_voos);

}// end preencheFilas

void ordenaFila(int *NAproximacoes, Fila *fila_de_aproximacao){
  Voo * percorre_fila = (Voo*)malloc(sizeof(Voo)); //aux para percorrer a fila
  Voo * temporario = (Voo*)calloc(1,sizeof(Voo)); //temporario para salvar conteudos

  if(percorre_fila==NULL) printf("Aux percorre_fila na ordenacao foi null\n\n"); //alocacao
  if(temporario==NULL) printf("Aux temporario na ordenacao foi null\n\n"); //alocacao

  //percorre_fila = fila_de_aproximacao->primeiro; //aponta para o primeiro da fila
  for(int i=0; i< *NAproximacoes; i++){
    for(percorre_fila = fila_de_aproximacao->primeiro; percorre_fila->proximo!=NULL; percorre_fila=percorre_fila->proximo){
      if(percorre_fila->combustivel > percorre_fila->proximo->combustivel){
        //copiar os dados para o temporario
        strcpy(temporario->codigo_de_voo, percorre_fila->codigo_de_voo);
        temporario->tipo = percorre_fila->tipo;
        temporario->combustivel = percorre_fila->combustivel;

        //trocar dados do percorre_fila com o percorre_fila->proximo
        strcpy(percorre_fila->codigo_de_voo, percorre_fila->proximo->codigo_de_voo);
        percorre_fila->tipo = percorre_fila->proximo->tipo;
        percorre_fila->combustivel = percorre_fila->proximo->combustivel;

        //atualizar o percorre_fila->proximo
        strcpy(percorre_fila->proximo->codigo_de_voo, temporario->codigo_de_voo);
        percorre_fila->proximo->tipo = temporario->tipo;
        percorre_fila->proximo->combustivel = temporario->combustivel;

      }//end if ordena combustiveis , troca conteudos
      else{
        continue;
      }
    }// end for percorre fila
  }//end for NAproximacoes vezes
  free(percorre_fila);
  free(temporario);
}//end ordenaFila
