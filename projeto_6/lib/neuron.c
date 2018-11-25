#include "neuron.h"
#include <math.h>

double exit_neuron(Neuron *n, double *p){//funcao para fazer todo o calculo dento do neuronio, chamando as outras abaixo - recebe o neuronio, o vetor de entrada, retorna a saida s
  return 0;
}//end of exit_neuron

double logistic_function(double *somatorio){
  return 1.0/(1.0 + exp(-(*somatorio)));
}//end of logistic_function

double dot_product(double *p, double *w){//funcao do produto interno - recebe o vetor de entrada e o de pesos, retorna o somatorio dos dot products
  double somatorio = 0.0;
  for(int i=0; i<537; i++){//dot product
    somatorio += (p[i] * w[i]);
  }//end of for dot product
  return somatorio;
}//end of dot_product
