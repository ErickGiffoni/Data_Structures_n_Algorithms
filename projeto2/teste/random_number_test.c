#include <stdio.h>
#include <stdlib.h>

int main(){

int array[50];
for(int i=0; i<50; i++){
  array[i] = i; //fill the array from 0 up to 49 -> 50 numbers
  //printf("%d\n", array[i]);
}

for(int i=0; i<50; i++){
  int temp = array[i];
  int random_index = rand() % 50; //random number from 0 up to 49

  //printf("%d\n", random_index);
  array[i] = array[random_index];
  array[random_index] = temp;
}

for(int i=0; i<50; i++) printf("Array[%d] = %d\n", i, array[i]);
//ideia : usar os valores das posicoes desse array para acessar as linhas dos vetores ILBP e os GLCM
  return 0;
}
