#ifndef NEURON_H
#define NEURON_H

#define qtd_neurons 536
#define numero_de_imagens 100

typedef struct neuron{
  double *w; //vetor de pesos
  double somatorio; //somatorio do produto interno(dot product): entrada * w
  double b; //escalar real
  double s; //saida do neuronio, apos aplicada a funcao logistica
} Neuron;//struct neuron

Neuron *new_neuron();//criar neuronio vazio
double exit_neuron(Neuron *, double *);//funcao para fazer todo o calculo dento do neuronio, chamando as outras abaixo - recebe o neuronio, o vetor de entrada, retorna a saida s
double logistic_function(double *);//recebe o resultado do dot_product + escalar b, retorna a saida s
double d_dx_logistic_function(double *);//derivada da logistica 
double dot_product(double *, double *);//funcao do produto interno - recebe o vetor de entrada e o de pesos, retorna o somatorio dos dot products
int set_random_weight(Neuron *, int); /* funcao para gerar valores aleatorios para o peso */
int set_random_bias(Neuron *); /* funcao para gerar valores aleatorios para o escalar */

#endif
