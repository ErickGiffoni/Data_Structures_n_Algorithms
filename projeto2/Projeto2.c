#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pasta_arquivos(char *);
int main(){

  FILE *fp;
  int cont_elementos = 0, cont_linhas = 0, cont_colunas = 0,aux=0;
  int numero;
  char *p;
  p = (char *)malloc(50000);
  if(p==NULL){
    printf("ALOCACAO FALHOU!!\n");
    exit(1);
  }
  pasta_arquivos(p);
  for(int i=0;i<50;i++){
printf("%s\n", p+i*100);
}
  free(p);
  return 0;
}

void pasta_arquivos(char *p){
  char m_locals[50][100];
  int x = 0;
  char *teste;
  char nomeArquivo_1[] = "DataSet/asphalt/asphalt_";
  char nomeArquivo_2[] = ".txt";
  char lol[] = "DataSet/asphalt/asphalt_01.txt";
  char nomeArquivo_full[76];
  strcpy(nomeArquivo_full,nomeArquivo_1);
  //strcat (nomeArquivo_full,  );
  //printf("%s\n",nomeArquivo_full );
  for(int i=0; i<50; i++){
    strcpy(nomeArquivo_full,nomeArquivo_1);
    x += 1;
    if(x<10){
      strcat(nomeArquivo_full, "0");
    }
    char numb[5];
    sprintf(numb, "%d", x);
    strcat(nomeArquivo_full, numb);
    strcpy(m_locals[i],nomeArquivo_full);
  }
  for(int i=0;i<50;i++){
    strcat(m_locals[i],nomeArquivo_2);
  //  printf("%s\n",m_locals[i]);
  }
  teste = &m_locals[0][0];
  for (int i ; i<50; i++){

}
  p = &m_locals[0][0];
  for(int i=0;i<50;i++){
  printf("%s\n", p+i*100);
}


}
