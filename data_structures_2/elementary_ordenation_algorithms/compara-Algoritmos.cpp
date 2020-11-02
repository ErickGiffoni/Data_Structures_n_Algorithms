/*
* University of Brasilia - Brazil, UnB
* Software Engineering
* Created by Erick Giffoni Felicíssimo on Aug 21 2020 .
* Copyright © 2020 Erick Giffoni Felicíssimo . All rights reserved.
*
* Esse programa compara o tempo de execucao entre implementacoes
* dos algoritmos selection sort, buble sort, insertion sort, para um
* vetor de tamanho x contendo elementos do tipo y.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define item int

void selectionSort_recursiva(item *v, int esq, int dir); // vetor v, indice esquerda, indice direita
void selectionSort(item *v, int esq, int dir); // implementacao nao-recursiva
void insertionSort(item *v, int esq, int dir);
void insertionSort_pace(item *v, int esq, int dir, int pace);
void shellSort(item *v, int esq, int dir);
void bubleSort(item *v, int esq, int dir);

int main(){
    
    srand(time(NULL));

    int tamanho = 1000;
    item v[tamanho];
    for(int i=0; i<tamanho; i++){
        v[i] = rand();
    }

    clock_t clicksRecursiva = clock(); // referencia: https://www.cplusplus.com/reference/ctime/clock/
    selectionSort_recursiva(v, 0, tamanho-1);
    clicksRecursiva = clock() - clicksRecursiva;

    //embaralhar o vetor novamente
    for (int i = 0; i < tamanho; i++){
        v[i] = rand();
    }
    //--------------------------------//

    clock_t clicksNaoRecursiva = clock();
    selectionSort(v, 0, tamanho-1);
    clicksNaoRecursiva = clock() - clicksNaoRecursiva;

    printf("\nVetor de tamanho %d\n", tamanho);
    printf("\nTempo de execucao da recursiva: %f segundos\n\n", (float)clicksRecursiva/CLOCKS_PER_SEC);
    printf("Tempo de execucao da NAO-recursiva: %f segundos\n\n", (float)clicksNaoRecursiva/CLOCKS_PER_SEC);

    return 0;
}

void selectionSort_recursiva(item *v, int esq, int dir){
    if(esq >= dir) return ;
    int menor = esq;
    item temp; // temporario
    for(int i=menor+1; i<=dir; i++){
        if(v[i] < v[menor]) menor = i;
    }
    if(menor != esq){
        temp = v[menor];
        v[menor] = v[esq];
        v[esq] = temp;
    }
    selectionSort_recursiva(v, esq+1, dir);
}//end selectionSort_recursiva

void selectionSort(item *v, int esq, int dir){
    for(int j=esq; j<dir; j++){
        int menor = j;
        item temp; // temporario
        for (int i = menor + 1; i <= dir; i++){
            if (v[i] < v[menor])
                menor = i;
        }
        if (menor != esq){
            temp = v[menor];
            v[menor] = v[esq];
            v[esq] = temp;
        }
    }// end for j
}// end selectionSort

void insertionSort(item *v, int esq, int dir){
    for (int i = dir; i > esq; i--)
    {
        if (v[i] < v[i - 1])
        {
            item tmp = v[i];
            v[i] = v[i - 1];
            v[i - 1] = tmp;
        }
    }
    for (int i = esq + 2; i <= dir; i++)
    {
        //note que a condicao inicial de i pressupõe que o vetor tem pelo menos 3 posicoes
        int j = i;
        item tmp = v[j];
        while (tmp < v[j - 1])
        {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = tmp;
    }
} //end insertion sort

void insertionSort_pace(item *v, int esq, int dir, int pace)
{
    for (int i = esq + pace; i <= dir; i++)
    {
        int j = i;
        item tmp = v[j];
        while ((j >= esq + pace) && (tmp < v[j - pace]))
        {
            v[j] = v[j - pace];
            j -= pace; // j = j-pace
        }
        v[j] = tmp;
    }
} //end insertion sort with pace

void shellSort(item *v, int esq, int dir)
{
    int pace;
    for (pace = 1; pace <= (dir - esq) / 9; pace = 3 * pace + 1)
        ; //encontra a maior passada
    for (; pace > 0; pace = pace / 3)
        insertionSort_pace(v, esq, dir, pace);
} //end shell sort

void bubleSort(item *v, int esq, int dir){
    return;
}//end buble sort