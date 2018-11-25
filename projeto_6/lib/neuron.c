#include "neuron.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

Neuron *new_neuron(){//criar neuronio vazio
  Neuron *n = (Neuron *)calloc(1, sizeof(Neuron));
  if(!n){
    printf("new_neuron ERROR: *n = NULL\n\n");
    return NULL;
  }//verifica se deu certo a alocacao do neuronio
  return n;
}// end of new_neuron

double exit_neuron(Neuron *n, double *p){//funcao para fazer todo o calculo dento do neuronio, chamando as outras abaixo - recebe o neuronio, o vetor de entrada, retorna a saida s
  if(!n){
    printf("exit_neuron ERROR: passing null neuron \n\n");
    return -1;
  }//verifica se o neuronio e nulo
  if(!p){
    printf("exit_neuron ERROR: passing null array p \n\n");
    return -1;
  }//verifica se o vetor de entrada e nulo
  if(!n->w){
    printf("exit_neuron ERROR: array w in n->w = NULL \n\n");
    return -1;
  }//verifica se o vetor de pesos e nulo
  n->somatorio = dot_product(p,n->w);
  n->somatorio += n->b; //soma o escalar b ao somatorio
  n->s = logistic_function(&n->somatorio);
  return n->s; //retorna o valor da saida
}//end of exit_neuron

double logistic_function(double *somatorio){
  return 1.0/(1.0 + exp(-(*somatorio)));
}//end of logistic_function

double dot_product(double *p, double *w){//funcao do produto interno - recebe o vetor de entrada e o de pesos, retorna o somatorio dos dot products
  double somatorio = 0.0;
  for(int i=1; i<537; i++){//dot product
    somatorio += (p[i] * w[i-1]);
  }//end of for dot product
  return somatorio;
}//end of dot_product
