#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#define numero_de_imagens 4 //numero de imagens a serem lidas

int main(){

int contador =0;
int i_for =0, j_for =0; //contadores para qualquer loop que for preciso

FILE *file_para_grama;
FILE *file_para_asfalto; //ponteiros para os arquivos

int  vec_numeros[4][2] = { {0,1}, {0,2}, {0,3}, {0,4} };

//printf("%d %d\n\n", vec_numeros[contador+2][0], vec_numeros[contador+2][1]);

char path_grama[29] ;
char path_asfalto[33] ;
char ponto_e_virgula;

int num_de_char_no_path_grama;
int num_de_char_no_path_asfalto;

int numero_de_colunas_grama =0;
int numero_de_colunas_asfalto =0;

int numero_de_linhas_grama =0;
int numero_de_linhas_asfalto =0;
int numero_no_arquivo =0;

    /* Aqui comeca o show */

while(contador <numero_de_imagens){ //DataSet grama

  //printf("Aqui o erro\n");
  num_de_char_no_path_grama = sprintf(path_grama, "arq_teste/grass/grass_%d%d.txt", vec_numeros[contador][0], vec_numeros[contador][1] );

  printf("path grama = %s\n\n", path_grama);

  file_para_grama = fopen(path_grama, "r");

  if(file_para_grama != NULL){
    printf("Abri o arquivo %d corretamente\n", contador+1);

    // CALCULAR O ILBP

      //encontrar o tamanho maximo da imagem .txt -> 1024 x 1024
    fscanf(file_para_grama, "%d%c", &numero_no_arquivo, &ponto_e_virgula);
      while(!feof(file_para_grama)){

        if(ponto_e_virgula == ';'){
          numero_de_colunas_grama ++;
        }
        else if(ponto_e_virgula == '\n'){
          numero_de_linhas_grama ++;
          numero_de_colunas_grama --; // para desconsiderar as quebras de linha
        }

        fscanf(file_para_grama, "%d%c", &numero_no_arquivo, &ponto_e_virgula);//leia os proximos

      }//end of while feof grama

      numero_de_colunas_grama += 1; //o ultimo numero do arquivo nao e seguido de ';'
      numero_de_linhas_grama -= 1; //a ultima quebra de linha do arquivo nao representa uma nova linha com elementos
      printf("Tamaho de colunas : %d\nNumero de linhas : %d\n\n", numero_de_colunas_grama, numero_de_linhas_grama);
      printf("Numero no arquivo : %d\nPonto e virgula : %c\n\n", numero_no_arquivo, ponto_e_virgula);

      //alocar dinamicamente uma matriz para armazenar os numeros do arquivo .txt e ler esses numeros

        int ** matriz_grama_txt = (int **) calloc(numero_de_linhas_grama, sizeof(int *)); //alocacao de uma matriz para o arquivo txt
        for(i_for =0; i_for<numero_de_linhas_grama; i_for++){
          matriz_grama_txt[i_for] = (int *) calloc(numero_de_linhas_grama, sizeof(int)); //alocacao das colunas da matriz com mesmo numero de linhas
        }

      //ler o .txt novamente e preencher a matriz_grama_txt
        rewind(file_para_grama); //o ponteiro deve voltar ao inicio do arquivo

        for(i_for = 0; i_for < numero_de_linhas_grama; i_for++){ //acesso as linhas
          for(j_for =0; j_for< numero_de_linhas_grama; j_for++){ //acesso as colunas
            if(feof(file_para_grama)){
              printf("END OF FILE %d\n", contador+1); //se o ponteiro chegar ao EOF
              break;
            }
            else fscanf(file_para_grama, "%d%c", &matriz_grama_txt[i_for][j_for], &ponto_e_virgula); //le o numero e o caractere
          }
printf("Elemento [][ultimo] %d\n", matriz_grama_txt[i_for][numero_de_linhas_grama-1]);
        }//end for preenche matriz

printf("FREE NIGGA %d\n", contador+1);
      free(matriz_grama_txt); //liberar o espaco em memoria

    //CALCULAR O GLCM



    //fim

    numero_de_colunas_grama =0; //atualizar para ler a proxima imagem
    numero_de_linhas_grama =0; //atualizar tambem

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

    // CALCULAR O ILBP

      //encontrar o tamanho maximo da imagem .txt -> 1024 x 1024

    //CALCULAR O GLCM



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
