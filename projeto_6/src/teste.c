#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../lib/neuron.h"

//compile: gcc teste.c ../lib../neuron.c -o teste

#define qtd_neurons 536
#define numero_de_imagens 100

int main(int argc, char **argv){
  srand(time(NULL));
  printf("Hello World!\nWe have a Neural Network here!!!\n\n");
  int number_of_neurons_hidden_layer = atoi(argv[1]);//numero de neuronios na camada oculta
  if(number_of_neurons_hidden_layer<1){
    printf("kidding me? not possible to have 0 neurons on hidden layer\n\n");
    return 0;
  }
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
    //fazer um vetor geral de treino com grama e asfalto
    double vet_treino_geral[numero_de_imagens/2][qtd_neurons+1];
    for(int i=0; i<(numero_de_imagens/2); i++){
      for(int j=0; j<qtd_neurons+1; j++){
        if(i<25) vet_treino_geral[i][j] = vet_treino_grama[i][j];
        else vet_treino_geral[i][j] = vet_treino_asfalto[i][j];
      }
    }//end for vet_treino_geral
  //variaveis importantes
  double *erros = (double *)calloc(numero_de_imagens/2, sizeof(double));//vetor de erros com 50 posicoes
  double erro_geral=1;//erro geral = sum(erros[i]^2)/50
  double limiar_do_erro_geral = 0.2;//erro_geral deve ser = ou menor que isso
  int numero_de_epocas=0;//vai de 0 a 1000, ou de 0 a x se erro_geral<=limiar_do_erro_geral
  double taxa_de_aprendizagem = 0.4625;//taxa de aprendizagem para a rede neural
  double *results_first_layer = (double *)calloc(qtd_neurons, sizeof(double));//vetor de resultados entre a 1 camada e a camada oculta
  double *results_hidden_layer = (double *)calloc(number_of_neurons_hidden_layer, sizeof(double));//vetor dos resultados da camada oculta com number_of_neurons_hidden_layer posicoes
  if(!erros) printf("main allocation ERROR: *erros failed\n\n");
  if(!results_first_layer) printf("main allocation ERROR: *results_first_layer failed\n\n");
  if(!results_hidden_layer) printf("main allocation ERROR: *results_hidden_layer failed\n\n");
  int counter = 0;
  int contador_de_erros=0;
  //treinar a rede neural
  do{
    //enviar a entrada para a primeira camada e salvar os resultados
    for(int i=0; i<qtd_neurons; i++){
      if(counter == (numero_de_imagens/2)) counter = 0;
      results_first_layer[i] = exit_neuron(first_layer[i], vet_treino_geral[array[counter]]);
      //printf("aqui %d\n\n", i);
    }
    //enviar os resultados anteriores para a camada escondida e salvar os novos resultados
    for(int i=0; i<number_of_neurons_hidden_layer; i++){
      results_hidden_layer[i] = exit_neuron(hidden_layer[i], results_first_layer);
    }
    //enviar os novos resultados para a ultima camada, calcular o erro e backpropagation
    last_layer->s = exit_neuron(last_layer, results_hidden_layer);
    if(contador_de_erros<(numero_de_imagens/2)) erros[contador_de_erros] = (vet_treino_geral[array[counter]][0] == 0) ? (last_layer->s) : (1 - last_layer->s);
    else {
      erro_geral = 0;
      contador_de_erros = 0;
      for(int i=0; i<(numero_de_imagens/2); i++){
        erro_geral += pow(erros[i],2);
      }
      erro_geral /= 50.0;
      printf("Accuracy on %d period was %.5lf\n\n", numero_de_epocas, erro_geral);
    }
    if(erro_geral<=limiar_do_erro_geral){
      break;
    }
    //printf("erro = %.5lf\n\n", erros[contador_de_erros]);
    //se numero_de_epocas%(numero_de_imagens/2)==0, calcular erro geral e verificar o limiar_do_erro_geral
    contador_de_erros++;
    numero_de_epocas+=1;
    counter++;
    if(numero_de_epocas % 50 == 0) printf("%d periods already done\n\n", numero_de_epocas);
  }while(numero_de_epocas<1000);
  printf("Training time : %d periods\n\nAccuracy reached : %.5lf\n\n", numero_de_epocas, erro_geral);
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
  free(results_first_layer);
  free(results_hidden_layer);
  return 0;
}
