#include <stdio.h>
#include <stdlib.h>

#define RET 0
#define TRI 1
#define CIR 2

typedef struct retangulo
{
    float b;
    float h;
} Retangulo;

typedef struct triangulo
{
    float b;
    float h;
} Triangulo;

typedef struct circulo
{
    float r;
} Circulo;


struct listahet
{
    int tipo;
    void *info;
    struct listahet *prox;
};

typedef struct listahet ListaHet;

ListaHet *cria_ret(float b, float h);
ListaHet *cria_tri(float b, float h);
ListaHet *cria_cir(float r);
float calc_area(ListaHet *e);
float max_area(ListaHet *l);

int main()
{

    return 0;
}

ListaHet *cria_ret(float b, float h)
{
    Retangulo *r;
    ListaHet *p;

    r = (Retangulo *) malloc(sizeof(Retangulo));

    if(r == NULL)
    {
        exit(1);
    }

    r->b = b;
    r->h = h;

    p = (ListaHet *) malloc(sizeof(ListaHet));

    if(p == NULL)
    {
        exit(1);
    }

    p->tipo = RET;
    p->info = r;
    p->prox = NULL;

    return p;
}

ListaHet *cria_tri(float b, float h)
{
    Triangulo *t;
    ListaHet *p;

    t = (Triangulo *) malloc(sizeof(Triangulo));

    if(t == NULL)
    {
        exit(1);
    }

    t->b = b;
    t->h = h;

    p = (ListaHet *) malloc(sizeof(ListaHet));

    if(p == NULL)
    {
        exit(1);
    }

    p->tipo = TRI;
    p->info = t;
    p->prox = NULL;

    return p;
}

ListaHet *cria_cir(float r)
{
    Circulo *c;
    ListaHet *p;

    c = (Circulo *) malloc(sizeof(Circulo));
    if(c == NULL)
    {
        exit(1);
    }

    c->r = r;

    p = (ListaHet *) malloc(sizeof(ListaHet));

    if(p == NULL)
    {
        exit(1);
    }

    p->tipo = CIR;
    p->info = c;
    p->prox = NULL;

    return p;
}

float calc_area(ListaHet *e)
{
    float a;

    switch(e->tipo)
    {
    case RET:
        {
            Retangulo *r = (Retangulo *) e->info;

            a = (r->b) * (r->h);
        }
        break;
    case TRI:
        {
            Triangulo *t = (Triangulo *) e->info;

            a = ((t->b) * (t->h))/2;
        }
        break;
    case CIR:
        {
            Circulo *c = (Circulo *) e->info;

            a = 3.14 * (c->r) * (c->r);
        }
        break;
    }

    return a;
}

float max_area(ListaHet *l)
{
    float aMax = 0;

    ListaHet *aux;

    for(aux = l; aux != NULL; aux = aux->prox)
    {
        float a = calc_area(aux);

        if(a > aMax)
            aMax = a;
    }

    return aMax;
}
