/*
*   © Erick Giffoni - University of Brasilia
*   Software Engineering - 2020
*   Assignment 3
*   Problem : https://moj.naquadah.com.br/contests/bcrEDA2-20201-3aatividadeavaliacao/grafo-nlogonia-conexoes.html
*   =)
*   compilation:
*   '_$ gcc '
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int indice;
    int visitado;
    int countvizinhos;
    int *proximo; //array com os indices dos vizinhos
} Node;

Node *lista;

int listatavazia(Node *node){
    if (node->countvizinhos == 0)
        return 1;
    else
        return 0;
} //end listatavazia

//int buscajoao(Node * node, int joao){
//    //printf("buscando %d no node %d\n", joao, node->indice);
//    int achei = 0;
//    if(node->indice == joao){
//        achei = 1;
//    }
//    else if( ! listatavazia(node) ){
//        for(int i=0; node->countvizinhos>0 && i<=node->countvizinhos; i++){
//            if(node->proximo[i] == joao){
//                achei = 1; 
//                //printf("achei ele em %d\n", node->proximo[i]);
//                break;
//            }
//        }
//    }
//    return achei;
//}//end bbuscajoao

int buscajoaoNovo(Node * node, int joao){
    //printf("buscando o node %d em %d\n", joao, node->indice);
    if(node->visitado == 1){
        //ja foi visitado
        //printf("node %d ja foi visitado\n", node->indice);
        return 0; //nao esta aqui
    }
    else{
        int achei = 0;
        //printf("node %d NAO foi visitado\n", node->indice);
        node->visitado = 1;
        if(node->indice == joao){
            //printf("ACHEI joao %d em %d\n", joao, node->indice);
            achei = 1;
        }
        else{
            for(int i=0; i < node->countvizinhos; i++){
                //printf("vou buscar no vizinho %d\n", node->proximo[i]);
                achei = buscajoaoNovo( &lista[ node->proximo[i] ], joao);
                if(achei){
                    break;
                }
            }//bbusca nos vizinhos nao visitados
        }
        return achei;
    }
}//end buscajoaoNovo

void addnodelist(Node *onde, int *quem)
{ //add quem na lista do onde
    onde->proximo[onde->countvizinhos] = *quem;
    onde->countvizinhos++;
} //end addnodelist

int main()
{

    int V;
    scanf(" %d", &V);

    lista = (Node *)calloc(V, sizeof(Node)); //lista de adjacencia
    for (int i = 0; i < V; i++){
        lista[i].proximo = (int *)calloc(V, sizeof(int));
        lista[i].indice = -1;
        for(int j=0; j<V; j++)
            lista[i].proximo[j] = -1;
    } //end for alocacao da lista de adj

    int v, w, d;
    while (1){
        scanf("%d %d %d", &v, &w, &d);
        if(v == 0 && w == 0 && d == 0)
            break;
        
        lista[v].indice = v;
        lista[w].indice = w;

        addnodelist(&lista[v], &lista[w].indice); //add w na lista de v
        if(d == 2)
            addnodelist(&lista[w], &lista[v].indice); //add v na lista de w
    }//end while leitura

    int t, x;
    int tprax=0, xprat=0;
    while(scanf(" %d %d", &t, &x) != EOF){
        if(x == t){
            tprax = 1;
            xprat = 1;
        }
        else{
            //buscar de t para x
            //printf("BBUSCAR X %d EM T %d\n", x, t);
            tprax = buscajoaoNovo(&lista[t], x);

            //marcar todos como nao visitados
            for(int i=0; i<V; i++){
                lista[i].visitado = 0;
            }

            //if(!tprax){
            //    //int vai = lista[t].countvizinhos;
            //    for(int i=0; i<lista[t].countvizinhos; i++){
            //        tprax = buscajoao(&lista[ lista[t].proximo[i] ], x);
            //        if(tprax)
            //            break;
            //    }
            //}
            //buscar de x para t
            //printf("xprat indice %d\nlista x %d\n", x, lista[x].indice);
            //printf("BUSCAR T %d EM X %d\n", t, x);
            xprat = buscajoaoNovo(&lista[x], t);

            //marcar todos como nao visitados
            for(int i=0; i<V; i++){
                lista[i].visitado = 0;
            }

            //if(!xprat){
            //    for(int i=0; i<lista[x].countvizinhos; i++){
            //        xprat = buscajoao(&lista[ lista[x].proximo[i] ], t);
            //        if(xprat)
            //            break;
            //    }
            //}
        }
        if(tprax){
            if(xprat){
                printf("Ida e Volta\n");
            }
            else{
                printf("Apenas Ida\n");
            }
        }//end if t pra x
        else if(xprat){
            printf("Apenas Volta\n");
        }//end if x pra t
        else{
            printf("Impossibru\n");
        }//end else impossibru
        tprax = 0;
        xprat = 0;
    }//end while le t, x

    return 0;
}