#ifndef NEURON_H
#define NEURON_H

typedef struct neuron{
  double **w; //matriz de pesos
  double somatorio; //somatorio do produto interno(dot product): entrada * w
  double b; //escalar real
  double s; //saida do neuronio, apos aplicada a funcao logistica
} Neuron;//struct neuron

double exit_neuron(Neuron *, double **);//funcao para fazer todo o calculo dento do neuronio, chamando as outras abaixo - recebe o neuronio, a matriz de entrada, retorna a saida s
double logistic_function(double *);//recebe o resultado do dot_product + escalar b, retorna a saida s
double dot_product(double **, double **);//funcao do produto interno - recebe a matriz de entrada e a de pesos, retorna o somatorio dos dot products

#endif
