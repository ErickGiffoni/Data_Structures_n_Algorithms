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

double d_dx_logistic_function(double *value){//derivada da logistica
  return exp(*value)/( pow( (exp(*value)+1) , 2) );//e^x / (e^x + 1)^2
}//end of d_dx_logistic_function

double dot_product(double *p, double *w){//funcao do produto interno - recebe o vetor de entrada e o de pesos, retorna o somatorio dos dot products
  double somatorio = 0.0;
  for(int i=1; i<qtd_neurons+1; i++){//dot product
    somatorio += (p[i] * w[i-1]);
  }//end of for dot product
  return somatorio;
}//end of dot_product

int set_random_weight(Neuron *n ,int value)
{
  if(!n)
  {
    printf("set_random_weight ERROR: cannot allocate memory to value\n");
    return 0;//false
  }//end if
  else{
  n->w = (double *) calloc(value, sizeof(double)); /* value e um valor dinamico no caso para alocar 536 posições */
/* se o neuronio não existe então nao tem como alocar o peso */
  for(int i = 0; i < value; i++)
  {
    double random_num = (rand() % 32767) - 16384; /* pega o limite maximo e mínimo para determinar os valores randomicos */
    n->w[i] = random_num;
    //if(n->w[i] == 0)printf("ZEEEEEEEEERRRRRRROOOOOOOOOO\n\n\n");
    //printf("n->w[i] = %lf\n\n", n->w[i]);
  }
  return 1;//true
}//end else
}//end of set_random_weight

int set_random_bias(Neuron *n)
{
  if(!n)
  {
    printf("set_random_bias ERROR: cannot allocate memory to value\n");
    return 0;
  }
  n->b = (rand() % 32767) - 16384; /* pega o limite maximo e mínimo para determinar os valores randomicos */

  return 1;
}//end of set_random_bias
