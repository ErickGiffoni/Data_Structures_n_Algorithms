
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

typedef struct conexo
{
    int tamanho;
    int *nodes;
} Conexo;

Conexo *vetordeconexo;

Node *lista;
int joaoaqui = 0;
int j, vertices = 0; //joao

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
        vetordeconexo[conexo].nodes = (int *)malloc(sizeof(int));
        vetordeconexo[conexo].nodes[0] = node->indice;
        return contanodes;
    }
    else if (node->visitado == 0)
    {
        node->visitado = 1;
        vetordeconexo[conexo].tamanho++;
        vetordeconexo[conexo].nodes = realloc(vetordeconexo[conexo].nodes, vetordeconexo[conexo].tamanho * sizeof(int));
        vetordeconexo[conexo].nodes[vetordeconexo[conexo].tamanho - 1] = node->indice;

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
    vertices++;
} //end addnodelist

int main()
{

    int V;
    scanf(" %d", &V);
    scanf(" %d", &j);

    if (V == 1)
    {
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

    vetordeconexo = (Conexo *)calloc(V, sizeof(Conexo));

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
            conexo++;
            //vetordeconexo->idconexo = contanodes;
            //conexo++;
            //printf("indice visitado %d\ncontanodes %d\n", i, contanodes);
            indicesconexos[i] = contanodes;
            //printf("conexo i %d é %d AND conexo maior %d é %d\n", i, indicesconexos[i], maior, indicesconexos[maior]);
            //indicesconexos[i] > indicesconexos[maior] ? maior = i : 1;

            //acheijoao = buscajoaoNovo(&lista[i], j);
            //if(acheijoao){
            //    joaoaqui = i;
            //}
        }
    } //end for procura conexos

    int joaonamaior = 0; //booleano
    //buscar se ele ta na maior
    //for (int i = 0; i < lista[maior].countvizinhos; i++)
    //{
    for (int i = 0; i < V; i++)
    {
        lista[i].visitado = 0;
    }
    // printf("maior e %d\n", maior);
    // joaonamaior = buscajoaoNovo(&lista[maior], j);
    // if (joaonamaior != -1)
    // {
    //     printf("Bora pra estrada\n");
    //     return 0;
    // }

    //

    int joaoaqui_index = -1;

    for (int i = 0; i < conexo; i++)
    {
        if (joaoaqui_index != -1)
            break;

        for (j = 0; j < vetordeconexo[i].tamanho; j++)
        {
            if (vetordeconexo[i].nodes[j] == joaoaqui)
            {
                joaoaqui_index = i;
                break;
            }
        }
    }

    int maior_index = 0;

    for (int i = 0; i < conexo; i++)
    {
        if (vetordeconexo[i].tamanho > vetordeconexo[maior_index].tamanho)
        {
            maior_index = i;
        }
        else if (vetordeconexo[i].tamanho == vetordeconexo[maior_index].tamanho)
        {
            if (joaoaqui_index == i && joaoaqui_index != -1)
            {
                maior_index = i;
            }
            else
            {
                int menori = 5002, min_maior_index = 5003;

                // ahhh meu deux
                for (j = 0; j < vetordeconexo[maior_index].tamanho; j++)
                    if (vetordeconexo[maior_index].nodes[j] < min_maior_index)
                        min_maior_index = vetordeconexo[maior_index].nodes[j];
                //nao aguento mais mas bora
                for (j = 0; j < vetordeconexo[i].tamanho; j++)
                    if (vetordeconexo[i].nodes[j] < menori)
                        menori = vetordeconexo[i].nodes[j];

                if (menori < min_maior_index)
                    maior_index = menori;
            }
        }
    }

    //printf("maior = %d -- ind con maior %d\njoaoaqui = %d == ind con joaoaqui %d\n", maior, indicesconexos[maior], joaoaqui, indicesconexos[joaoaqui]);

    //if(joaoaqui == maior){
    //    printf("Bora pra estrada\n");
    //    return 0;
    //}

    // agora vai

    if ((lista[joaoaqui].countvizinhos == 0 && joaoaqui_index != -1) || vertices == 0)
    {
        printf("Fique em casa");
    }
    else if (joaoaqui_index == maior_index)
    {
        printf("Bora pra estrada\n");
    }
    else
    {
        int cid_index = 9999;
        for (int i = 0; i < vetordeconexo[maior_index].tamanho; i++)
            if (vetordeconexo[maior_index].nodes[i] < cid_index)
                cid_index = vetordeconexo[maior_index].nodes[i];

        printf("Vamos para %d\n", cid_index);
    }

    return 0;
}