/*
*   © Erick Giffoni - University of Brasilia
*   Software Engineering - 2020
*   Final Test 4
*   Problem : https://moj.naquadah.com.br/contests/bcrEDA2-20201-4aatividadeavaliacao/grafo-chp.html
*   =)
*   compilation:
*   '_$ gcc caifora.c'
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node {
    int valor;
    int visitado;
    int countvizinhos;
    //int superconexao;
} Node;

typedef struct aresta{
    Node * de;
    Node * para;
    int custo;
    int superconexao;
} Aresta;

int * visitados, * distancias, * sucessores;

void addConexao(Node * listanodes, Aresta * listaarestas, int * v, int * w, int * c, int * t, int * countnodes, int * countarestas);

void calculaCustos(Node * listanodes, Aresta * listaarestas, int * o, int * x, int * countnodes, int * countarestas);

int main(void){

    int V;
    scanf(" %d", &V);

    int qtdarestas = V*2 + 1;

    Node * listanodes = (Node *) calloc(V, sizeof(Node));

    Aresta * listaarestas = (Aresta *) calloc(qtdarestas, sizeof(Aresta));

    visitados = (int *) calloc(V, sizeof(int));
    distancias = (int *) calloc(V, sizeof(int));
    sucessores = (int *) calloc(V, sizeof(int));

    int v, w, c, t;
    int /*countnodes = 0,*/ countarestas = 0;

    while(1){
        scanf(" %d %d %d %d", &v, &w, &c, &t);
        if(v == w && w == c && c == t && t == 0){
            break;
        }//end if tudo zero
        addConexao(listanodes, listaarestas, &v, &w, &c, &t, &V, &countarestas);
    }//end while leitura v,w,c,t

    int o, x;

    while(scanf(" %d, %d", &o, &x) != EOF){
        calculaCustos(listanodes, listaarestas, &o, &x, &V, &countarestas);
    }//end while leitura o,x e calculo dos custos

    return 0;
}//end main

void addConexao(Node *listanodes, Aresta *listaarestas, int *v, int *w, int *c, int *t, int *countnodes, int *countarestas){

    listanodes[*v].valor = *v;
    listanodes[*v].countvizinhos += 1;
    listanodes[*w].valor = *w;
    listanodes[*w].countvizinhos += 1;
    //*countnodes += 2;

    listaarestas[*countarestas].de = &listanodes[*v];
    listaarestas[*countarestas].para = &listanodes[*w];
    listaarestas[*countarestas].custo = *c;

    if(*t == 0){
        *countarestas += 1;
        listaarestas[*countarestas].de = &listanodes[*w];
        listaarestas[*countarestas].para = &listanodes[*v];
        listaarestas[*countarestas].custo = *c;
        *countarestas += 1;
    }//end if aresta bidirecional
    else{
        listaarestas[*countarestas].superconexao = 1;
        *countarestas += 1;
    }//end else superconexao

}//end add conexao

void calculaCustos(Node *listanodes, Aresta *listaarestas, int *o, int *x, int *countnodes, int *countarestas){

    int cx, cs; //custos: sem, com super conexao, respect.
    int cx_ok = 0, cs_ok = 0; //se for possivel calcular x, s -> 0: impossivel

    for(int i=0; i<*countnodes; i++){
        visitados[i] = 0;
        distancias[i] = INT_MAX;
        sucessores[i] = -1;
    }//end for inicializa todos

    for(int i = 0; i<*countarestas; i++){
        if(listaarestas[i].de->valor == *o){
            if(listaarestas[i].para->valor == *x){
                if(listaarestas[i].superconexao == 1){
                    cs = listaarestas[i].custo;
                    break;
                }
                else{
                    cx = listaarestas[i].custo;
                    break;
                }
            }
            else(
                
            )
        }
    }
    
    return;

}//end calcula custos