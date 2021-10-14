/*
* Erick Giffoni - 170141161
* kk-página
* 02/10/2020
*/

#include <stdio.h>
#include <stdlib.h>

int separa(int *v, int esq, int dir);
void quickSortMediana(int *v, int esq, int dir);
void quickSelect(int *v, int esq, int dir, int k){
    if(dir<=esq){
        return;
    }
    int i = separa(v, esq, dir);
    if(i>k){
        quickSelect(v, esq, i-1, k);
    }
    if(i<k){
        quickSelect(v, i+1, dir, k);
    }
}
//void imprimeID(int *v, int indice, int x, int n);
//void mergeSort(int *vet, int esq, int dir, int k);
//void mergeSortPadrao(int *vet, int esq, int dir);
//void merge(int *vet, int esq, int meio, int dir);
//int solve(int *vet, int esq, int dir, int k)
//{
//    int j;
//    while (esq < dir)
//    {
//        j = separa(vet, esq, dir);
//        if (k == j)
//            return j;
//        if (k > j)
//            dir = j;
//        else
//            esq = j;
//    }
//}

int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}//end compare

int main()
{

    int n, p, x; // qtd produtos, pagina, qtd prod por pagina
    scanf(" %d", &n);
    scanf(" %d", &p);
    scanf(" %d", &x);

    int *id = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &id[i]);
    }
    
    //qsort(id, n, sizeof(int), compare);

    //for(int i=0; i<x; i++){
        quickSelect(id, 0, n-1, (p*x));
        quickSelect(id, (p*x)+1, n-1, (p*x)+x-1);
        quickSortMediana(id, (p*x)+1, (p*x)+x-1-1);
    //}

    //puts("");
    //for (int i = 0; i < n; i++)
    //{
    //    printf("%d ", id[i]);
    //}
    //puts("");

    int count = 1;
    for(int i = x*p; count <= x && i<n; i++){
        printf("%d\n", id[i]);
        count++;
    }

    //for (int i = 0; i < x; i++)
    //    quickSelect(id, 0, n - 1, (x * p) + i);
    ////mergeSortPadrao(id, (x*p), (x*p)+x);
    //imprimeID(id, (x * p), x, n);

    free(id);
    return 0;
}//end main

int separa(int *v, int esq, int dir)
{
    int c = v[dir];
    int j = esq;
    for (int k = esq; k < dir; k++)
    {
        if (v[k] <= c)
        {
            int tmp = v[k];
            v[k] = v[j];
            v[j] = tmp;
            j++;
        }
    } //end for
    int tmp = v[j];
    v[j] = v[dir];
    v[dir] = tmp;
    return j;
}
//
void quickSortMediana(int *v, int esq, int dir)
{
    if (dir <= esq)
        return;

    if (v[dir] < v[(dir + esq) / 2])
    {
        int tmp = v[dir];
        v[dir] = v[(dir + esq) / 2];
        v[(dir + esq) / 2] = tmp;
    }

    if (v[(dir + esq) / 2] < v[esq])
    {
        int tmp = v[(dir + esq) / 2];
        v[(dir + esq) / 2] = v[esq];
        v[esq] = tmp;
    }

    if (v[(dir + esq) / 2] < v[dir])
    {
        int tmp = v[(dir + esq) / 2];
        v[(dir + esq) / 2] = v[dir];
        v[dir] = tmp;
    }

    int j = separa(v, esq, dir);
    quickSortMediana(v, esq, j - 1);
    quickSortMediana(v, j + 1, dir);
}
//
//void quickSelect(int *v, int esq, int dir, int k)
//{
//    if (dir <= esq)
//        return;
//    //mediana de 3
//    if (v[dir] < v[(dir + esq) / 2])
//    {
//        int tmp = v[dir];
//        v[dir] = v[(dir + esq) / 2];
//        v[(dir + esq) / 2] = tmp;
//    }
//
//    if (v[(dir + esq) / 2] < v[esq])
//    {
//        int tmp = v[(dir + esq) / 2];
//        v[(dir + esq) / 2] = v[esq];
//        v[esq] = tmp;
//    }
//
//    if (v[(dir + esq) / 2] < v[dir])
//    {
//        int tmp = v[(dir + esq) / 2];
//        v[(dir + esq) / 2] = v[dir];
//        v[dir] = tmp;
//    }
//    //mediana de 3
//    int i = solve(v, esq, dir, k);
//    if (i > k)
//        quickSelect(v, esq, i - 1, k);
//    if (i < k)
//        quickSelect(v, i + 1, dir, k);
//}
//
//void imprimeID(int *v, int indice, int x, int n)
//{
//    for (int i = 0; i < x; i++)
//    {
//        if (indice < n)
//        {
//            printf("%d\n", v[indice++]);
//        } //end if
//        else
//            break;
//    } //end for
//}
//
//void mergeSort(int *vet, int esq, int dir, int k)
//{
//    if (esq >= dir)
//        return;
//    //int i = separa(vet, esq, dir);
//    //if (i > k)
//    //    quickSelect(vet, esq, i - 1, k);
//    //if (i < k)
//    //    quickSelect(vet, i + 1, dir, k);
//    int meio = (dir + esq) / 2;
//    mergeSort(vet, esq, meio, k);
//    mergeSort(vet, meio + 1, dir, k);
//    merge(vet, esq, meio, dir);
//}
//
//void merge(int *vet, int esq, int meio, int dir)
//{
//    int *aux = (int *)calloc((dir - esq + 1), sizeof(int));
//    int k = 0, i = esq, j = meio + 1;
//    while (i <= meio && j <= dir)
//    {
//        if (vet[i] <= vet[j]) //assim fica estavel
//            aux[k++] = vet[i++];
//        else
//            aux[k++] = vet[j++];
//    }
//    while (i <= meio)
//        aux[k++] = vet[i++];
//    while (j <= dir)
//        aux[k++] = vet[j++];
//
//    k = 0;
//    for (i = esq; i <= dir; i++)
//        vet[i] = aux[k++];
//
//    free(aux);
//}
//
//void mergeSortPadrao(int *vet, int esq, int dir)
//{
//    if (esq >= dir)
//        return;
//    //int i = separa(vet, esq, dir);
//    //if (i > k)
//    //    quickSelect(vet, esq, i - 1, k);
//    //if (i < k)
//    //    quickSelect(vet, i + 1, dir, k);
//    int meio = (dir + esq) / 2;
//    mergeSortPadrao(vet, esq, meio);
//    mergeSortPadrao(vet, meio + 1, dir);
//    merge(vet, esq, meio, dir);
//}