/*
*   © Erick Giffoni - University of Brasilia
*   Software Engineering - 2020
*   =)
*   Problem : Desfile dos Patos
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int qtdpatos;
    int cor; // indice hash
    int * table = (int *) calloc(1000001, sizeof(int));
    int maiorcor = 0; //indice da cor de maior frequencia
    while(1){
        scanf(" %d", &qtdpatos);
        if(qtdpatos==0) break;

        for(int i=0; i<qtdpatos; i++){
            scanf(" %d", &cor);
            table[cor]++;
            if(table[cor]>table[maiorcor]){
                maiorcor = cor;
            }
        }
        printf("%d\n", maiorcor);
        //limpar a tabela
        for(int i=0; i<1000001; i++){
            table[i] = 0;
        }
    }

    return 0;
}