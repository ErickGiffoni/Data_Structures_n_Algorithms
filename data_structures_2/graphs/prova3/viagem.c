/*
*   © Erick Giffoni - University of Brasilia
*   Software Engineering - 2020
*   Assignment 3
*   Problem : https://moj.naquadah.com.br/contests/bcrEDA2-20201-3aatividadeavaliacao/grafo-ajude-joao.html
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
int joaoaqui = 0;
int j; //joao

int listatavazia(Node *node)
{
    if (node->countvizinhos == 0)
        return 1;
    else
        return 0;
} //end listatavazia

int buscajoaoNovo(Node * node, int joao){
    //printf("buscando o node %d em %d\n", joao, node->indice);
    if(node->visitado == 1){
        //ja foi visitado
        //printf("node %d ja foi visitado\n", node->indice);
        return -1; //nao esta aqui
    }
    else{
        int achei = -1;
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

int buscajoao(Node * node, int joao){
    //printf("buscando joao no node %d\n", node->indice);
    int achei = 0;
    if(node->indice == joao){
        achei = 1;
    }
    else{
        for(int i=0; node->countvizinhos>0 && i<=node->countvizinhos; i++){
            if(node->proximo[i] == joao){
                achei = 1; 
                //printf("achei ele em %d\n", node->proximo[i]);
                break;
            }
        }
    }
    //if(!achei){
    //    
    //}
    return achei;
}//end bbuscajoao

int visitalista(Node *node)
{
    int contanodes = 1;
    if (listatavazia(node) && node->visitado == 0)
    {
        node->visitado = 1;
        return contanodes;
    }
    else if (node->visitado == 0)
    {
        node->visitado = 1;
        int i = 0;
        for (int ji = node->proximo[i]; i < node->countvizinhos; i++, ji = node->proximo[i])
        {
            //if(ji == j)
            //    joaoaqui = node->indice;//duvida

            contanodes += visitalista(&lista[ji]);
        } //marca os nodes na lista como visitados
        return contanodes;
    }
    else
        return 0; //node nao foi visitado
} //end visitalista

void addnodelist(Node *onde, int *quem)
{ //add quem na lista do onde
    onde->proximo[onde->countvizinhos] = *quem;
    onde->countvizinhos++;
} //end addnodelist

int main()
{

    int V;
    scanf(" %d", &V);
    scanf(" %d", &j);

    joaoaqui = j;

    lista = (Node *)calloc(V, sizeof(Node)); //lista de adjacencia
    for (int i = 0; i < V; i++){
        lista[i].proximo = (int *)calloc(V, sizeof(int));
        lista[i].indice = -1; //mudei aqui em 27/11/20 22:07
        for(int j=0; j<V; j++)
            lista[i].proximo[j] = -1;
    } //end for alocacao da lista de adj

    int v, w;
    while (scanf("%d %d", &v, &w) != EOF){
        lista[v].indice = v;
        lista[w].indice = w;

        //printf("OI\n");

        addnodelist(&lista[v], &lista[w].indice); //add w na lista de v
        addnodelist(&lista[w], &lista[v].indice); //add v na lista de w
    }//end while leitura

    int conexo = 0;
    int * indicesconexos = (int *) calloc(V, sizeof(int));
    int contanodes = 0;
    int maior = 0;//indice com o maior numero conexo
    int acheijoao;

    for (int i = 0; i < V; i++){
        contanodes = visitalista(&lista[i]);
        if (contanodes){
            conexo++;
            //printf("indice visitado %d\ncontanodes %d\n", i, contanodes);
            indicesconexos[i] = contanodes;
            //printf("conexo i %d é %d AND conexo maior %d é %d\n", i, indicesconexos[i], maior, indicesconexos[maior]);
            indicesconexos[i] > indicesconexos[maior] ? maior = i : 1;

            //acheijoao = buscajoaoNovo(&lista[i], j);
            //if(acheijoao){
            //    joaoaqui = i;
            //}
        }
    } //end for procura conexos
    //printf("maior e %d\n", maior);

    //for(int i=0; i<V; i++){
    //    printf("%d ", indicesconexos[i]);
    //}
    //puts("");

    //printf("%d\n", conexo);

    if(j == maior){
        if(indicesconexos[j] == 1){
            printf("Fique em casa\n");
        }
        else{
            printf("Bora pra estrada\n");
        }
    }
    else if(indicesconexos[j] == indicesconexos[maior]){
        //printf("aqui\n");
        if(indicesconexos[j] == 1){
            printf("Fique em casa\n");
        }
        else{
            printf("Bora pra estrada\n");
        }
    }
    else{
        int joaonamaior = 0;
        //buscar se ele ta na maior
        for(int i=0; i<lista[maior].countvizinhos; i++){
            joaonamaior = buscajoao(&lista[ lista[maior].proximo[i] ], j);
            if(joaonamaior){
                printf("Bora pra estrada\n");
                break;
            }
        }
        if(!joaonamaior){

            //
                for(int k=0; k<V; k++){
                    if(k == maior || indicesconexos[k] == 0)
                        continue;

                    else{
                        for(int i=0; i<V; i++){
                            lista[i].visitado = 0;
                        }

                        acheijoao = buscajoaoNovo(&lista[k], j);
                        if(acheijoao != -1){
                            joaoaqui = k;
                            break;
                        }
                    }
                }
            //

            //printf("joao faz parte do grupo de %d\n", joaoaqui);
            //printf("indice em joaoaqui %d  --  indice em maior %d\n", indicesconexos[joaoaqui], indicesconexos[maior]);
            if(indicesconexos[joaoaqui] >= indicesconexos[maior])
                printf("Bora pra estrada\n");
            else
                printf("Vamos para %d\n", maior);
        }
    }

    return 0;
}