#include <stdio.h>
#include <stdlib.h>

#define RET 0
#define TRI 1
#define CIR 2

typedef struct retangulo{
  float b,h;
}Retangulo;

typedef struct triangulo{
  float b,h;
}Triangulo;

typedef struct circulo{
  float r;
}Circulo;

typedef struct listahet{
  int tipo; // 0 retangulo, 1 triangulo, 2 circulo
  void *info;
  struct listahet *prox;
}Listahet;

Listahet *cria_ret(float b, float h);
Listahet *cria_tri(float b, float h);
Listahet *cria_cir(float r);

int main(){



  return 0;
}//end main

Listahet *cria_ret(float b, float h){
  Retangulo *r;
  Listahet *e;

  r = (Retangulo*) malloc(sizeof(Retangulo));

  if(r==NULL) exit(1);

  r->b = b;
  r->h = h;

  e = (Listahet *) malloc(sizeof(Listahet));

  if(e == NULL) exit(-2);

  e->tipo = RET;
  e->info = r;
  e->prox = NULL;

  return e;
}//end of cria_ret

Listahet *cria_tri(float b, float h){
  Triangulo *t;
  Listahet *e;
  t = (Triangulo*) malloc(sizeof(Triangulo));

  if (t == NULL) exit(1);
  t->b = b;
  t->h = h;

  e = (Listahet *) malloc(sizeof(Listahet));

  if(e == NULL) exit(-2);

  e->tipo = TRI;
  e->info = t;
  e->prox = NULL;

  return e;

}
Listahet *cria_cir(float r){
  Circulo *c;
  Listahet *e;
  c = (Circulo*) malloc(sizeof(Circulo));

  if (t == NULL) exit(1);
  c->r = r;

  e = (Listahet *) malloc(sizeof(Listahet));

  if(e == NULL) exit(-2);

  e->tipo = CIR;
  e->info = c;
  e->prox = NULL;

  return e;
}

float calc_area(Listahet *e){
  float a;
  switch (e->tipo) {
    case RET:
      {
        Retangulo *r = (Retangulo*) e->info;

        a = r->b * r->h ;
      }
      break;
    case TRI:
    {
      Triangulo *t = (Triangulo*) e->info;
      a = ((t->b)*(t->h))/2.0f;
    }
    break;
  case CIR:
  {
    Circulo *c = (Circulo*) e->info;
    a = 3.14159f * c->r * c->r ;
  }
  }

  return a;
}
