/*
*   © Erick Giffoni - University of Brasilia
*   Software Engineering - 2020
*   =)
*   Problem : Diga-me a Frequencia
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Caracter{
    int contagem;
    int codigo;
} Caracter;

int separa(Caracter *v, int esq, int dir){
    Caracter c = v[dir];
    int j = esq;
    for (int k = esq; k < dir; k++){
        if (v[k].contagem < c.contagem){
                Caracter tmp = v[k];
                v[k] = v[j];
                v[j] = tmp;
                j++;
        }
        else if (v[k].contagem == c.contagem){
            if(v[k].codigo < c.codigo){
                Caracter tmp = v[k];
                v[k] = v[j];
                v[j] = tmp;
                j++;
            }
        }
    } //end for
    Caracter tmp = v[j];
    v[j] = v[dir];
    v[dir] = tmp;
    return j;
}

void quickSort(Caracter *v, int esq, int dir){
    if (dir <= esq)
        return;
    int j = separa(v, esq, dir);
    quickSort(v, esq, j - 1);
    quickSort(v, j + 1, dir);
}

int main()
{
    char string[1001];
    Caracter * vetchar = (Caracter *) calloc(256, sizeof(Caracter));
    while(scanf(" %s", string)!=EOF){
        for (int i=0; strcmp(&string[i], "\0") != 0; i++){
            vetchar[string[i]].codigo = string[i];
            vetchar[string[i]].contagem ++;
        }
        //ordenar e print
        quickSort(vetchar, 0, 255);
        for(int i=0; i<256; i++){
            if(vetchar[i].contagem==0)
                continue; //pular os elementos vazios
            else{
                printf("%d %d\n", vetchar[i].codigo, vetchar[i].contagem);
            }
        }
        puts("");
        //limpar
        for (int i = 0; i < 256; i++){
            vetchar[i].codigo = 0;
            vetchar[i].contagem = 0;
        }
    }
    free(vetchar);

    return 0;
}