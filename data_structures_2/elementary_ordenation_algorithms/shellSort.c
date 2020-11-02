/*
* University of Brasilia - Brazil, UnB
* Software Engineering
* Created by Erick Giffoni Felicíssimo in 2020 .
* Copyright © 2020 Erick Giffoni Felicíssimo . All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define item int
#define tamanho 50000

void insertionSort_pace(item *v, int esq, int dir, int pace);
void shellSort(item *v, int esq, int dir);

int main(){

    srand(time(NULL));

    item vet[tamanho];
    for (int i = 0; i < tamanho; i++){
        vet[i] = rand();
        //printf("%d ", vet[i]);
    }
    //puts("\n");

    clock_t clicks = clock();
    shellSort(vet, 0, tamanho - 1);
    clicks = clock() - clicks;

    printf("\nVetor de tamanho %d\n", tamanho);
    printf("\nTempo de execucao shell sort: %f segundos\n\n", (float)clicks / CLOCKS_PER_SEC);

    //for (int i = 0; i < tamanho; i++){
    //    printf("%d ", vet[i]);
    //}
    //puts("\n");

    return 0;
}//end main

void insertionSort_pace(item *v, int esq, int dir, int pace)
{
    for (int i = esq + pace; i <= dir; i++)
    {
        int j = i;
        item tmp = v[j];
        while ((j>=esq+pace) && (tmp < v[j - pace]))
        {
            v[j] = v[j - pace];
            j-= pace; // j = j-pace
        }
        v[j] = tmp;
    }
} //end insertion sort with pace

void shellSort(item *v, int esq, int dir){
    int pace;
    for(pace=1; pace<= (dir-esq)/9; pace= 3*pace +1);//encontra a maior passada
    for(; pace>0; pace=pace/3)
        insertionSort_pace(v, esq, dir, pace);
}//end shell sort