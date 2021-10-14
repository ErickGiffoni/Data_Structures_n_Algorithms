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

typedef struct conexo{
    int tamanho;
    int * nodes;
}Conexo;

Conexo * vetordeconexo;

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

int buscajoaoNovo(Node *node, int joao)
{
    printf("buscando o node %d em %d\n", joao, node->indice);
    if (node->visitado == 1)
    {
        //ja foi visitado
        printf("node %d ja foi visitado\n", node->indice);
        return -1; //nao esta aqui
    }
    else
    {
        int achei = -1;
        printf("node %d NAO foi visitado\n", node->indice);
        node->visitado = 1;
        if (node->indice == joao)
        {
            printf("ACHEI joao %d em %d\n", joao, node->indice);
            achei = 1;
            return achei;
        }
        else
        {
            for (int i = 0; i < node->countvizinhos; i++)
            {
                printf("vou buscar no vizinho %d\n", node->proximo[i]);
                achei = buscajoaoNovo(&lista[node->proximo[i]], joao);
                if (achei)
                {
                    return achei;
                }
            } //bbusca nos vizinhos nao visitados
        }
        return achei;
    }
} //end buscajoaoNovo

int buscajoao(Node *node, int joao)
{
    //printf("buscando joao no node %d\n", node->indice);
    int achei = 0;
    if (node->indice == joao)
    {
        achei = 1;
    }
    else
    {
        for (int i = 0; node->countvizinhos > 0 && i <= node->countvizinhos; i++)
        {
            //printf("vizinho é %d\n", node->proximo[i]);
            if (node->proximo[i] == joao)
            {
                achei = 1;
                //printf("achei ele em %d\n", node->proximo[i]);
                return achei;
                //break;
            }
        }
    }
    //if(!achei){
    //
    //}
    return achei;
} //end bbuscajoao

int conexo = 0;

int visitalista(Node *node)
{
    int contanodes = 1;
    if (listatavazia(node) && node->visitado == 0)
    {   
        node->visitado = 1;
        vetordeconexo[conexo].tamanho = 1;
        vetordeconexo[conexo].nodes = (int *) malloc(sizeof(int));
        vetordeconexo[conexo].nodes[0] = node->indice;
        conexo++;
        return contanodes;
    }
    else if (node->visitado == 0)
    {
        node->visitado = 1;
        vetordeconexo[conexo].tamanho++;
        vetordeconexo[conexo].nodes = realloc(vetordeconexo[conexo].nodes, vetordeconexo[conexo].tamanho * sizeof(int));
        vetordeconexo[conexo].nodes[ vetordeconexo[conexo].tamanho ] = node->indice;
        conexo++;
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

    if(V == 1){
        printf("Fique em casa\n");
        return 0;
    }

    joaoaqui = j;

    lista = (Node *)calloc(V, sizeof(Node)); //lista de adjacencia
    for (int i = 0; i < V; i++)
    {
        lista[i].proximo = (int *)calloc(V, sizeof(int));
        lista[i].indice = -1; //mudei aqui em 27/11/20 22:07
        for (int j = 0; j < V; j++)
            lista[i].proximo[j] = -1;
    } //end for alocacao da lista de adj

    int v, w;
    while (scanf("%d %d", &v, &w) != EOF)
    {
        lista[v].indice = v;
        lista[w].indice = w;

        //printf("OI\n");

        addnodelist(&lista[v], &lista[w].indice); //add w na lista de v
        addnodelist(&lista[w], &lista[v].indice); //add v na lista de w
    }                                             //end while leitura

    vetordeconexo = (Conexo *) calloc(V, sizeof(Conexo));

    //int conexo = 0;
    int *indicesconexos = (int *)calloc(V, sizeof(int));
    int contanodes = 0;
    int maior = 0; //indice com o maior numero conexo
    int acheijoao;

    for (int i = 0; i < V; i++)
    {
        //vetordeconexo[i]->idconexo = -1;

        contanodes = visitalista(&lista[i]);

        //vetordeconexo[i].tamanho = contanodes;

        if (contanodes)
        {
            //vetordeconexo->idconexo = contanodes;
            //conexo++;
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

    //------------------------------------------------------------------------------------//
    //------------------------------------------------------------------------------------//



    //------------------------------------------------------------------------------------//
    //------------------------------------------------------------------------------------//
    
        int joaonamaior = 0; //booleano
        //buscar se ele ta na maior
        //for (int i = 0; i < lista[maior].countvizinhos; i++)
        //{
        for (int i = 0; i < V; i++)
        {
            lista[i].visitado = 0;
        }
            printf("maior e %d\n", maior);
            joaonamaior = buscajoaoNovo(&lista[maior], j);
            if (joaonamaior != -1)
            {
                printf("Bora pra estrada\n");
                return 0;
            }
        //}
    
    

            //
        for (int k = 0; k < V; k++){
            //printf("k = %d\n", k);
            if (/*k == maior ||*/ indicesconexos[k] == 0 /*|| acheijoao != -1*/)
                continue;
            else
            {
                for (int i = 0; i < V; i++)
                {
                    lista[i].visitado = 0;
                }
                //printf("buscaar na lista com k = %d\n", k);
                acheijoao = buscajoaoNovo(&lista[k], j);
                if (acheijoao != -1)
                {
                    joaoaqui = k;
                    break;
                }
            }
        }//end for encontra joao

        //printf("maior = %d -- ind con maior %d\njoaoaqui = %d == ind con joaoaqui %d\n", maior, indicesconexos[maior], joaoaqui, indicesconexos[joaoaqui]);

        //if(joaoaqui == maior){
        //    printf("Bora pra estrada\n");
        //    return 0;
        //}

        if(indicesconexos[joaoaqui] == indicesconexos[maior]){
            if(indicesconexos[joaoaqui] == 1){
                printf("Fique em casa\n");
            }
            else{
                //if(maior < joaoaqui){
                //    printf("Vamos para %d\n", maior);
                //}
                //else{
                    printf("Bora pra estrada\n");
                //}
            }
        }
        else{
            //maior
                //nao tem como
            //menor
            //printf("joaoaqui %d e maior %d\n", joaoaqui, maior);
            printf("Vamos para %d\n", maior);
        }
        
            //

            //printf("joao faz parte do grupo de %d\n", joaoaqui);
            //printf("indice em joaoaqui %d  --  indice em maior %d\n", indicesconexos[joaoaqui], indicesconexos[maior]);

    return 0;
}