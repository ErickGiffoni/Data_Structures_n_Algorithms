#include <stdio.h>
#include <stdlib.h>

struct Elemento
{
    int valor;
    struct Elemento *prox;
};

typedef struct Elemento Lista;

Lista *criaListaVazia();
Lista *insereInicio(Lista *l, int v);
void imprime(Lista *l);
void libera(Lista *l);

int main()
{
    Lista *list;

    list = criaListaVazia();

    list = insereInicio(list, 5);
    list = insereInicio(list, 4);
    list = insereInicio(list, 3);

    imprime(list);

    libera(list);

    return 0;
}

Lista *criaListaVazia()
{
    return NULL;
}

Lista *insereInicio(Lista *l, int v)
{
    Lista *elem;

    elem = (Lista *) malloc(sizeof(Lista));

    if(elem == NULL)
    {
        exit(-1);
    }

    elem->valor = v;

    if(l == NULL)
    {
        elem->prox = NULL;
        return elem;
    }
    else
    {
        elem->prox = l;
        return elem;
    }
}

void imprime(Lista *l)
{
    Lista *elem;
    int i = 0;

    for(elem = l; elem != NULL; elem = elem->prox)
    {
        printf("Valor na posicao %d: %d\n", i, elem->valor);
        i++;
    }
}

void libera(Lista *l)
{
    Lista *atual;

    for(atual = l; atual != NULL; l = atual)
    {
        atual = atual->prox;
        free(l);
    }
}
