/*
* University of Brasilia - Brazil, UnB
* Software Engineering
* Created by Erick Giffoni Felicíssimo in 2020 .
* Copyright © 2020 Erick Giffoni Felicíssimo . All rights reserved.
*/

#include <stdio.h>

#define item int
#define tamanho 50000

void insertionSort(int *v, int esq, int dir);

int main(){

    int vet[tamanho];
    int qtd_numeros = 0;

    while(scanf(" %d", &vet[qtd_numeros]) != EOF)
        qtd_numeros++; //ultimo indice, exclusive

    insertionSort(vet, 0, qtd_numeros-1);

    printf("%d", vet[0]);
    for(int i=1; i<qtd_numeros; i++){
        printf(" %d", vet[i]);
    }
    printf("\n");

    return 0;
}

void insertionSort(int *v, int esq, int dir){
    for(int i=dir; i>esq; i--){
        if(v[i]<v[i-1]){
            int tmp = v[i];
            v[i] = v[i-1];
            v[i-1] = tmp;
        }
    }
    for(int i=esq+2; i<=dir; i++){
        //note que a condicao inicial de i pressupõe que o vetor tem pelo menos 3 posicoes
        int j=i;
        int tmp = v[j];
        while(tmp<v[j-1]){
            v[j] = v[j-1];
            j--;
        }
        v[j] = tmp;
    }
}//end insertion sort