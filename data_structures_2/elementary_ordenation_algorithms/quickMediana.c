/*
* University of Brasilia - Brazil, UnB
* Software Engineering
* Created by Erick Giffoni Felicíssimo in 2020 .
* Copyright © 2020 Erick Giffoni Felicíssimo . All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>

#define item int

int separa(item *v, int esq, int dir);
void quickSortMediana(item *v, int esq, int dir);

int main()
{

    int tamanho;
    scanf(" %d", &tamanho);

    item *vet = (item *) calloc(tamanho, sizeof(item));

    for(int i=0; i<tamanho; i++){
        scanf(" %d", &vet[i]);
    }

    quickSortMediana(vet, 0, tamanho - 1);

    printf("%d", vet[0]);
    for (int i = 1; i < tamanho; i++)
    {
        printf(" %d", vet[i]);
    }
    printf("\n");

    return 0;
}

int separa(item *v, int esq, int dir)
{
    item c = v[dir];
    int j = esq;
    for (int k = esq; k < dir; k++)
    {
        if (v[k] <= c)
        {
            item tmp = v[k];
            v[k] = v[j];
            v[j] = tmp;
            j++;
        }
    } //end for
    item tmp = v[j];
    v[j] = v[dir];
    v[dir] = tmp;
    return j;
}

void quickSortMediana(item *v, int esq, int dir)
{
    if (dir <= esq)
        return;

    if(v[dir] < v[(dir+esq)/2]){
        item tmp = v[dir];
        v[dir] = v[(dir + esq) / 2];
        v[(dir + esq) / 2] = tmp;
    }

    if (v[(dir + esq) / 2] < v[esq]){
        item tmp = v[(dir + esq) / 2];
        v[(dir + esq) / 2] = v[esq];
        v[esq] = tmp;
    }

    if (v[(dir + esq) / 2] < v[dir]){
        item tmp = v[(dir + esq) / 2];
        v[(dir + esq) / 2] = v[dir];
        v[dir] = tmp;
    }

    int j = separa(v, esq, dir);
    quickSortMediana(v, esq, j - 1);
    quickSortMediana(v, j + 1, dir);
}