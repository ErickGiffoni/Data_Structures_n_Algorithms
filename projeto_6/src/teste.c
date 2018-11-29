#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../lib/neuron.h"

//compile: gcc teste.c ../lib../neuron.c -o teste

#define qtd_neurons 536
#define numero_de_imagens 100

int main(int argc, char **argv){
    srand(time(NULL));
    printf("Hello World!\n");
    int number_of_neurons_hidden_layer = atoi(argv[1]);//numero de neuronios na camada oculta
    printf("numero de neuronios na camada oculta = %d\n", number_of_neurons_hidden_layer);

    //testing dot_product and logistic_function
    double array1[537] = {20, 20,2,2,3,4,5,6,7};
    double array2[537] = {10,10};
    double somatorio = dot_product(array1, array2);//400
    printf("somatorio = %.5lf\n", somatorio);//400
    double saida = logistic_function(&somatorio);//1
    printf("saida = %.5lf\n", saida);//1
    //testing neuron.h
    printf("\n----------------------------------------------\n");
    //Neuron *neuron = new_neuron();
    //if(set_random_weight(neuron, 536)); /* definir o valor do peso dos neuronios aleatoriamente */
    //printf("peso do neuronio = %.2f\n", neuron->w[200]);
    //if(set_random_bias(neuron, 536)); /* definir o valor do escalar aleatoriamente */
    //printf("escalar do neuronio = %.2f\n", neuron->b);
    //neuron->s = exit_neuron(neuron, array1);
    //criando os arrays de camadas de neuronios
    //Neuron **first_layer = (Neuron **)calloc(qtd_neurons,sizeof(Neuron*));//array de neuronios com qtd_neurons posicoes
    //Neuron **hidden_layer = (Neuron **)calloc(number_of_neurons_hidden_layer,sizeof(Neuron *));//array de neuronios com number_of_neurons_hidden_layer posicoes
    //Neuron *last_layer = new_neuron();//ultima camada e um unico neuronio
    //for(int i=0; i<qtd_neurons; i++){
    //  first_layer[i] = new_neuron();
    //}//alocaao de neuronios na primeira camada
    //for(int i=0; i<number_of_neurons_hidden_layer; i++){
    //  hidden_layer[i] = new_neuron();
    //}//alocaao de neuronios camada oculta
    double **vetores_normalizados = (double **)calloc(numero_de_imagens,sizeof(double*));//alocando as linhas da matriz de vetores do tamanho de numero_de_imagens
    for(int i=0; i<numero_de_imagens; i++){
      vetores_normalizados[i] = (double *)calloc(qtd_neurons,sizeof(double));//qtd_neurons colunas
    }//end for alocando as colunas
    FILE *arq_vet_norm = fopen("../projeto2/vetores_normalizados.txt", "r");//abre o arquivo para leitura
    FILE *vet_test = fopen("vet_test.txt", "w");
    if(!arq_vet_norm) printf("main ERROR: arq_vet_norm = NULL\n\n");
    else{
    for(int i=0; i<numero_de_imagens; i++){
      for(int j=0; j<qtd_neurons; j++){
        fscanf(arq_vet_norm, "%lf", &vetores_normalizados[i][j]);
        fprintf(vet_test, "%.50lf ", vetores_normalizados[i][j]);
      }//end for percorre colunas e le o numero no .txt
      fprintf(vet_test, "\n");
    }//end for percorre linhas
  }//end else arq_vet_norm != NULL
    //-----------------------------------------------------//
    return 0;
}
