#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../lib/neuron.h"

//compile: gcc main.c ../lib/neuron.c -o main

int main(int argc, char **argv){
    srand(time(NULL));
    printf("Hello World!\nWe have a Neural Network here!!!\n\n");
    int number_of_neurons_hidden_layer = atoi(argv[1]);//numero de neuronios na camada oculta
    printf("numero de neuronios na camada oculta = %d\n", number_of_neurons_hidden_layer);
    printf("\n----------------------------------------------\n");
    //ler os vetores do arquivo ../projeto2/vetores_normalizados.txt
    double **vetores_normalizados = (double **)calloc(numero_de_imagens,sizeof(double*));//alocando as linhas da matriz de vetores do tamanho de numero_de_imagens
    for(int i=0; i<numero_de_imagens; i++){
      vetores_normalizados[i] = (double *)calloc(qtd_neurons+1,sizeof(double));//qtd_neurons colunas
    }//end for alocando as colunas
    FILE *arq_vet_norm = fopen("../projeto2/vetores_normalizados.txt", "r");//abre o arquivo para leitura
    if(!arq_vet_norm) printf("main ERROR: arq_vet_norm = NULL\n\n");
    else{
    for(int i=0; i<numero_de_imagens; i++){
      if(i<50) vetores_normalizados[i][0] = 1;//primeira posicao dos gramas tem valor 1
      for(int j=1; j<qtd_neurons+1; j++){
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
    //Escolher, para cada classe, 25 vetores treino aleatorios
    double vet_treino_grama[numero_de_imagens/4][qtd_neurons+1];
    double vet_treino_asfalto[numero_de_imagens/4][qtd_neurons+1];
    //CRIACAO ARRAY AUXILIAR COM NUMEROS ALEATORIOS DE 0 À 49.
        int array[numero_de_imagens/2];
          for(int i=0; i<numero_de_imagens/2; i++){
          array[i] = i; //fill the array from 0 up to 49 -> 50 numbers
      //printf("%d\n", array[i]);
    }//end for array auxiliar
    for(int i=0; i<numero_de_imagens/2; i++){
        int temp = array[i];
        int random_index = rand() % (numero_de_imagens/2); //random number from 0 up to 49

        //printf("%d\n", random_index);
        array[i] = array[random_index];
        array[random_index] = temp;
      }//end for embaralha array auxiliar
      for(int i=0; i<(numero_de_imagens/4); i++){//pegar 25 de grama aleatorios p treino
        for(int j=0; j<qtd_neurons+1; j++){
          vet_treino_grama[i][j] = vetores_normalizados[array[i]][j];//linha array[i] e um nuemro aleatorio de 0 a 49
        }
      }//end for pegar 25 de grama aleatorios p treino
      for(int i=0; i<(numero_de_imagens/4); i++){//pegar 25 de asfalto aleatorios p treino
        for(int j=0; j<qtd_neurons+1; j++){
          vet_treino_asfalto[i][j] = vetores_normalizados[array[i+(numero_de_imagens/4)]+(numero_de_imagens/2)][j];//linha array[i+(numero_de_imagens/4)]+(numero_de_imagens/2) e um numero aleatorio de 50 a 99
        }
      }//end for pegar 25 de asfalto aleatorios p treino
    //variaveis importantes
    double *erros = (double *)calloc(numero_de_imagens/2, sizeof(double));//vetor de erros com 50 posicoes
    double erro_geral=1;//erro geral = sum(erros[i]^2)/50
    double limiar_do_erro_geral = 0.2;//erro_geral deve ser = ou menor que isso
    int numero_de_epocas=0;//vai de 0 a 1000, ou de 0 a x se erro_geral<=limiar_do_erro_geral
    double taxa_de_aprendizagem = 0.45;//taxa de aprendizagem para a rede neural
    //treinar a rede neural
    //do{

    //  numero_de_epocas+=1;
    //}while(numero_de_epocas<=1000 || erro_geral>limiar_do_erro_geral);
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
    free(erros);//liberando vetor de erros
    return 0;
}
