#ifndef AEROLIBRARY_H
#define AEROLIBRARY_H

// ! Implementacoes no aeroLibrary.c !

// ******* Estruturas *******
typedef struct voo{
  char codigo_de_voo[7] ; // ponteiro para um vetor de char, que e o codigo de voo alocado estaticamente na main
  char tipo; // D -> decolagem ; A -> aproximacao
  int combustivel; // se for do tipo aproximacao, tera um numero de combustivel : 0 e pouco e 12 e muito
  struct voo *proximo ; // proximo da fila de voos
}Voo;

typedef struct fila{
  Voo *primeiro; // ponteiro para Voo no inicio da fila, primeiro elemento a ser atendido
  Voo *ultimo; // ponteiro para Voo no final da fila, ultimo a ser atendido
}Fila;




// ******* Funcionalidades *******

Voo *criarVoo(char *);
//excluirVoo();
Voo *insereInicio(Voo *, Voo *);
void imprimeVoos(Voo *);
void randomizeModo(Voo *);
void randomizeNivelDeCombustivel(Voo *);

//criarFila();
//excluirFila();

#endif
