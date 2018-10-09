#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
  int dado;
  struct lista *prox;
}Lista;

Lista *criaListaVazia();

Lista *criaElemento(int d);

Lista *insereInicio(Lista *l, Lista *e);

void insereLista(Lista *l, Lista *e, int idx);

void printLista(Lista *l);

void liberaLista(Lista *l);

Lista *buscaElemento(Lista *l,int d);

int main(){

  Lista *lista, *temp;
  lista = criaListaVazia();

  lista = insereInicio(lista, criaElemento(1));
  lista = insereInicio(lista, criaElemento(2));
  lista = insereInicio(lista, criaElemento(3));
//printf("ERRROUU\n");
  insereLista(lista, criaElemento(15), 2);
//printf("ERRROUU\n");
  printLista(lista);

  temp = buscaElemento(lista, 15);
  if(temp != NULL)
    printf("\n%p\n", temp);
  else printf("Element not found\n");

  liberaLista(lista);
  return 0;
}

Lista *criaListaVazia(){
  return NULL;
}

Lista *criaElemento(int d){
  Lista *l;
  l = (Lista *) malloc(sizeof(Lista));
  if(l==NULL){
   printf("Deu ruim\n");
   exit(1);
 }
 l->dado = d;
 l->prox = NULL;
  return l;
}

Lista *insereInicio(Lista *l, Lista *e){
  e->prox = l;
  return e;
}

void printLista(Lista *l){
  Lista *e;
  for(e=l; e != NULL; e= e->prox){
    printf("%d\t", e->dado);
  }
  printf("\n");
}

void liberaLista(Lista *l){
  Lista *e;
  do{
    e = l->prox;
    free(l);
    l=e;
  }while(e!=NULL);
}

void insereLista(Lista *l, Lista *e, int idx){
  int i=0;
  Lista *t;
  for(t = l; i!= idx-1; t = t->prox){
    i++;
  }
  e->prox = t->prox;
  t->prox = e;

}

Lista *buscaElemento(Lista *l, int d){
  Lista *e;
  for(e = l; e!=NULL; e = e->prox){
    if(e->dado == d)
      break;
  }
  return e;
}
