#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

#define numero_de_imagens 4

int main(){

int contador =0;

FILE *file_para_grama;
FILE *file_para_asfalto;

int  vec_numeros[4][2] = { {0,1}, {0,2}, {0,3}, {0,4} };

//printf("%d %d\n\n", vec_numeros[contador+2][0], vec_numeros[contador+2][1]);

char path_grama[29] ;
char path_asfalto[33] ;

int num_de_char_no_path_grama;
int num_de_char_no_path_asfalto;

int tamanho_maximo_da_grama_txt =0;
int tamanho_maximo_do_asfalto_txt =0;

while(contador <numero_de_imagens){ //DataSet grama

  //printf("Aqui o erro\n");
  num_de_char_no_path_grama = sprintf(path_grama, "arq_teste/grass/grass_%d%d.txt", vec_numeros[contador][0], vec_numeros[contador][1] );

  printf("path grama = %s\n\n", path_grama);

  file_para_grama = fopen(path_grama, "r");

  if(file_para_grama != NULL){
    printf("Abri o arquivo %d corretamente\n", contador+1);

    // calcular o ILBP

      //encontrar o tamanho maximo da imagem .txt

      tamanho_maximo_da_grama_txt = fscanf(file_para_grama, "%d%c");

    //calcular o GLCM



    //fim

    fclose(file_para_grama);
    printf("Fechei o %d\n", contador+1);
  }
  else printf("Erro ao abrir o arquivo %d\n", contador+1);

  contador ++;

}//end while abrir grama

printf("****************************************************************\n\nAsfalto\n\n");

contador = 0;

while(contador <numero_de_imagens){ //DataSet asfalto

  //printf("Aqui o erro\n");
  num_de_char_no_path_asfalto = sprintf(path_asfalto, "arq_teste/asphalt/asphalt_%d%d.txt", vec_numeros[contador][0], vec_numeros[contador][1] );

  printf("path asfalto = %s\n\n", path_asfalto);

  file_para_asfalto = fopen(path_asfalto, "r");

  if(file_para_asfalto != NULL){
    printf("Abri o arquivo %d corretamente\n", contador+1);

    // calcular o ILBP

      //encontrar o tamanho maximo da imagem .txt

    //calcular o GLCM



    //fim

    fclose(file_para_asfalto);
    printf("Fechei o %d\n", contador+1);
  }
  else printf("Erro ao abrir o arquivo %d\n", contador+1);

  contador ++;

}//end while abre asfalto

printf("****************************************************************\n\n");


  return 0;
}
