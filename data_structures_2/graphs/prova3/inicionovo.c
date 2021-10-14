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

typedef struct node{
    int indice;
    int visitado;
    int countvizinhos;
    int * proximo; //array com os indices dos vizinhos
}Node;

Node *lista;

int listatavazia(Node * node){
    if(node->countvizinhos == 0)
        return 1;
    else
        return 0;
}//end listatavazia

int visitalista(Node * node, int * conexo){

    if(listatavazia(node) && node->visitado == 0){
            node->visitado = 1;
            return 1;
        }
    else if(node->visitado == 0){
        node->visitado = 1;
        int i=0;
        for(int j = node->proximo[i]; i <=node->countvizinhos; i++, j = node->proximo[i]){
            visitalista(&lista[j], conexo);
        }//marca os nodes na lista como visitados
        return 1;
    }
    else
        return 0; //node nao foi visitado
}//end visitalista

void addnodelist(Node * onde, int * quem){ //add quem na lista do onde
        onde->proximo[onde->countvizinhos] = *quem;
        onde->countvizinhos++;
}//end addnodelist

int main(){

    int V;
    scanf(" %d", &V);

    lista = (Node *)calloc(V, sizeof(Node)); //lista de adjacencia
    for (int i = 0; i < V; i++){
        lista[i].proximo = (int *) calloc(V, sizeof(int));
    } //end for alocacao da lista de adj

    int v, w;
    while (scanf("%d %d", &v, &w) != EOF){
        lista[v].indice = v;
        lista[w].indice = w;

        //printf("OI\n");

        addnodelist(&lista[v], &lista[w].indice); //add w na lista de v
        addnodelist(&lista[w], &lista[v].indice); //add v na lista de w
    } //end while leitura

    int conexo = 0;

    for(int i=0; i<V; i++){
        if( visitalista(&lista[i], &conexo) )
            conexo++;
    }//end for procura conexos

    printf("%d\n", conexo);

    return 0;
}

/*
int * tmp = node->proximo;
        if(*tmp == anterior || *tmp == primeiro)
            tmp ++;
        printf("NAO ACHEI, vou procurar no vizinho %d\n", *tmp);
        while(*tmp != -1){
            achei = buscajoao(&lista[ *tmp ], joao, node->indice, primeiro);
            if(achei)
                break;
            tmp++;
        }
        */