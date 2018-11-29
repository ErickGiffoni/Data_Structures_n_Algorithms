#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../lib/neuron.h"

//compile: gcc main.c ../lib/neuron.c -o main

#define qtd_neurons 536
#define numero_de_imagens 100

int main(int argc, char **argv){
    srand(time(NULL));
    printf("Hello World!\nWe have a Neural Network here!!!\n\n");
    int number_of_neurons_hidden_layer = atoi(argv[1]);//numero de neuronios na camada oculta
    printf("numero de neuronios na camada oculta = %d\n", number_of_neurons_hidden_layer);
    printf("\n----------------------------------------------\n");
    //ler os vetores do arquivo ../projeto2/vetores_normalizados.txt
    double **vetores_normalizados = (double **)calloc(numero_de_imagens,sizeof(double*));//alocando as linhas da matriz de vetores do tamanho de numero_de_imagens
    for(int i=0; i<numero_de_imagens; i++){
      vetores_normalizados[i] = (double *)calloc(qtd_neurons,sizeof(double));//qtd_neurons colunas
    }//end for alocando as colunas
    FILE *arq_vet_norm = fopen("../projeto2/vetores_normalizados.txt", "r");//abre o arquivo para leitura
    if(!arq_vet_norm) printf("main ERROR: arq_vet_norm = NULL\n\n");
    else{
    for(int i=0; i<numero_de_imagens; i++){
      for(int j=0; j<qtd_neurons; j++){
        fscanf(arq_vet_norm, "%lf", &vetores_normalizados[i][j]);
      }//end for percorre colunas e le o numero no .txt
    }//end for percorre linhas
  }//end else arq_vet_norm != NULL
    //criando os arrays de camadas de neuronios
    Neuron **first_layer = (Neuron **)calloc(qtd_neurons,sizeof(Neuron*));//array de neuronios com qtd_neurons posicoes
    Neuron **hidden_layer = (Neuron **)calloc(number_of_neurons_hidden_layer,sizeof(Neuron *));//array de neuronios com number_of_neurons_hidden_layer posicoes
    Neuron *last_layer = new_neuron();//ultima camada e um unico neuronio
    for(int i=0; i<qtd_neurons; i++){
      first_layer[i] = new_neuron();
      if(!set_random_weight(first_layer[i], 536)) printf("main set_random_weight ERROR: return value <= 0\n\n");//preenche os pesos com valores aleatorios e retorna 0 se deu errado - 536 e o tamanho do vetor de pesos que queremos
      if(!set_random_bias(first_layer[i])) printf("main set_random_bias ERROR: return value <= 0\n\n");//da um valor aleatorio para o bias e retorna 0 se deu errado
    }//alocaao de neuronios na primeira camada
    for(int i=0; i<number_of_neurons_hidden_layer; i++){
      hidden_layer[i] = new_neuron();
      if(!set_random_weight(hidden_layer[i], 536)) printf("main set_random_weight ERROR: return value <= 0\n\n");//preenche os pesos com valores aleatorios e retorna 0 se deu errado - 536 e o tamanho do vetor de pesos que queremos
      if(!set_random_bias(hidden_layer[i])) printf("main set_random_bias ERROR: return value <= 0\n\n");//da um valor aleatorio para o bias e retorna 0 se deu errado
    }//alocaao de neuronios camada oculta


  
    //-----------------------------------------------------//
    //freeing elements
    for(int i=0; i<numero_de_imagens; i++){
      free(vetores_normalizados[i]);
    }//liberando vetores_normalizados da memoria
    for(int i=0; i<qtd_neurons; i++){
      free(first_layer[i]);
    }//liberando neuronios na primeira camada
    for(int i=0; i<number_of_neurons_hidden_layer; i++){
      free(hidden_layer[i]);
    }//liberando neuronios camada oculta
    free(last_layer);//liberando ultima camada
    return 0;
}
