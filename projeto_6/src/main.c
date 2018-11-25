#include <stdio.h>
#include <stdlib.h>
#include "../lib/neuron.h"

//compile: gcc main.c ../lib../neuron.c -o main

int main(int argc, char **argv){
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
    Neuron *neuron = new_neuron();
    //neuron->w = [23,12,13,14,45,6,7,32,45]; // nao da certo
    neuron->s = exit_neuron(neuron, array1);
    //-----------------------------------------------------//
    return 0;
}
