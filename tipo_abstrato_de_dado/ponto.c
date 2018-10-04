#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Ponto{
  double x,y;
}Ponto;

//encapsular
void setPonto(Ponto *p, double x, double y);
Ponto *cria_Ponto();
void imprime_Ponto(Ponto *p);
double calcula_dist(Ponto *p, Ponto *p2);
void libera_Ponto(Ponto *p);

int main(){

  Ponto *p, *p2;
  //p.x = 1.8;
  //p.y = 4.3;
  p = cria_Ponto();
  p2 = cria_Ponto();
  setPonto(p,17,17);
  setPonto(p2,18,19);
  imprime_Ponto(p);
  imprime_Ponto(p2);
  double dist = calcula_dist(p, p2);
  printf("A dist é : %lf\n", dist);
  libera_Ponto(p);
  libera_Ponto(p2);

  return 0;
}

void setPonto(Ponto *p, double x, double y){
  p->x =x;
  p->y=y;
}

Ponto *cria_Ponto(){
  Ponto *p;
  p = (Ponto *) malloc(sizeof(Ponto));

  if(!p){
    printf("Deu ruim cria\n");
    exit(1);
  }

  return p;
}

void imprime_Ponto(Ponto *p){
  if(!p){
    printf("Deu ruim imprime\n");
    exit(1);
  }
  printf("Ponto : %lf %lf\n", p->x, p->y);
}

double calcula_dist(Ponto *p, Ponto *p2){
  if(!p){
    printf("Deu ruim no p1 calc dist\n");
    exit(1);
  }
  if(!p2){
    printf("Deu ruim no p2 calc dist\n");
    exit(1);
  }
  else {double result = sqrt(pow(p->x - p2->x,2)+pow(p->y - p2->y,2));
  return result;
  }
}

void libera_Ponto(Ponto *p){
  free(p);
}
