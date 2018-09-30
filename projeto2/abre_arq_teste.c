#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <string.h>
#include "libraries/ILBP_library.h"

#define numero_de_imagens 50 //numero de imagens a serem lidas

int main(){

int contador =0;
int i_for =0, j_for =0; //contadores para qualquer loop que for preciso

FILE *file_para_grama;
FILE *file_para_asfalto;

int  vec_numeros[50][2] = { {0,1}, {0,2}, {0,3}, {0,4}, {0,5}, {0,6}, {0,7}, {0,8}, {0,9}, {1,0},
                            {1,1}, {1,2}, {1,3}, {1,4}, {1,5}, {1,6}, {1,7}, {1,8}, {1,9}, {2,0},
                            {2,1}, {2,2}, {2,3}, {2,4}, {2,5}, {2,6}, {2,7}, {2,8}, {2,9}, {3,0},
                            {3,1}, {3,2}, {3,3}, {3,4}, {3,5}, {3,6}, {3,7}, {3,8}, {3,9}, {4,0},
                            {4,1}, {4,2}, {4,3}, {4,4}, {4,5}, {4,6}, {4,7}, {4,8}, {4,9}, {5,0} };

int vetores_ILBP_grama[numero_de_imagens][512]={0};//servira para armazenar o vetor ILBP de cada .txt de grama.
                                                  //Cada vetor possui 512 posicoes, correspondentes aos possiveis valores do ILBP calculado na
                                                 //vizinhanca de 8, que sao de 0 a 511.
int vetores_ILBP_asfalto[numero_de_imagens][512]={0};//servira para armazenar o vetor ILBP de cada .txt de asfalto.


//printf("%d %d\n\n", vec_numeros[contador+2][0], vec_numeros[contador+2][1]);
char path_grama[27] ;
char path_asfalto[31] ;
char ponto_e_virgula;

int num_de_char_no_path_grama;
int num_de_char_no_path_asfalto;

int numero_de_colunas_grama =0;
int numero_de_colunas_asfalto =0;

int numero_de_linhas_grama =0;
int numero_de_linhas_asfalto =0;
int numero_no_arquivo =0;

//int avg_pixel =0, contador_do_pixel =0; //media dos 8 vizinhos do pixel (inclusive) e contador de repeticao, respectivamente

    /* Aqui comeca o show */


while(contador <numero_de_imagens){

  //printf("Aqui o erro\n");
  num_de_char_no_path_grama = sprintf(path_grama, "DataSet/grass/grass_%d%d.txt", vec_numeros[contador][0], vec_numeros[contador][1] );

  //printf("path grama = %s\n\n", path_grama);

  file_para_grama = fopen(path_grama, "r");

  if(file_para_grama != NULL){
    //printf("Abri o arquivo %d corretamente\n", contador+1);

    // CALCULAR O ILBP

      //encontrar o tamanho maximo da imagem .txt -> 1025 x 1025
      while(!feof(file_para_grama)){
        fscanf(file_para_grama, "%d%c", &numero_no_arquivo, &ponto_e_virgula);

        if(ponto_e_virgula == ';'){
          numero_de_colunas_grama ++;
        }
        else if(ponto_e_virgula == '\n'){
          numero_de_linhas_grama ++;
          numero_de_colunas_grama ++;
        }

        //fscanf(file_para_grama, "%d%c", &numero_no_arquivo, &ponto_e_virgula);//leia os proximos

      }//end of while feof grama

      //numero_de_colunas_grama += 1; //o ultimo numero do arquivo nao e seguido de ';'
      numero_de_linhas_grama -= 1; //a ultima quebra de linha do arquivo nao representa uma nova linha com elementos
      numero_de_colunas_grama /= numero_de_linhas_grama;
      //printf("Tamaho de colunas : %d\nNumero de linhas : %d\n\n", numero_de_colunas_grama, numero_de_linhas_grama);
      //printf("Ultimo Numero no arquivo : %d\nPonto e virgula : %c\n\n", numero_no_arquivo, ponto_e_virgula);

      //alocar dinamicamente uma matriz para armazenar os numeros do arquivo .txt e ler esses numeros

        int ** matriz_grama_txt = (int **) calloc(numero_de_linhas_grama, sizeof(int *)); //alocacao de uma matriz para o arquivo txt
        for(i_for =0; i_for<numero_de_linhas_grama; i_for++){
          matriz_grama_txt[i_for] = (int *) calloc(numero_de_colunas_grama, sizeof(int)); //alocacao das colunas da matriz com mesmo numero de linhas
        } //end for aloca ,matriz_grama_txt                                              // matriz quadrada

        if(matriz_grama_txt == NULL) printf("matriz_grama_txt NULL\n\n");

      //ler o .txt novamente e preencher a matriz_grama_txt
        rewind(file_para_grama); //o ponteiro deve voltar ao inicio do arquivo

        for(i_for = 0; i_for < numero_de_linhas_grama; i_for++){ //acesso as linhas
          for(j_for =0; j_for< numero_de_colunas_grama; j_for++){ //acesso as colunas
            if(feof(file_para_grama)){
              printf("END OF FILE %d\n", contador+1); //se o ponteiro chegar ao EOF
              break;
            }
            else fscanf(file_para_grama, "%d%c", &matriz_grama_txt[i_for][j_for], &ponto_e_virgula); //le o numero e o caractere
          }                                                                                         //armazena o numero na matriz
//printf("Elemento [][ultimo] %d\n", matriz_grama_txt[i_for][j_for-1]);
        }//end for preenche matriz

      //calcular a vizinhanca de 8 de cada pixel, armazenar no vetores_ILBP_grama correspondente
        rewind(file_para_grama);
        int soma_ILBP =0; //calcular o somatorio parcial
        int vetor_somas_parciais[9]; //9 somas parciais
        int menor_valor_no_somas_parciais =0;
        int avg_pixel =0; //media dos valores dos 8 vizinhos + pixel central

        for(i_for =1; i_for<numero_de_linhas_grama-1; i_for++){ //percorrer a matriz_grama_txt da linha 1 a linha 1023
          for(j_for =1; j_for<numero_de_colunas_grama-1; j_for++){// colunas de 1 a 1023 (elementos que tem 8 vizinhos)
            avg_pixel = (matriz_grama_txt[i_for-1][j_for-1]+matriz_grama_txt[i_for-1][j_for]+matriz_grama_txt[i_for-1][j_for+1]+
                         matriz_grama_txt[i_for][j_for-1]+matriz_grama_txt[i_for][j_for]+matriz_grama_txt[i_for][j_for+1]+
                         matriz_grama_txt[i_for+1][j_for-1]+matriz_grama_txt[i_for+1][j_for]+matriz_grama_txt[i_for+1][j_for+1])/9;

            for(int vizinho=0; vizinho<=8; vizinho++){
              for(int posicao_pixel=0; posicao_pixel<=8; posicao_pixel++){
                if((posicao_pixel+vizinho)%9==0){
                  soma_ILBP += s_function(matriz_grama_txt[i_for-1][j_for-1],avg_pixel)*pow(2,posicao_pixel);
                }//%0
                else if((posicao_pixel+vizinho)%9==1){
                  soma_ILBP += s_function(matriz_grama_txt[i_for-1][j_for],avg_pixel)*pow(2,posicao_pixel);
                }//%1
                else if((posicao_pixel+vizinho)%9==2){
                  soma_ILBP += s_function(matriz_grama_txt[i_for-1][j_for+1],avg_pixel)*pow(2,posicao_pixel);
                }//%2
                else if((posicao_pixel+vizinho)%9==3){
                  soma_ILBP += s_function(matriz_grama_txt[i_for][j_for-1],avg_pixel)*pow(2,posicao_pixel);
                }//%3
                else if((posicao_pixel+vizinho)%9==4){
                  soma_ILBP += s_function(matriz_grama_txt[i_for][j_for],avg_pixel)*pow(2,posicao_pixel);
                }//%4
                else if((posicao_pixel+vizinho)%9==5){
                  soma_ILBP += s_function(matriz_grama_txt[i_for][j_for+1],avg_pixel)*pow(2,posicao_pixel);
                }//%5
                else if((posicao_pixel+vizinho)%9==6){
                  soma_ILBP += s_function(matriz_grama_txt[i_for+1][j_for-1],avg_pixel)*pow(2,posicao_pixel);
                }//%6
                else if((posicao_pixel+vizinho)%9==7){
                  soma_ILBP += s_function(matriz_grama_txt[i_for+1][j_for],avg_pixel)*pow(2,posicao_pixel);
                }//%7
                else if((posicao_pixel+vizinho)%9==8){
                  soma_ILBP += s_function(matriz_grama_txt[i_for+1][j_for+1],avg_pixel)*pow(2,posicao_pixel);
                }//%8

              }//end for posicao_pixel
              vetor_somas_parciais[vizinho] = soma_ILBP;
              //if(soma_ILBP >511 || soma_ILBP<0) printf("************EEEEEEEEEEEEEEEEEEEEEEEEEPPPPPPPPPPPPPPPPPPAAAAAAAAAAAAAAA*************\n\n\n\n");
              soma_ILBP=0;

            }//end for vizinho

            //encontrar o menor valor no vetor_somas_parciais, ir no vetores_ILBP_grama[menor valor] e incrementar 1 unidade inteira
              menor_valor_no_somas_parciais = vetor_somas_parciais[0];
              for(int k=1; k<=8; k++){
                if(menor_valor_no_somas_parciais > vetor_somas_parciais[k]) menor_valor_no_somas_parciais = vetor_somas_parciais[k];
                else continue;

              }//end for achar menor_valor_no_somas_parciais

              //zerar o vetor_somas_parciais
                for(int k=0; k<=8; k++){
                  vetor_somas_parciais[k] = 0;
                }//end for zera vetor_somas_parciais

              //ir no vetores_ILBP_grama e incrementar
                vetores_ILBP_grama[contador][menor_valor_no_somas_parciais]+=1;

          }//end for colunas
        }//end for ILBP

//printf("i for : %d\nj for : %d\nFREE NIGGA %d\n", i_for, j_for, contador+1);
      free(matriz_grama_txt); //liberar o espaco em memoria

    //CALCULAR O GLCM



    //fim

    numero_de_colunas_grama =0; //atualizar para ler a proxima imagem
    numero_de_linhas_grama =0; //atualizar tambem

    fclose(file_para_grama);
    //printf("Fechei o %d\n", contador+1);
  }
  else printf("Erro ao abrir o arquivo %d\n", contador+1);

  contador ++;

}//end while abrir grama

printf("****************************************************************\n\nAsfalto\n\n");

contador = 0;

while(contador <numero_de_imagens){

  //printf("Aqui o erro\n");
  num_de_char_no_path_asfalto = sprintf(path_asfalto, "DataSet/asphalt/asphalt_%d%d.txt", vec_numeros[contador][0], vec_numeros[contador][1] );

  //printf("path asfalto = %s\n\n", path_asfalto);

  file_para_asfalto = fopen(path_asfalto, "r");

  if(file_para_asfalto != NULL){
    //printf("Abri o arquivo %d corretamente\n", contador+1);

    // CALCULAR O ILBP

      //encontrar o tamanho maximo da imagem .txt -> 1025 x 1025
      while(!feof(file_para_asfalto)){
        fscanf(file_para_asfalto, "%d%c", &numero_no_arquivo, &ponto_e_virgula);

        if(ponto_e_virgula == ';'){
          numero_de_colunas_asfalto ++;
        }
        else if(ponto_e_virgula == '\n'){
          numero_de_linhas_asfalto ++;
          numero_de_colunas_asfalto ++;
        }

        //fscanf(file_para_asfalto, "%d%c", &numero_no_arquivo, &ponto_e_virgula);//leia os proximos

      }//end of while feof asfalto

      //numero_de_colunas_asfalto += 1; //o ultimo numero do arquivo nao e seguido de ';'
      numero_de_linhas_asfalto -= 1; //a ultima quebra de linha do arquivo nao representa uma nova linha com elementos
      numero_de_colunas_asfalto /= numero_de_linhas_asfalto;
      //printf("Tamaho de colunas : %d\nNumero de linhas : %d\n\n", numero_de_colunas_asfalto, numero_de_linhas_asfalto);
      //printf("Ultimo Numero no arquivo : %d\nPonto e virgula : %c\n\n", numero_no_arquivo, ponto_e_virgula);

      //alocar dinamicamente uma matriz para armazenar os numeros do arquivo .txt e ler esses numeros

        int ** matriz_asfalto_txt = (int **) calloc(numero_de_linhas_asfalto, sizeof(int *)); //alocacao de uma matriz para o arquivo txt
        for(i_for =0; i_for<numero_de_linhas_asfalto; i_for++){
          matriz_asfalto_txt[i_for] = (int *) calloc(numero_de_colunas_asfalto, sizeof(int)); //alocacao das colunas da matriz com mesmo numero de linhas
        } //end for aloca ,matriz_asfalto_txt                                              // matriz quadrada

        if(matriz_asfalto_txt == NULL) printf("matriz_asfalto_txt NULL\n\n");

      //ler o .txt novamente e preencher a matriz_asfalto_txt
        rewind(file_para_asfalto); //o ponteiro deve voltar ao inicio do arquivo

        for(i_for = 0; i_for < numero_de_linhas_asfalto; i_for++){ //acesso as linhas
          for(j_for =0; j_for< numero_de_colunas_asfalto; j_for++){ //acesso as colunas
            if(feof(file_para_asfalto)){
              printf("END OF FILE %d\n", contador+1); //se o ponteiro chegar ao EOF
              break;
            }
            else fscanf(file_para_asfalto, "%d%c", &matriz_asfalto_txt[i_for][j_for], &ponto_e_virgula); //le o numero e o caractere
          }                                                                                         //armazena o numero na matriz
//printf("Elemento [][ultimo] %d\n", matriz_asfalto_txt[i_for][j_for-1]);
        }//end for preenche matriz

      //calcular a vizinhanca de 8 de cada pixel, armazenar no vetores_ILBP_asfalto correspondente
        rewind(file_para_asfalto);
        int soma_ILBP =0; //calcular o somatorio parcial
        int vetor_somas_parciais[9]; //9 somas parciais
        int menor_valor_no_somas_parciais =0;
        int avg_pixel =0; //media dos valores dos 8 vizinhos + pixel central

        for(i_for =1; i_for<numero_de_linhas_asfalto-1; i_for++){ //percorrer a matriz_asfalto_txt da linha 1 a linha 1023
          for(j_for =1; j_for<numero_de_colunas_asfalto-1; j_for++){// colunas de 1 a 1023 (elementos que tem 8 vizinhos)
            avg_pixel = (matriz_asfalto_txt[i_for-1][j_for-1]+matriz_asfalto_txt[i_for-1][j_for]+matriz_asfalto_txt[i_for-1][j_for+1]+
                         matriz_asfalto_txt[i_for][j_for-1]+matriz_asfalto_txt[i_for][j_for]+matriz_asfalto_txt[i_for][j_for+1]+
                         matriz_asfalto_txt[i_for+1][j_for-1]+matriz_asfalto_txt[i_for+1][j_for]+matriz_asfalto_txt[i_for+1][j_for+1])/9;

            for(int vizinho=0; vizinho<=8; vizinho++){
              for(int posicao_pixel=0; posicao_pixel<=8; posicao_pixel++){
                if((posicao_pixel+vizinho)%9==0){
                  soma_ILBP += s_function(matriz_asfalto_txt[i_for-1][j_for-1],avg_pixel)*pow(2,posicao_pixel);
                }//%0
                else if((posicao_pixel+vizinho)%9==1){
                  soma_ILBP += s_function(matriz_asfalto_txt[i_for-1][j_for],avg_pixel)*pow(2,posicao_pixel);
                }//%1
                else if((posicao_pixel+vizinho)%9==2){
                  soma_ILBP += s_function(matriz_asfalto_txt[i_for-1][j_for+1],avg_pixel)*pow(2,posicao_pixel);
                }//%2
                else if((posicao_pixel+vizinho)%9==3){
                  soma_ILBP += s_function(matriz_asfalto_txt[i_for][j_for-1],avg_pixel)*pow(2,posicao_pixel);
                }//%3
                else if((posicao_pixel+vizinho)%9==4){
                  soma_ILBP += s_function(matriz_asfalto_txt[i_for][j_for],avg_pixel)*pow(2,posicao_pixel);
                }//%4
                else if((posicao_pixel+vizinho)%9==5){
                  soma_ILBP += s_function(matriz_asfalto_txt[i_for][j_for+1],avg_pixel)*pow(2,posicao_pixel);
                }//%5
                else if((posicao_pixel+vizinho)%9==6){
                  soma_ILBP += s_function(matriz_asfalto_txt[i_for+1][j_for-1],avg_pixel)*pow(2,posicao_pixel);
                }//%6
                else if((posicao_pixel+vizinho)%9==7){
                  soma_ILBP += s_function(matriz_asfalto_txt[i_for+1][j_for],avg_pixel)*pow(2,posicao_pixel);
                }//%7
                else if((posicao_pixel+vizinho)%9==8){
                  soma_ILBP += s_function(matriz_asfalto_txt[i_for+1][j_for+1],avg_pixel)*pow(2,posicao_pixel);
                }//%8

              }//end for posicao_pixel
              vetor_somas_parciais[vizinho] = soma_ILBP;
              //if(soma_ILBP >511 || soma_ILBP<0) printf("************EEEEEEEEEEEEEEEEEEEEEEEEEPPPPPPPPPPPPPPPPPPAAAAAAAAAAAAAAA*************\n\n\n\n");
              soma_ILBP=0;

            }//end for vizinho

            //encontrar o menor valor no vetor_somas_parciais, ir no vetores_ILBP_asfalto[menor valor] e incrementar 1 unidade inteira
              menor_valor_no_somas_parciais = vetor_somas_parciais[0];
              for(int k=1; k<=8; k++){
                if(menor_valor_no_somas_parciais > vetor_somas_parciais[k]) menor_valor_no_somas_parciais = vetor_somas_parciais[k];
                else continue;

              }//end for achar menor_valor_no_somas_parciais

              //zerar o vetor_somas_parciais
                for(int k=0; k<=8; k++){
                  vetor_somas_parciais[k] = 0;
                }//end for zera vetor_somas_parciais

              //ir no vetores_ILBP_asfalto e incrementar
                vetores_ILBP_asfalto[contador][menor_valor_no_somas_parciais]+=1;

          }//end for colunas
        }//end for ILBP

//printf("i for : %d\nj for : %d\nFREE NIGGA %d\n", i_for, j_for, contador+1);
      free(matriz_asfalto_txt); //liberar o espaco em memoria

      //CALCULAR O GLCM



  //fim

    numero_de_colunas_asfalto =0; //atualizar para ler a proxima imagem
    numero_de_linhas_asfalto =0; //atualizar tambem

    fclose(file_para_asfalto);
  //  printf("Fechei o %d\n", contador+1);
  }
  else printf("Erro ao abrir o arquivo %d\n", contador+1);

  contador ++;

}//end while abre asfalto

printf("****************************************************************\n\n");
    // FIM DO PROGRAMA
//printf("vetores_ILBP_asfalto gerado : \n");
//  for(i_for=0; i_for<4; i_for++){
//    for(j_for=0; j_for<512; j_for++){
//      printf("%d ", vetores_ILBP_asfalto[i_for][j_for]);
//    }
//    printf("End line %d\n\n", i_for);
//  }


  return 0;
}
