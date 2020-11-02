/*
* University of Brasilia - Brazil, UnB
* Software Engineering
* Created by Erick Giffoni Felicíssimo in 2020 .
* Copyright © 2020 Erick Giffoni Felicíssimo . All rights reserved.
*/

#include <stdio.h>

#define item int
#define tamanho 50000

int separa(item *v, int esq, int dir);
void quickSort(item *v, int esq, int dir);

int main()
{

    int vet[tamanho];
    int qtd_numeros = 0;

    while (scanf(" %d", &vet[qtd_numeros]) != EOF)
        qtd_numeros++; //ultimo indice, exclusive

    quickSort(vet, 0, qtd_numeros - 1);

    printf("%d", vet[0]);
    for (int i = 1; i < qtd_numeros; i++)
    {
        printf(" %d", vet[i]);
    }
    printf("\n");

    return 0;
}

int separa(item *v, int esq, int dir){
    item c = v[dir];
    int j = esq;
    for(int k=esq; k<dir; k++){
        if(v[k] <= c){
            item tmp = v[k];
            v[k] = v[j];
            v[j] = tmp;
            j++;
        }
    }//end for
    item tmp = v[j];
    v[j] = v[dir];
    v[dir] = tmp;
    return j;
}

void quickSort(item *v, int esq, int dir){
    if(dir<=esq) return;
    int j = separa(v, esq, dir);
    quickSort(v, esq, j-1);
    quickSort(v, j+1, dir);
}