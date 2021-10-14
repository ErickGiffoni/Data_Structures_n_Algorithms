/*
*   © Erick Giffoni - University of Brasilia
*   Software Engineering - 2020
*   Assignment 3
*   Problem : https://moj.naquadah.com.br/contests/bcrEDA2-20201-3aatividadeavaliacao/grafo-nucleos-cidades.html
*   =)
*   compilation:
*   '_$ gcc '
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int V;
    scanf(" %d", &V);

    int ** arestas = (int **) calloc(V, sizeof(int *)); //matriz de adjacencia
    int * pre = (int *) calloc(V, sizeof(int)); //pre -> marcar os visitados
    for(int i=0; i<V; i++){
        arestas[i] = (int *) calloc(V, sizeof(int));
        pre[i] = -1;
    }//end for alocacao

    int v, w;
    while(scanf(" %d %d", &v, &w)!=EOF){
        arestas[v][w] = 1;
        arestas[w][v] = 1;
    }//end while leitura

    int conexos = 0;
    int temvizinho = 0;
    int sozinho = 0;

    for(int i=0; i<V; i++){
        if(pre[i]==-1){
            printf("visitando o %d\n", i);
            //visita os nos
            pre[i] = 0;

            for(int j=i+1; j<V; j++){
                printf("aresta %d %d = %d\n", i, j, arestas[i][j]);
                if(arestas[i][j] == 1 && pre[j] == -1){
                    pre[j] = 0;
                    temvizinho = 1;
                }
                else{
                    sozinho++;
                }
                printf("pre de %d = %d\n", j, pre[j]);
            }//end for vista os nos

        }//end if nao visitado
        else{
            for(int k=0; k<V; k++)
                if(arestas[i][k] == 1)
                    pre[k] = 0;
        }
        if(sozinho >= V-1)
            conexos++;

        else if(temvizinho) 
            conexos++;

        temvizinho = 0;
        sozinho = 0;
    }//end for conta conexos

    printf("%d\n", conexos);

    free(pre);
    for(int i=0; i<V; i++)
        free(arestas[i]);
    free(arestas);

    return 0;
}