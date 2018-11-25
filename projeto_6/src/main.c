#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    printf("Hello World!\n");
    int number_of_neurons_hidden_layer = atoi(argv[1]);//numero de neuronios na camada oculta
    printf("numero de neuronios na camada oculta = %d\n", number_of_neurons_hidden_layer);
    return 0;
}
