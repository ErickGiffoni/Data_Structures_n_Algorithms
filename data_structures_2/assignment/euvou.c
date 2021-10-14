/*
*   © Erick Giffoni - University of Brasilia
*   Software Engineering - 2020
*   Final Assignment
*   Problem : https://moj.naquadah.com.br/contests/bcrEDA2-20201-trabalho/euvouestarla.html
*   =)
*   compilation:
*   '_$ gcc euvou.c'
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int N, M, J, A, vizin, ju_esteve, quero_saber;
    scanf(" %d %d %d", &N, &M, &J);

    //alocar vetor de bairros
    int * bairros = (int *) calloc(N, sizeof(int));

    //alocar matriz de adj dos bairros
    int ** adj = (int **) calloc(N, sizeof(int *));
    for(int i=0; i<N; i++){    
        adj[i] = (int *) calloc(N, sizeof(int)); //continua alocacao da matriz adj
    }

    for(int i=0; i<N; i++){

        scanf(" %d", &A);

        for(int j=0; j<A; j++){
            scanf(" %d", &vizin);
            //add vizinho de i na matriz
            adj[i][vizin] = 1;
        }

    }

    for(int i=0; i<M; i++){
        scanf(" %d", &ju_esteve);
        //marcar ju_esteve como visitado e os vizinhos tbm
        bairros[ju_esteve] = 1;
        for(int j=0; j<N; j++){
            if(adj[ju_esteve][j] == 1){
                bairros[j] = 1;
            }//end if
            else{
                continue;
            }//end else
        }//end for j
    }//end for i

    for(int i=0; i<J; i++){
        scanf(" %d", &quero_saber);
        //acessar a posicao quero_saber e ver se foi visitada
        //print 'Eu vou...' ou 'Nao vou...'
        printf("%s\n", bairros[quero_saber] == 1 ? "Eu vou estar la" : "Nao vou estar la");
    }

    return 0;
}