/*
* University of Brasilia - Brazil, UnB
* Software Engineering
* Created by Erick Giffoni Felicíssimo in 2020 .
* Copyright © 2020 Erick Giffoni Felicíssimo . All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>

#define item int

void mergeSort(item *vet, int esq, int dir);
void merge(item *vet, int esq, int meio, int dir);

int main()
{

    int tamanho;
    scanf(" %d", &tamanho);

    item *vet = (item *)calloc(tamanho, sizeof(item));

    for (int i = 0; i < tamanho; i++)
    {
        scanf(" %d", &vet[i]);
    }

    mergeSort(vet, 0, tamanho - 1);

    printf("%d", vet[0]);
    for (int i = 1; i < tamanho; i++)
    {
        printf(" %d", vet[i]);
    }
    printf("\n");

    return 0;
}

void mergeSort(item *vet, int esq, int dir){
    if(esq >= dir) return;
    int meio = (dir+esq)/2;
    mergeSort(vet, esq, meio);
    mergeSort(vet, meio+1, dir);
    merge(vet, esq, meio, dir);
}

void merge(item *vet, int esq, int meio, int dir){
    item *aux = (item *) calloc((dir-esq+1), sizeof(item));
    int k=0, i=esq, j=meio+1;
    while(i <= meio && j <= dir){
        if(vet[i] <= vet[j]) //assim fica estavel
            aux[k++] = vet[i++];
        else 
            aux[k++] = vet[j++];
    }
    while(i<=meio)
        aux[k++] = vet[i++];
    while(j<=dir)
        aux[k++] = vet[j++];
    
    k=0;
    for(i=esq; i<=dir; i++)
        vet[i] = aux[k++];
    
    free(aux);
}