#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define numero_de_imagens 50
#define qtd_metricas 24




int main(){

int contador = 0;

FILE *file_para_grama;
FILE *file_para_asfalto;

int  vec_numeros[50][2] = { {0,1}, {0,2}, {0,3}, {0,4}, {0,5}, {0,6}, {0,7}, {0,8}, {0,9}, {1,0},
                            {1,1}, {1,2}, {1,3}, {1,4}, {1,5}, {1,6}, {1,7}, {1,8}, {1,9}, {2,0},
                            {2,1}, {2,2}, {2,3}, {2,4}, {2,5}, {2,6}, {2,7}, {2,8}, {2,9}, {3,0},
                            {3,1}, {3,2}, {3,3}, {3,4}, {3,5}, {3,6}, {3,7}, {3,8}, {3,9}, {4,0},
                            {4,1}, {4,2}, {4,3}, {4,4}, {4,5}, {4,6}, {4,7}, {4,8}, {4,9}, {5,0} };
//printf("%d %d\n\n", vec_numeros[contador+2][0], vec_numeros[contador+2][1]);
char path_grama[100] ;
char full_path_grass[50][100];
char path_asfalto[100];
char full_path_asphalt[50][100];


int num_de_char_no_path_grama;
int num_de_char_no_path_asfalto;

while(contador < numero_de_imagens){


  num_de_char_no_path_grama = sprintf(path_grama, "/Users/caiovf13/Desktop/UnB/eda/Projeto02/DataSet/grass/grass_%d%d.txt", vec_numeros[contador][0], vec_numeros[contador][1]);

  //printf("path grama = %s\n\n", path_grama);

  file_para_grama = fopen(path_grama, "r");

  if(file_para_grama != NULL){
    printf("Abri o arquivo %d corretamente\n", contador+1);
    strcpy(full_path_grass[contador],path_grama);
    fclose(file_para_grama);
    printf("Fechei o %d\n", contador+1);
  }
  else printf("Erro ao abrir o arquivo %d\n", contador+1);

  contador ++;

}//end while abrir grama

for(int i=0;i<50;i++){
  printf("%s\n",full_path_grass[i]);
}

printf("****************************************************************\n\nAsfalto\n\n");

contador = 0;

while(contador <numero_de_imagens){

  //printf("Aqui o erro\n");
  num_de_char_no_path_asfalto = sprintf(path_asfalto, "/Users/caiovf13/Desktop/UnB/eda/Projeto02/DataSet/asphalt/asphalt_%d%d.txt", vec_numeros[contador][0], vec_numeros[contador][1] );

  //printf("path asfalto = %s\n\n", path_asfalto);

  file_para_asfalto = fopen(path_asfalto, "r");

  if(file_para_asfalto != NULL){
    printf("Abri o arquivo %d corretamente\n", contador+1);
    strcpy(full_path_asphalt[contador],path_asfalto);
    fclose(file_para_asfalto);
    printf("Fechei o %d\n", contador+1);
  }
  else printf("Erro ao abrir o arquivo %d\n", contador+1);

  contador ++;

}//end while abre asfalto

for(int i=0;i<50;i++){
  printf("%s\n",full_path_asphalt[i]);
}
FILE *fp_asphalt;
for(int i=0;i<50; i++){
  fp_asphalt = fopen(full_path_asphalt[i],"r");
    if(fp_asphalt == NULL){
      printf("FALHA!\n");
      exit(1);
    }
    else{
      printf("O AQRUIVO %d FOI ABERTO COM SUCESSO\n", (i+1));
    }
}
fclose(fp_asphalt);





printf("*******************************************************************************************\n");






double m_metricas_asphalt[qtd_metricas][numero_de_imagens],m_metricas_grass[qtd_metricas][numero_de_imagens];

 for(int i=0;i<numero_de_imagens;i++){ //CALCULO GLCM ASFALTO


int number,number_of_lines = 0, number_of_columns = 0, number_of_elements = 0; //Proprieades Matriz.
int biggest_element = 0; // Maior elemento da Matriz.
char aux; //Contador caracteres Matriz.

fp_asphalt = fopen(full_path_asphalt[i],"r");

while(!feof(fp_asphalt)){    //Conta elementos da Matriz e Seleciona o maior elemento.
  fscanf(fp_asphalt,"%d%c",&number,&aux);

  if(number > biggest_element)biggest_element = number;

  if(aux == ';'){
      number_of_elements +=1;
    }
    else if(aux == '\n'){
      number_of_lines +=1;
      number_of_elements+=1;
    }
   //printf(" %c",aux);
}
fclose(fp_asphalt);


number_of_lines -= 1;  //pois a matriz comeca com um "\n"
number_of_columns = number_of_elements/number_of_lines; // Matriz quadrada
printf("number_of_lines = %d\n number_of_columns = %d\n number_of_elements = %d\n biggest_element = %d\n",number_of_lines,number_of_columns,number_of_elements,biggest_element);


int *m_asphalt;
m_asphalt = (int *)malloc(number_of_columns*number_of_lines*sizeof(int)); //MATRIZ DA IMAGEM ALOCADA DINAMICAMENTE
if(m_asphalt == NULL)printf("ERRO AO ALOCAR m_asphalt\n");

int *glcm_horizontal_right;
glcm_horizontal_right = (int *)calloc(biggest_element*biggest_element,sizeof(int));//MATRIZ GLCM
if(glcm_horizontal_right == NULL)printf("ERRO AO ALOCAR glcm_horizontal_right\n");

int *glcm_horizontal_left;
glcm_horizontal_left = (int *)calloc(biggest_element*biggest_element,sizeof(int));//MATRIZ GLCM
if(glcm_horizontal_left == NULL)printf("ERRO AO ALOCAR glcm_horizontal_left\n");

int *glcm_vertical_up;
glcm_vertical_up = (int *)calloc(biggest_element*biggest_element,sizeof(int));//MATRIZ GLCM
if(glcm_vertical_up == NULL)printf("ERRO AO ALOCAR glcm_vertical_up\n");

int *glcm_vertical_down;
glcm_vertical_down = (int *)calloc(biggest_element*biggest_element,sizeof(int));//MATRIZ GLCM
if(glcm_vertical_down == NULL)printf("ERRO AO ALOCAR glcm_vertical_down\n");

int *glcm_diagonal_135;
glcm_diagonal_135 = (int *)calloc(biggest_element*biggest_element,sizeof(int));//MATRIZ GLCM
if(glcm_diagonal_135 == NULL)printf("ERRO AO ALOCAR glcm_diagonal_135\n");

int *glcm_diagonal_45;
glcm_diagonal_45 = (int *)calloc(biggest_element*biggest_element,sizeof(int));//MATRIZ GLCM
if(glcm_diagonal_45 == NULL)printf("ERRO AO ALOCAR glcm_diagonal_45\n");

int *glcm_diagonal_225;
glcm_diagonal_225 = (int *)calloc(biggest_element*biggest_element,sizeof(int));//MATRIZ GLCM
if(glcm_diagonal_225 == NULL)printf("ERRO AO ALOCAR glcm_diagonal_225\n");

int *glcm_diagonal_315;
glcm_diagonal_315 = (int *)calloc(biggest_element*biggest_element,sizeof(int));//MATRIZ GLCM
if(glcm_diagonal_315 == NULL)printf("ERRO AO ALOCAR glcm_diagonal_315\n");

file_para_asfalto = fopen(full_path_asphalt[0],"r"); //ABERTURA DO ARQUIVO .TXT DE ASFALTO
if(file_para_asfalto == NULL){
  printf("Cannot open the file\n");
}


for(int i=0; i<number_of_lines;i++){ //FUNCAO QUE ADICIONA À MATRIZ ALOCADA OS VALORES DA MATRIZ .TXT
  for(int j=0; j<number_of_columns;j++){
    int x = 0;
    char ch;
        fscanf(file_para_asfalto,"%d",&x);
        ch = getc(file_para_asfalto);
        //printf("%d ",x);
        //putchar(ch);
        //printf("\n");
        *(m_asphalt+(i*number_of_columns)+j) = x;
  }
}

fclose(file_para_asfalto);


  for(int i = 0; i<number_of_lines; i++){ //PRINTA A MATRIZ ALOCADA m_asphalt;
    for(int j = 0; j<number_of_columns; j++){
    //  printf("%d ",*(m_asphalt+(i*number_of_columns)+j));
    }
    //printf("\n");
  }

  /*for(int i=0;i<biggest_element;i++){ //ESTRUTURA QUE PRINTA ALGUMA MATRIZ GLCM PREENCHIDA POR 0's DO CALLOC
    for(int j=0;j<biggest_element;j++){
      printf("%d ",*(glcm+(i*biggest_element )+j));
    }
    printf("\n");
  }*/



  for(int i=0; i<number_of_lines;i++){
      for(int j=0; j<number_of_columns; j++){


        if((i!=0 && i!=(number_of_lines-1)) && (j!=0 && j!=(number_of_columns-1))){
          int glcm_h_right=0, glcm_h_left=0, glcm_v_up=0, glcm_v_down=0, glcm_d_45=0,glcm_d_135=0, glcm_d_315=0, glcm_d_225=0;

          int x =  *(m_asphalt+(i*number_of_columns)+j);//valor da m_asphalt[i][j]

          glcm_h_right= *(m_asphalt+(i*number_of_columns)+(j+1));//valor da posicao m_asphalt[i][j+1]
          *(glcm_horizontal_right+(x*biggest_element)+glcm_h_right)+=1;//incremento na matriz glcm_horizontal_right

          glcm_h_left = *(m_asphalt+(i*number_of_columns)+(j-1));//valor da posicao m_asphalt[i][j-1]
          *(glcm_horizontal_left+(x*biggest_element)+glcm_h_left)+=1;//incremento na matriz glcm_horizontal_left

          glcm_v_up = *(m_asphalt+((i-1)*number_of_columns)+j);//valor da posicao m_asphalt[i-1][j]
          *(glcm_vertical_up+(x*biggest_element)+glcm_v_up)+=1;//incremento na matriz glcm_vertical_up

          glcm_v_down = *(m_asphalt+((i+1)*number_of_columns)+j);//valor da posicao m_asphalt[i+1][j]
          *(glcm_vertical_down+(x*biggest_element)+glcm_v_down)+=1;//incremento na matriz glcm_vertical_down

          glcm_d_45 = *(m_asphalt+((i-1)*number_of_columns)+(j+1));//valor da posicao m_asphalt[i-1][j+1]
          *(glcm_diagonal_45+(x*biggest_element)+glcm_d_45)+=1;//incremento na matriz glcm_diagonal_45

          glcm_d_135 = *(m_asphalt+((i-1)*number_of_columns)+(j-1));//valor da posicao m_asphalt[i-1][j-1]
          *(glcm_diagonal_135+(x*biggest_element)+glcm_d_135)+=1;//incremento na matriz glcm_diagonal_135

          glcm_d_315 = *(m_asphalt+((i+1)*number_of_columns)+(j+1));//valor da posicao m_asphalt[i+1][j+1]
          *(glcm_diagonal_315+(x*biggest_element)+glcm_d_315)+=1;//incremento na matriz glcm_diagonal_315

          glcm_d_225 = *(m_asphalt+((i+1)*number_of_columns)+(j-1));//valor da posicao m_asphalt[i+1][j-1]
          *(glcm_diagonal_225+(x*biggest_element)+glcm_d_225)+=1;//incremento na matriz glcm_diagonal_225

        }
        else{

          if(i==0 && j==0){ //Quando m_asphalt[0][0]
            int glcm_h_right=0, glcm_v_down=0, glcm_d_315=0;

            int x =  *(m_asphalt+(i*number_of_columns)+j);//valor da m_asphalt[i][j]

            glcm_h_right = *(m_asphalt+(i*number_of_columns)+(j+1));
            *(glcm_horizontal_right+(x*biggest_element)+glcm_h_right)+=1;

            glcm_v_down = *(m_asphalt+((i+1)*number_of_columns)+j);
            *(glcm_vertical_down+(x*biggest_element)+glcm_v_down)+=1;

            glcm_d_315 = *(m_asphalt+((i+1)*number_of_columns)+(j+1));
            *(glcm_diagonal_315+(x*biggest_element)+glcm_d_315)+=1;
          }

          else if(i==0 && j==(number_of_columns-1)){//Quando m_asphalt[0][(number_of_columns-1)]
            int glcm_h_left=0, glcm_v_down=0, glcm_d_225=0;

            int x =  *(m_asphalt+(i*number_of_columns)+j);//valor da m_asphalt[i][j]

            glcm_h_left = *(m_asphalt+(i*number_of_columns)+(j-1));//valor da posicao m_asphalt[i][j-1]
            *(glcm_horizontal_left+(x*biggest_element)+glcm_h_left)+=1;//incremento na matriz glcm_horizontal_left

            glcm_d_225 = *(m_asphalt+((i+1)*number_of_columns)+(j-1));//valor da posicao m_asphalt[i+1][j-1]
            *(glcm_diagonal_225+(x*biggest_element)+glcm_d_225)+=1;//incremento na matriz glcm_diagonal_225

            glcm_v_down = *(m_asphalt+((i+1)*number_of_columns)+j);//valor da posicao m_asphalt[i+1][j]
            *(glcm_vertical_down+(x*biggest_element)+glcm_v_down)+=1;//incremento na matriz glcm_vertical_down
          }

          else if(i==(number_of_lines-1) && j==0){//Quando m_asphalt[(number_of_lines-1)][0]
            int glcm_h_right=0, glcm_v_up=0, glcm_d_45=0;

            int x =  *(m_asphalt+(i*number_of_columns)+j);//valor da m_asphalt[i][j]

            glcm_h_right = *(m_asphalt+(i*number_of_columns)+(j+1));
            *(glcm_horizontal_right+(x*biggest_element)+glcm_h_right)+=1;

            glcm_v_up = *(m_asphalt+((i-1)*number_of_columns)+j);//valor da posicao m_asphalt[i-1][j]
            *(glcm_vertical_up+(x*biggest_element)+glcm_v_up)+=1;//incremento na matriz glcm_vertical_up

            glcm_d_45 = *(m_asphalt+((i-1)*number_of_columns)+(j+1));//valor da posicao m_asphalt[i-1][j+1]
            *(glcm_diagonal_45+(x*biggest_element)+glcm_d_45)+=1;//incremento na matriz glcm_diagonal_45
          }

          else if(i==(number_of_lines-1) && j==(number_of_columns-1)){//Quando m_asphalt[(number_of_lines-1)][(number_of_columns-1)]
            int  glcm_h_left=0, glcm_v_up=0, glcm_d_135=0;

            int x =  *(m_asphalt+(i*number_of_columns)+j);//valor da m_asphalt[i][j]

            glcm_h_left = *(m_asphalt+(i*number_of_columns)+(j-1));//valor da posicao m_asphalt[i][j-1]
            *(glcm_horizontal_left+(x*biggest_element)+glcm_h_left)+=1;//incremento na matriz glcm_horizontal_left

            glcm_v_up = *(m_asphalt+((i-1)*number_of_columns)+j);//valor da posicao m_asphalt[i-1][j]
            *(glcm_vertical_up+(x*biggest_element)+glcm_v_up)+=1;//incremento na matriz glcm_vertical_up

            glcm_d_135 = *(m_asphalt+((i-1)*number_of_columns)+(j-1));//valor da posicao m_asphalt[i-1][j-1]
            *(glcm_diagonal_135+(x*biggest_element)+glcm_d_135)+=1;//incremento na matriz glcm_diagonal_135
          }

          else if((j>0 && j<(number_of_columns-1)) && (i == 0 )){ //Quando m_asphalt[0][0< i <(number_of_columns-1)]
            int glcm_h_right=0, glcm_h_left=0, glcm_v_down=0, glcm_d_315=0, glcm_d_225=0;

            int x =  *(m_asphalt+(i*number_of_columns)+j);//valor da m_asphalt[i][j]

            glcm_h_right= *(m_asphalt+(i*number_of_columns)+(j+1));//valor da posicao m_asphalt[i][j+1]
            *(glcm_horizontal_right+(x*biggest_element)+glcm_h_right)+=1;//incremento na matriz glcm_horizontal_right

            glcm_h_left = *(m_asphalt+(i*number_of_columns)+(j-1));//valor da posicao m_asphalt[i][j-1]
            *(glcm_horizontal_left+(x*biggest_element)+glcm_h_left)+=1;//incremento na matriz glcm_horizontal_left

            glcm_v_down = *(m_asphalt+((i+1)*number_of_columns)+j);//valor da posicao m_asphalt[i+1][j]
            *(glcm_vertical_down+(x*biggest_element)+glcm_v_down)+=1;//incremento na matriz glcm_vertical_down

            glcm_d_315 = *(m_asphalt+((i+1)*number_of_columns)+(j+1));//valor da posicao m_asphalt[i+1][j+1]
            *(glcm_diagonal_315+(x*biggest_element)+glcm_d_315)+=1;//incremento na matriz glcm_diagonal_315

            glcm_d_225 = *(m_asphalt+((i+1)*number_of_columns)+(j-1));//valor da posicao m_asphalt[i+1][j-1]
            *(glcm_diagonal_225+(x*biggest_element)+glcm_d_225)+=1;//incremento na matriz glcm_diagonal_225
          }

          else if((i>0 && i<(number_of_lines-1)) && j==0){
            int glcm_h_right=0, glcm_v_up=0, glcm_v_down=0, glcm_d_45=0, glcm_d_315=0;

            int x =  *(m_asphalt+(i*number_of_columns)+j);//valor da m_asphalt[i][j]

            glcm_h_right= *(m_asphalt+(i*number_of_columns)+(j+1));//valor da posicao m_asphalt[i][j+1]
            *(glcm_horizontal_right+(x*biggest_element)+glcm_h_right)+=1;//incremento na matriz glcm_horizontal_right

            glcm_v_down = *(m_asphalt+((i+1)*number_of_columns)+j);//valor da posicao m_asphalt[i+1][j]
            *(glcm_vertical_down+(x*biggest_element)+glcm_v_down)+=1;//incremento na matriz glcm_vertical_down

            glcm_d_315 = *(m_asphalt+((i+1)*number_of_columns)+(j+1));//valor da posicao m_asphalt[i+1][j+1]
            *(glcm_diagonal_315+(x*biggest_element)+glcm_d_315)+=1;//incremento na matriz glcm_diagonal_315

            glcm_v_up = *(m_asphalt+((i-1)*number_of_columns)+j);//valor da posicao m_asphalt[i-1][j]
            *(glcm_vertical_up+(x*biggest_element)+glcm_v_up)+=1;//incremento na matriz glcm_vertical_up
          }

          else if((i == (number_of_lines-1)) && (j>0 && j < (number_of_columns-1))){
            int glcm_h_right=0, glcm_h_left=0, glcm_v_up=0, glcm_d_45=0,glcm_d_135=0;

            int x =  *(m_asphalt+(i*number_of_columns)+j);//valor da m_asphalt[i][j]

            glcm_h_right= *(m_asphalt+(i*number_of_columns)+(j+1));//valor da posicao m_asphalt[i][j+1]
            *(glcm_horizontal_right+(x*biggest_element)+glcm_h_right)+=1;//incremento na matriz glcm_horizontal_right

            glcm_v_up = *(m_asphalt+((i-1)*number_of_columns)+j);//valor da posicao m_asphalt[i-1][j]
            *(glcm_vertical_up+(x*biggest_element)+glcm_v_up)+=1;//incremento na matriz glcm_vertical_up

            glcm_h_left = *(m_asphalt+(i*number_of_columns)+(j-1));//valor da posicao m_asphalt[i][j-1]
            *(glcm_horizontal_left+(x*biggest_element)+glcm_h_left)+=1;//incremento na matriz glcm_horizontal_left

            glcm_d_135 = *(m_asphalt+((i-1)*number_of_columns)+(j-1));//valor da posicao m_asphalt[i-1][j-1]
            *(glcm_diagonal_135+(x*biggest_element)+glcm_d_135)+=1;//incremento na matriz glcm_diagonal_135

            glcm_d_45 = *(m_asphalt+((i-1)*number_of_columns)+(j+1));//valor da posicao m_asphalt[i-1][j+1]
            *(glcm_diagonal_45+(x*biggest_element)+glcm_d_45)+=1;//incremento na matriz glcm_diagonal_45

          }

          else if((i>0 && i<(number_of_lines-1)) && j==(number_of_columns-1)){
            int  glcm_h_left=0, glcm_v_up=0, glcm_v_down=0, glcm_d_135=0, glcm_d_225=0;

            int x =  *(m_asphalt+(i*number_of_columns)+j);//valor da m_asphalt[i][j]

            glcm_h_left = *(m_asphalt+(i*number_of_columns)+(j-1));//valor da posicao m_asphalt[i][j-1]
            *(glcm_horizontal_left+(x*biggest_element)+glcm_h_left)+=1;//incremento na matriz glcm_horizontal_left

            glcm_v_up = *(m_asphalt+((i-1)*number_of_columns)+j);//valor da posicao m_asphalt[i-1][j]
            *(glcm_vertical_up+(x*biggest_element)+glcm_v_up)+=1;//incremento na matriz glcm_vertical_up

            glcm_d_135 = *(m_asphalt+((i-1)*number_of_columns)+(j-1));//valor da posicao m_asphalt[i-1][j-1]
            *(glcm_diagonal_135+(x*biggest_element)+glcm_d_135)+=1;//incremento na matriz glcm_diagonal_135

            glcm_v_down = *(m_asphalt+((i+1)*number_of_columns)+j);//valor da posicao m_asphalt[i+1][j]
            *(glcm_vertical_down+(x*biggest_element)+glcm_v_down)+=1;//incremento na matriz glcm_vertical_down

            glcm_d_225 = *(m_asphalt+((i+1)*number_of_columns)+(j-1));//valor da posicao m_asphalt[i+1][j-1]
            *(glcm_diagonal_225+(x*biggest_element)+glcm_d_225)+=1;//incremento na matriz glcm_diagonal_225

          }

        }
      }
  }

  /*for(int i=0; i<biggest_element;i++){
    for(int j=0;j<biggest_element;j++){
      printf("%d ",*(glcm_horizontal_right+(i*biggest_element)+j));
    }
    printf("\n");
  }
  printf("\n\n\n\n\n\n\n******************************************************************\n");

  for(int i=0; i<biggest_element;i++){
    for(int j=0;j<biggest_element;j++){
      printf("%d ",*(glcm_horizontal_left+(i*biggest_element)+j));
    }
    printf("\n");
  }

  for(int i=0; i<biggest_element;i++){
    for(int j=0;j<biggest_element;j++){
      printf("%d ",*(glcm_vertical_up+(i*biggest_element)+j));
    }
    printf("\n");
  }

  for(int i=0; i<biggest_element;i++){
    for(int j=0;j<biggest_element;j++){
      printf("%d ",*(glcm_vertical_down+(i*biggest_element)+j));
    }
    printf("\n");
  }

  for(int i=0; i<biggest_element;i++){
    for(int j=0;j<biggest_element;j++){
      printf("%d ",*(glcm_diagonal_45+(i*biggest_element)+j));
    }
    printf("\n");
  }

  for(int i=0; i<biggest_element;i++){
    for(int j=0;j<biggest_element;j++){
      printf("%d ",*(glcm_diagonal_135+(i*biggest_element)+j));
    }
    printf("\n");
  }

  for(int i=0; i<biggest_element;i++){
    for(int j=0;j<biggest_element;j++){
      printf("%d ",*(glcm_diagonal_225+(i*biggest_element)+j));
    }
    printf("\n");
  }
*/

//NORMALIZANDO GLCMS

//CRIANDO NOVAS MATRIZES COM OS VALORES NORMALIZADOS

double *normalized_glcm_horizontal_right;
normalized_glcm_horizontal_right = (double *)calloc(biggest_element*biggest_element,sizeof(double));//MATRIZ GLCM
if(normalized_glcm_horizontal_right == NULL)printf("ERRO AO ALOCAR normalized_glcm_horizontal_right\n");

double *normalized_glcm_horizontal_left;
normalized_glcm_horizontal_left = (double *)calloc(biggest_element*biggest_element,sizeof(double));//MATRIZ GLCM
if(normalized_glcm_horizontal_left == NULL)printf("ERRO AO ALOCAR normalized_glcm_horizontal_left\n");

double *normalized_glcm_vertical_up;
normalized_glcm_vertical_up = (double *)calloc(biggest_element*biggest_element,sizeof(double));//MATRIZ GLCM
if(normalized_glcm_vertical_up == NULL)printf("ERRO AO ALOCAR normalized_glcm_vertical_up\n");

double *normalized_glcm_vertical_down;
normalized_glcm_vertical_down = (double *)calloc(biggest_element*biggest_element,sizeof(double));//MATRIZ GLCM
if(normalized_glcm_vertical_down == NULL)printf("ERRO AO ALOCAR normalized_glcm_vertical_down\n");

double *normalized_glcm_diagonal_135;
normalized_glcm_diagonal_135 = (double *)calloc(biggest_element*biggest_element,sizeof(double));//MATRIZ GLCM
if(normalized_glcm_diagonal_135 == NULL)printf("ERRO AO ALOCAR glcm_diagonal_135\n");

double *normalized_glcm_diagonal_45;
normalized_glcm_diagonal_45 = (double *)calloc(biggest_element*biggest_element,sizeof(double));//MATRIZ GLCM
if(normalized_glcm_diagonal_45 == NULL)printf("ERRO AO ALOCAR normalized_glcm_diagonal_45\n");

double *normalized_glcm_diagonal_225;
normalized_glcm_diagonal_225 = (double *)calloc(biggest_element*biggest_element,sizeof(double));//MATRIZ GLCM
if(normalized_glcm_diagonal_225 == NULL)printf("ERRO AO ALOCAR normalized_glcm_diagonal_225\n");

double *normalized_glcm_diagonal_315;
normalized_glcm_diagonal_315 = (double *)calloc(biggest_element*biggest_element,sizeof(double));//MATRIZ GLCM
if(normalized_glcm_diagonal_315 == NULL)printf("ERRO AO ALOCAR normalized_glcm_diagonal_315\n");

double soma_dos_elementos_horizontalz_right=0, soma_dos_elementos_horizontalz_left=0, soma_dos_elementos_vertical_up=0,
soma_dos_elementos_vertical_down=0, soma_dos_elementos_diagonal_45=0, soma_dos_elementos_diagonal_135=0, soma_dos_elementos_diagonal_225=0, soma_dos_elementos_diagonal_315=0;
for(int i=0;i<biggest_element;i++){
  for(int j=0;j<biggest_element;j++){
    soma_dos_elementos_horizontalz_right += *(glcm_horizontal_right+(i*biggest_element)+j);
    soma_dos_elementos_horizontalz_left += *(glcm_horizontal_left+(i*biggest_element)+j);
    soma_dos_elementos_vertical_up += *(glcm_vertical_up+(i*biggest_element)+j);
    soma_dos_elementos_vertical_down += *(glcm_vertical_down+(i*biggest_element)+j);
    soma_dos_elementos_diagonal_45 += *(glcm_diagonal_45+(i*biggest_element)+j);
    soma_dos_elementos_diagonal_135 += *(glcm_diagonal_135+(i*biggest_element)+j);
    soma_dos_elementos_diagonal_225 += *(glcm_diagonal_225+(i*biggest_element)+j);
    soma_dos_elementos_diagonal_315 += *(glcm_diagonal_315+(i*biggest_element)+j);
  }
}

printf("soma_dos_elementos_horizontalz_right = %.2lf\n soma_dos_elementos_horizontalz_left = %.10lf\n soma_dos_elementos_vertical_down = %.10lf\n soma_dos_elementos_vertical_up = %.10lf\n soma_dos_elementos_diagonal_45 = %.10lf\n soma_dos_elementos_diagonal_135 = %.10lf\n soma_dos_elementos_diagonal_225 = %.10lf\n soma_dos_elementos_diagonal_315= %.10lf\n",soma_dos_elementos_horizontalz_right, soma_dos_elementos_horizontalz_left, soma_dos_elementos_vertical_down, soma_dos_elementos_vertical_up, soma_dos_elementos_diagonal_45, soma_dos_elementos_diagonal_135, soma_dos_elementos_diagonal_225, soma_dos_elementos_diagonal_315);

for(int i=0;i<biggest_element;i++){
  for(int j=0;j<biggest_element;j++){
    *(normalized_glcm_horizontal_right+(i*biggest_element)+j) = (*(glcm_horizontal_right+(i*biggest_element)+j) / soma_dos_elementos_horizontalz_right);
    *(normalized_glcm_horizontal_left+(i*biggest_element)+j) = *(glcm_horizontal_left+(i*biggest_element)+j)/ soma_dos_elementos_horizontalz_left;
    *(normalized_glcm_vertical_up+(i*biggest_element)+j) = *(glcm_vertical_up+(i*biggest_element)+j)/ soma_dos_elementos_vertical_up;
    *(normalized_glcm_vertical_down+(i*biggest_element)+j) = *(glcm_vertical_down+(i*biggest_element)+j)/  soma_dos_elementos_vertical_down;
    *(normalized_glcm_diagonal_45+(i*biggest_element)+j) = *(glcm_diagonal_45+(i*biggest_element)+j)/   soma_dos_elementos_diagonal_45;
    *(normalized_glcm_diagonal_135+(i*biggest_element)+j) = *(glcm_diagonal_135+(i*biggest_element)+j)/   soma_dos_elementos_diagonal_135;
    *(normalized_glcm_diagonal_225+(i*biggest_element)+j) = *(glcm_diagonal_225+(i*biggest_element)+j)/   soma_dos_elementos_diagonal_225;
    *(normalized_glcm_diagonal_315+(i*biggest_element)+j) = (*(glcm_diagonal_315+(i*biggest_element)+j)/  soma_dos_elementos_diagonal_315);
  }
}
double lol = 0, lol1 = 0, lol2 = 0, lol3 = 0, lol4 = 0, lol5 = 0, lol6 = 0, lol7 = 0;
for(int i=0;i<biggest_element;i++){
  for(int j=0; j<biggest_element;j++){
    lol+= *(normalized_glcm_horizontal_right+(i*biggest_element)+j);
    lol1+= *(normalized_glcm_horizontal_left+(i*biggest_element)+j);
    lol2+= *(normalized_glcm_vertical_up+(i*biggest_element)+j);
    lol3+= *(normalized_glcm_vertical_down+(i*biggest_element)+j);
    lol4+= *(normalized_glcm_diagonal_45+(i*biggest_element)+j);
    lol5+= *(normalized_glcm_diagonal_135+(i*biggest_element)+j);
    lol6+= *(normalized_glcm_diagonal_225+(i*biggest_element)+j);
    lol7+= *(normalized_glcm_diagonal_315+(i*biggest_element)+j);
  }
  printf("\n");
}
printf("%.10lf\n %.10lf\n %.10lf\n %.10lf\n %.10lf\n %.10lf\n %.10lf\n %.10lf\n",lol,lol1,lol2,lol3,lol4,lol5,lol6,lol7); //PROVA QUE AS MATRIZES FORAM NORMALIZADAS DE MANEIRA CORRETA. POIS A SOMA DE SEUS ELEMENTOS É IGUAL A "1".

//FIM DAS NORMALIZAÇÕES

 //FEATURE GLCM.1 - CONTRAST:


double contraste_glcm_horizontal_right=0, contraste_glcm_horizontal_left=0, contraste_glcm_vertical_up=0, contraste_glcm_vertical_down=0,
contraste_glcm_diagonal_45=0, contraste_glcm_diagonal_135=0, contraste_glcm_diagonal_225=0, contraste_glcm_diagonal_315=0;
for(int i=0; i<biggest_element; i++){
  for(int j=0; j<biggest_element; j++){
    contraste_glcm_horizontal_right+= ((i-j)*(i-j))*(*(normalized_glcm_horizontal_right+(i*biggest_element)+j));
    contraste_glcm_horizontal_left+= ((i-j)*(i-j))*(*(normalized_glcm_horizontal_left+(i*biggest_element)+j));
    contraste_glcm_vertical_up+= ((i-j)*(i-j))*(*(normalized_glcm_vertical_up+(i*biggest_element)+j));
    contraste_glcm_vertical_down+= ((i-j)*(i-j))*(*(normalized_glcm_vertical_down+(i*biggest_element)+j));
    contraste_glcm_diagonal_45+= ((i-j)*(i-j))*(*(normalized_glcm_diagonal_45+(i*biggest_element)+j));
    contraste_glcm_diagonal_135+= ((i-j)*(i-j))*(*(normalized_glcm_diagonal_135+(i*biggest_element)+j));
    contraste_glcm_diagonal_225+= ((i-j)*(i-j))*(*(normalized_glcm_diagonal_225+(i*biggest_element)+j));
    contraste_glcm_diagonal_315+= ((i-j)*(i-j))*(*(normalized_glcm_diagonal_315+(i*biggest_element)+j));
  }
}
printf("contraste_glcm_horizontal_right = %.10lf\n contraste_glcm_horizontal_left = %.10lf\n contraste_glcm_vertical_up = %.10lf\n contraste_glcm_vertical_down = %.10lf\ncontraste_glcm_diagonal_45 = %.10lf\n contraste_glcm_diagonal_135 = %.10lf\n contraste_glcm_diagonal_225 = %.10lf\n contraste_glcm_diagonal_335 = %.10lf\n ", contraste_glcm_horizontal_right, contraste_glcm_horizontal_left,contraste_glcm_vertical_up,contraste_glcm_vertical_down,contraste_glcm_diagonal_45,contraste_glcm_diagonal_135, contraste_glcm_diagonal_225, contraste_glcm_diagonal_315);
printf("---------------------------------------//---------------------------------------//---------------------------------------//---------------------------------------\n\n\n\n\n");

//-----------------------------//---------------------//-------

//FEATURE GLCM.10 - Energy:
double energy_glcm_horizontal_right=0, energy_glcm_horizontal_left=0, energy_glcm_vertical_up=0, energy_glcm_vertical_down=0, energy_glcm_diagonal_45=0, energy_glcm_diagonal_135=0, energy_glcm_diagonal_225=0, energy_glcm_diagonal_315=0;
for(int i=0;i<biggest_element;i++){
  for(int j=0; j<biggest_element; j++){
    energy_glcm_horizontal_right += ( (*(normalized_glcm_horizontal_right+(i*biggest_element)+j)) * (*(normalized_glcm_horizontal_right+(i*biggest_element)+j)));
    energy_glcm_horizontal_left += ( (*(normalized_glcm_horizontal_left+(i*biggest_element)+j)) * (*(normalized_glcm_horizontal_left+(i*biggest_element)+j)));
    energy_glcm_vertical_up += ( (*(normalized_glcm_vertical_up+(i*biggest_element)+j)) * (*(normalized_glcm_vertical_up+(i*biggest_element)+j)));
    energy_glcm_vertical_down += ( (*(normalized_glcm_vertical_down+(i*biggest_element)+j)) * (*(normalized_glcm_vertical_down+(i*biggest_element)+j)));
    energy_glcm_diagonal_45 += ( (*(normalized_glcm_diagonal_45+(i*biggest_element)+j)) * (*(normalized_glcm_diagonal_45+(i*biggest_element)+j)));
    energy_glcm_diagonal_135 += ( (*(normalized_glcm_diagonal_135+(i*biggest_element)+j)) * (*(normalized_glcm_diagonal_135+(i*biggest_element)+j)));
    energy_glcm_diagonal_225 += ( (*(normalized_glcm_diagonal_225+(i*biggest_element)+j)) * (*(normalized_glcm_diagonal_225+(i*biggest_element)+j)));
    energy_glcm_diagonal_315 += ( (*(normalized_glcm_diagonal_315+(i*biggest_element)+j)) * (*(normalized_glcm_diagonal_315+(i*biggest_element)+j)));

  }
}
printf("energy_glcm_horizontal_right = %.10lf\n energy_glcm_horizontal_left = %.10lf\n energy_glcm_vertical_up = %.10lf\n energy_glcm_vertical_down = %.10lf\n energy_glcm_diagonal_45 = %.10lf\n energy_glcm_diagonal_135 = %.10lf\n energy_glcm_diagonal_225 = %.10lf\n energy_glcm_diagonal_315 = %.10lf\n" , energy_glcm_horizontal_right, energy_glcm_horizontal_left, energy_glcm_vertical_up, energy_glcm_vertical_down, energy_glcm_diagonal_45, energy_glcm_diagonal_135, energy_glcm_diagonal_225, energy_glcm_diagonal_315);
printf("---------------------------------------//---------------------------------------//---------------------------------------//---------------------------------------\n\n\n\n\n");


//-----------------------------//---------------------//-------

//FEATURE GLCM.3 - Homogeneity
double homogeneity_glcm_horizontal_right = 0, homogeneity_glcm_horizontal_left=0, homogeneity_glcm_vertical_up=0, homogeneity_glcm_vertical_down=0, homogeneity_glcm_diagonal_45=0, homogeneity_glcm_diagonal_135=0, homogeneity_glcm_diagonal_225=0, homogeneity_glcm_diagonal_315=0;

for(int i=0; i<biggest_element; i++){
  for(int j=0;j<biggest_element; j++){
    homogeneity_glcm_horizontal_right += ((*(normalized_glcm_horizontal_right+(i*biggest_element)+j))/(1+sqrt((i-j)*(i-j))));
    homogeneity_glcm_horizontal_left += ((*(normalized_glcm_horizontal_left+(i*biggest_element)+j))/(1+sqrt((i-j)*(i-j))));
    homogeneity_glcm_vertical_up += ((*(normalized_glcm_vertical_up+(i*biggest_element)+j))/(1+sqrt((i-j)*(i-j))));
    homogeneity_glcm_vertical_down += ((*(normalized_glcm_vertical_down+(i*biggest_element)+j))/(1+sqrt((i-j)*(i-j))));
    homogeneity_glcm_diagonal_45 += ((*(normalized_glcm_diagonal_45+(i*biggest_element)+j))/(1+sqrt((i-j)*(i-j))));
    homogeneity_glcm_diagonal_135 += ((*(normalized_glcm_diagonal_135+(i*biggest_element)+j))/(1+sqrt((i-j)*(i-j))));
    homogeneity_glcm_diagonal_225 += ((*(normalized_glcm_diagonal_225+(i*biggest_element)+j))/(1+sqrt((i-j)*(i-j))));
    homogeneity_glcm_diagonal_315 += ((*(normalized_glcm_diagonal_315+(i*biggest_element)+j))/(1+sqrt((i-j)*(i-j))));
  }
}
printf("homogeneity_glcm_horizontal_right = %.10lf\n homogeneity_glcm_horizontal_left %.10lf\n homogeneity_glcm_vertical_up %.10lf\n homogeneity_glcm_vertical_down %.10lf\n homogeneity_glcm_diagonal_45 %.10lf\n homogeneity_glcm_diagonal_135 %.10lf\n homogeneity_glcm_diagonal_225 %.10lf\n homogeneity_glcm_diagonal_315 %.10lf\n ",homogeneity_glcm_horizontal_right, homogeneity_glcm_horizontal_left, homogeneity_glcm_vertical_up, homogeneity_glcm_vertical_down, homogeneity_glcm_diagonal_45, homogeneity_glcm_diagonal_135, homogeneity_glcm_diagonal_225, homogeneity_glcm_diagonal_315 );
printf("---------------------------------------//---------------------------------------//---------------------------------------//---------------------------------------\n\n\n\n\n");

      m_metricas_asphalt[0][i] = contraste_glcm_horizontal_right;
      m_metricas_asphalt[1][i] = contraste_glcm_horizontal_left;
      m_metricas_asphalt[2][i] = contraste_glcm_vertical_up;
      m_metricas_asphalt[3][i] = contraste_glcm_vertical_down;
      m_metricas_asphalt[4][i] = contraste_glcm_diagonal_45;
      m_metricas_asphalt[5][i] = contraste_glcm_diagonal_135;
      m_metricas_asphalt[6][i] = contraste_glcm_diagonal_225;
      m_metricas_asphalt[7][i] = contraste_glcm_diagonal_315;
      m_metricas_asphalt[8][i] = energy_glcm_horizontal_right;
      m_metricas_asphalt[9][i] = energy_glcm_horizontal_left;
      m_metricas_asphalt[10][i] = energy_glcm_vertical_up;
      m_metricas_asphalt[11][i] = energy_glcm_vertical_down;
      m_metricas_asphalt[12][i] = energy_glcm_diagonal_45;
      m_metricas_asphalt[13][i] = energy_glcm_diagonal_135;
      m_metricas_asphalt[14][i] = energy_glcm_diagonal_225;
      m_metricas_asphalt[15][i] = energy_glcm_diagonal_315;
      m_metricas_asphalt[16][i] = homogeneity_glcm_horizontal_right;
      m_metricas_asphalt[17][i] = homogeneity_glcm_horizontal_left;
      m_metricas_asphalt[18][i] = homogeneity_glcm_vertical_up;
      m_metricas_asphalt[19][i] = homogeneity_glcm_vertical_down;
      m_metricas_asphalt[20][i] = homogeneity_glcm_diagonal_45;
      m_metricas_asphalt[21][i] = homogeneity_glcm_diagonal_135;
      m_metricas_asphalt[22][i] = homogeneity_glcm_diagonal_225;
      m_metricas_asphalt[23][i] = homogeneity_glcm_diagonal_315;


  free(m_asphalt);
  free(glcm_horizontal_left);
  free(glcm_horizontal_right);
  free(glcm_vertical_up);
  free(glcm_vertical_down);
  free(glcm_diagonal_45);
  free(glcm_diagonal_135);
  free(glcm_diagonal_225);
  free(glcm_diagonal_315);

  free(normalized_glcm_horizontal_right);
  free(normalized_glcm_horizontal_left);
  free(normalized_glcm_vertical_up);
  free(normalized_glcm_vertical_down);
  free(normalized_glcm_diagonal_45);
  free(normalized_glcm_diagonal_135);
  free(normalized_glcm_diagonal_225);
  free(normalized_glcm_diagonal_315);


} //END FOR i<numero_de_imagens


























for(int i=0;i<50;i++){
  printf("%s\n",full_path_grass[i]);
}
FILE *fp_grass;
for(int i=0;i<50; i++){
  fp_grass = fopen(full_path_grass[i],"r");
    if(fp_grass == NULL){
      printf("FALHA!\n");
      exit(1);
    }
    else{
      printf("O AQRUIVO %d FOI ABERTO COM SUCESSO\n", (i+1));
    }
}
fclose(fp_grass);





for(int i=0;i<numero_de_imagens;i++){ //CALCULO GLCM GRAMA


int number_grass,number_of_lines = 0, number_of_columns = 0, number_of_elements = 0; //Proprieades Matriz.
int biggest_element = 0; // Maior elemento da Matriz.
char aux=0; //Contador caracteres Matriz.

fp_grass= fopen(full_path_grass[i],"r");

while(!feof(fp_grass)){    //Conta elementos da Matriz e Seleciona o maior elemento.
 fscanf(fp_grass,"%d%c",&number_grass,&aux);

 if(number_grass > biggest_element)biggest_element = number_grass;

 if(aux == ';'){
     number_of_elements +=1;
   }
   else if(aux == '\n'){
     number_of_lines +=1;
     number_of_elements+=1;
   }
  //printf(" %c",aux);
}
fclose(fp_grass);


number_of_lines -= 1;  //pois a matriz comeca com um "\n"
number_of_columns = number_of_elements/number_of_lines; // Matriz quadrada
printf("number_of_lines = %d\n number_of_columns = %d\n number_of_elements = %d\n biggest_element = %d\n",number_of_lines,number_of_columns,number_of_elements,biggest_element);


int *m_grass;
m_grass = (int *)malloc(number_of_columns*number_of_lines*sizeof(int)); //MATRIZ DA IMAGEM ALOCADA DINAMICAMENTE
if(fp_grass == NULL)printf("ERRO AO ALOCAR m_grass\n");

int *glcm_horizontal_right;
glcm_horizontal_right = (int *)calloc(biggest_element*biggest_element,sizeof(int));//MATRIZ GLCM
if(glcm_horizontal_right == NULL)printf("ERRO AO ALOCAR glcm_horizontal_right\n");

int *glcm_horizontal_left;
glcm_horizontal_left = (int *)calloc(biggest_element*biggest_element,sizeof(int));//MATRIZ GLCM
if(glcm_horizontal_left == NULL)printf("ERRO AO ALOCAR glcm_horizontal_left\n");

int *glcm_vertical_up;
glcm_vertical_up = (int *)calloc(biggest_element*biggest_element,sizeof(int));//MATRIZ GLCM
if(glcm_vertical_up == NULL)printf("ERRO AO ALOCAR glcm_vertical_up\n");

int *glcm_vertical_down;
glcm_vertical_down = (int *)calloc(biggest_element*biggest_element,sizeof(int));//MATRIZ GLCM
if(glcm_vertical_down == NULL)printf("ERRO AO ALOCAR glcm_vertical_down\n");

int *glcm_diagonal_135;
glcm_diagonal_135 = (int *)calloc(biggest_element*biggest_element,sizeof(int));//MATRIZ GLCM
if(glcm_diagonal_135 == NULL)printf("ERRO AO ALOCAR glcm_diagonal_135\n");

int *glcm_diagonal_45;
glcm_diagonal_45 = (int *)calloc(biggest_element*biggest_element,sizeof(int));//MATRIZ GLCM
if(glcm_diagonal_45 == NULL)printf("ERRO AO ALOCAR glcm_diagonal_45\n");

int *glcm_diagonal_225;
glcm_diagonal_225 = (int *)calloc(biggest_element*biggest_element,sizeof(int));//MATRIZ GLCM
if(glcm_diagonal_225 == NULL)printf("ERRO AO ALOCAR glcm_diagonal_225\n");

int *glcm_diagonal_315;
glcm_diagonal_315 = (int *)calloc(biggest_element*biggest_element,sizeof(int));//MATRIZ GLCM
if(glcm_diagonal_315 == NULL)printf("ERRO AO ALOCAR glcm_diagonal_315\n");

file_para_asfalto = fopen(full_path_asphalt[0],"r"); //ABERTURA DO ARQUIVO .TXT DE ASFALTO
if(file_para_asfalto == NULL){
 printf("Cannot open the file\n");
}


for(int i=0; i<number_of_lines;i++){ //FUNCAO QUE ADICIONA À MATRIZ ALOCADA OS VALORES DA MATRIZ .TXT
 for(int j=0; j<number_of_columns;j++){
   int x = 0;
   char ch;
       fscanf(file_para_grama,"%d",&x);
       ch = getc(file_para_grama);
       //printf("%d ",x);
       //putchar(ch);
       //printf("\n");
       *(m_grass+(i*number_of_columns)+j) = x;
 }
}

fclose(file_para_grama);


 for(int i = 0; i<number_of_lines; i++){ //PRINTA A MATRIZ ALOCADA m_asphalt;
   for(int j = 0; j<number_of_columns; j++){
   //  printf("%d ",*(m_asphalt+(i*number_of_columns)+j));
   }
   //printf("\n");
 }

 /*for(int i=0;i<biggest_element;i++){ //ESTRUTURA QUE PRINTA ALGUMA MATRIZ GLCM PREENCHIDA POR 0's DO CALLOC
   for(int j=0;j<biggest_element;j++){
     printf("%d ",*(glcm+(i*biggest_element )+j));
   }
   printf("\n");
 }*/



 for(int i=0; i<number_of_lines;i++){
     for(int j=0; j<number_of_columns; j++){


       if((i!=0 && i!=(number_of_lines-1)) && (j!=0 && j!=(number_of_columns-1))){
         int glcm_h_right=0, glcm_h_left=0, glcm_v_up=0, glcm_v_down=0, glcm_d_45=0,glcm_d_135=0, glcm_d_315=0, glcm_d_225=0;

         int x =  *(m_grass+(i*number_of_columns)+j);//valor da m_asphalt[i][j]

         glcm_h_right= *(m_grass+(i*number_of_columns)+(j+1));//valor da posicao m_asphalt[i][j+1]
         *(glcm_horizontal_right+(x*biggest_element)+glcm_h_right)+=1;//incremento na matriz glcm_horizontal_right

         glcm_h_left = *(m_grass+(i*number_of_columns)+(j-1));//valor da posicao m_asphalt[i][j-1]
         *(glcm_horizontal_left+(x*biggest_element)+glcm_h_left)+=1;//incremento na matriz glcm_horizontal_left

         glcm_v_up = *(m_grass+((i-1)*number_of_columns)+j);//valor da posicao m_asphalt[i-1][j]
         *(glcm_vertical_up+(x*biggest_element)+glcm_v_up)+=1;//incremento na matriz glcm_vertical_up

         glcm_v_down = *(m_grass+((i+1)*number_of_columns)+j);//valor da posicao m_asphalt[i+1][j]
         *(glcm_vertical_down+(x*biggest_element)+glcm_v_down)+=1;//incremento na matriz glcm_vertical_down

         glcm_d_45 = *(m_grass+((i-1)*number_of_columns)+(j+1));//valor da posicao m_asphalt[i-1][j+1]
         *(glcm_diagonal_45+(x*biggest_element)+glcm_d_45)+=1;//incremento na matriz glcm_diagonal_45

         glcm_d_135 = *(m_grass+((i-1)*number_of_columns)+(j-1));//valor da posicao m_asphalt[i-1][j-1]
         *(glcm_diagonal_135+(x*biggest_element)+glcm_d_135)+=1;//incremento na matriz glcm_diagonal_135

         glcm_d_315 = *(m_grass+((i+1)*number_of_columns)+(j+1));//valor da posicao m_asphalt[i+1][j+1]
         *(glcm_diagonal_315+(x*biggest_element)+glcm_d_315)+=1;//incremento na matriz glcm_diagonal_315

         glcm_d_225 = *(m_grass+((i+1)*number_of_columns)+(j-1));//valor da posicao m_asphalt[i+1][j-1]
         *(glcm_diagonal_225+(x*biggest_element)+glcm_d_225)+=1;//incremento na matriz glcm_diagonal_225

       }
       else{

         if(i==0 && j==0){ //Quando m_asphalt[0][0]
           int glcm_h_right=0, glcm_v_down=0, glcm_d_315=0;

           int x =  *(m_grass+(i*number_of_columns)+j);//valor da m_asphalt[i][j]

           glcm_h_right = *(m_grass+(i*number_of_columns)+(j+1));
           *(glcm_horizontal_right+(x*biggest_element)+glcm_h_right)+=1;

           glcm_v_down = *(m_grass+((i+1)*number_of_columns)+j);
           *(glcm_vertical_down+(x*biggest_element)+glcm_v_down)+=1;

           glcm_d_315 = *(m_grass+((i+1)*number_of_columns)+(j+1));
           *(glcm_diagonal_315+(x*biggest_element)+glcm_d_315)+=1;
         }

         else if(i==0 && j==(number_of_columns-1)){//Quando m_asphalt[0][(number_of_columns-1)]
           int glcm_h_left=0, glcm_v_down=0, glcm_d_225=0;

           int x =  *(m_grass+(i*number_of_columns)+j);//valor da m_asphalt[i][j]

           glcm_h_left = *(m_grass+(i*number_of_columns)+(j-1));//valor da posicao m_asphalt[i][j-1]
           *(glcm_horizontal_left+(x*biggest_element)+glcm_h_left)+=1;//incremento na matriz glcm_horizontal_left

           glcm_d_225 = *(m_grass+((i+1)*number_of_columns)+(j-1));//valor da posicao m_asphalt[i+1][j-1]
           *(glcm_diagonal_225+(x*biggest_element)+glcm_d_225)+=1;//incremento na matriz glcm_diagonal_225

           glcm_v_down = *(m_grass+((i+1)*number_of_columns)+j);//valor da posicao m_asphalt[i+1][j]
           *(glcm_vertical_down+(x*biggest_element)+glcm_v_down)+=1;//incremento na matriz glcm_vertical_down
         }

         else if(i==(number_of_lines-1) && j==0){//Quando m_asphalt[(number_of_lines-1)][0]
           int glcm_h_right=0, glcm_v_up=0, glcm_d_45=0;

           int x =  *(m_grass+(i*number_of_columns)+j);//valor da m_asphalt[i][j]

           glcm_h_right = *(m_grass+(i*number_of_columns)+(j+1));
           *(glcm_horizontal_right+(x*biggest_element)+glcm_h_right)+=1;

           glcm_v_up = *(m_grass+((i-1)*number_of_columns)+j);//valor da posicao m_asphalt[i-1][j]
           *(glcm_vertical_up+(x*biggest_element)+glcm_v_up)+=1;//incremento na matriz glcm_vertical_up

           glcm_d_45 = *(m_grass+((i-1)*number_of_columns)+(j+1));//valor da posicao m_asphalt[i-1][j+1]
           *(glcm_diagonal_45+(x*biggest_element)+glcm_d_45)+=1;//incremento na matriz glcm_diagonal_45
         }

         else if(i==(number_of_lines-1) && j==(number_of_columns-1)){//Quando m_asphalt[(number_of_lines-1)][(number_of_columns-1)]
           int  glcm_h_left=0, glcm_v_up=0, glcm_d_135=0;

           int x =  *(m_grass+(i*number_of_columns)+j);//valor da m_asphalt[i][j]

           glcm_h_left = *(m_grass+(i*number_of_columns)+(j-1));//valor da posicao m_asphalt[i][j-1]
           *(glcm_horizontal_left+(x*biggest_element)+glcm_h_left)+=1;//incremento na matriz glcm_horizontal_left

           glcm_v_up = *(m_grass+((i-1)*number_of_columns)+j);//valor da posicao m_asphalt[i-1][j]
           *(glcm_vertical_up+(x*biggest_element)+glcm_v_up)+=1;//incremento na matriz glcm_vertical_up

           glcm_d_135 = *(m_grass+((i-1)*number_of_columns)+(j-1));//valor da posicao m_asphalt[i-1][j-1]
           *(glcm_diagonal_135+(x*biggest_element)+glcm_d_135)+=1;//incremento na matriz glcm_diagonal_135
         }

         else if((j>0 && j<(number_of_columns-1)) && (i == 0 )){ //Quando m_asphalt[0][0< i <(number_of_columns-1)]
           int glcm_h_right=0, glcm_h_left=0, glcm_v_down=0, glcm_d_315=0, glcm_d_225=0;

           int x =  *(m_grass+(i*number_of_columns)+j);//valor da m_asphalt[i][j]

           glcm_h_right= *(m_grass+(i*number_of_columns)+(j+1));//valor da posicao m_asphalt[i][j+1]
           *(glcm_horizontal_right+(x*biggest_element)+glcm_h_right)+=1;//incremento na matriz glcm_horizontal_right

           glcm_h_left = *(m_grass+(i*number_of_columns)+(j-1));//valor da posicao m_asphalt[i][j-1]
           *(glcm_horizontal_left+(x*biggest_element)+glcm_h_left)+=1;//incremento na matriz glcm_horizontal_left

           glcm_v_down = *(m_grass+((i+1)*number_of_columns)+j);//valor da posicao m_asphalt[i+1][j]
           *(glcm_vertical_down+(x*biggest_element)+glcm_v_down)+=1;//incremento na matriz glcm_vertical_down

           glcm_d_315 = *(m_grass+((i+1)*number_of_columns)+(j+1));//valor da posicao m_asphalt[i+1][j+1]
           *(glcm_diagonal_315+(x*biggest_element)+glcm_d_315)+=1;//incremento na matriz glcm_diagonal_315

           glcm_d_225 = *(m_grass+((i+1)*number_of_columns)+(j-1));//valor da posicao m_asphalt[i+1][j-1]
           *(glcm_diagonal_225+(x*biggest_element)+glcm_d_225)+=1;//incremento na matriz glcm_diagonal_225
         }

         else if((i>0 && i<(number_of_lines-1)) && j==0){
           int glcm_h_right=0, glcm_v_up=0, glcm_v_down=0, glcm_d_45=0, glcm_d_315=0;

           int x =  *(m_grass+(i*number_of_columns)+j);//valor da m_asphalt[i][j]

           glcm_h_right= *(m_grass+(i*number_of_columns)+(j+1));//valor da posicao m_asphalt[i][j+1]
           *(glcm_horizontal_right+(x*biggest_element)+glcm_h_right)+=1;//incremento na matriz glcm_horizontal_right

           glcm_v_down = *(m_grass+((i+1)*number_of_columns)+j);//valor da posicao m_asphalt[i+1][j]
           *(glcm_vertical_down+(x*biggest_element)+glcm_v_down)+=1;//incremento na matriz glcm_vertical_down

           glcm_d_315 = *(m_grass+((i+1)*number_of_columns)+(j+1));//valor da posicao m_asphalt[i+1][j+1]
           *(glcm_diagonal_315+(x*biggest_element)+glcm_d_315)+=1;//incremento na matriz glcm_diagonal_315

           glcm_v_up = *(m_grass+((i-1)*number_of_columns)+j);//valor da posicao m_asphalt[i-1][j]
           *(glcm_vertical_up+(x*biggest_element)+glcm_v_up)+=1;//incremento na matriz glcm_vertical_up
         }

         else if((i == (number_of_lines-1)) && (j>0 && j < (number_of_columns-1))){
           int glcm_h_right=0, glcm_h_left=0, glcm_v_up=0, glcm_d_45=0,glcm_d_135=0;

           int x =  *(m_grass+(i*number_of_columns)+j);//valor da m_asphalt[i][j]

           glcm_h_right= *(m_grass+(i*number_of_columns)+(j+1));//valor da posicao m_asphalt[i][j+1]
           *(glcm_horizontal_right+(x*biggest_element)+glcm_h_right)+=1;//incremento na matriz glcm_horizontal_right

           glcm_v_up = *(m_grass+((i-1)*number_of_columns)+j);//valor da posicao m_asphalt[i-1][j]
           *(glcm_vertical_up+(x*biggest_element)+glcm_v_up)+=1;//incremento na matriz glcm_vertical_up

           glcm_h_left = *(m_grass+(i*number_of_columns)+(j-1));//valor da posicao m_asphalt[i][j-1]
           *(glcm_horizontal_left+(x*biggest_element)+glcm_h_left)+=1;//incremento na matriz glcm_horizontal_left

           glcm_d_135 = *(m_grass+((i-1)*number_of_columns)+(j-1));//valor da posicao m_asphalt[i-1][j-1]
           *(glcm_diagonal_135+(x*biggest_element)+glcm_d_135)+=1;//incremento na matriz glcm_diagonal_135

           glcm_d_45 = *(m_grass+((i-1)*number_of_columns)+(j+1));//valor da posicao m_asphalt[i-1][j+1]
           *(glcm_diagonal_45+(x*biggest_element)+glcm_d_45)+=1;//incremento na matriz glcm_diagonal_45

         }

         else if((i>0 && i<(number_of_lines-1)) && j==(number_of_columns-1)){
           int  glcm_h_left=0, glcm_v_up=0, glcm_v_down=0, glcm_d_135=0, glcm_d_225=0;

           int x =  *(m_grass+(i*number_of_columns)+j);//valor da m_asphalt[i][j]

           glcm_h_left = *(m_grass+(i*number_of_columns)+(j-1));//valor da posicao m_asphalt[i][j-1]
           *(glcm_horizontal_left+(x*biggest_element)+glcm_h_left)+=1;//incremento na matriz glcm_horizontal_left

           glcm_v_up = *(m_grass+((i-1)*number_of_columns)+j);//valor da posicao m_asphalt[i-1][j]
           *(glcm_vertical_up+(x*biggest_element)+glcm_v_up)+=1;//incremento na matriz glcm_vertical_up

           glcm_d_135 = *(m_grass+((i-1)*number_of_columns)+(j-1));//valor da posicao m_asphalt[i-1][j-1]
           *(glcm_diagonal_135+(x*biggest_element)+glcm_d_135)+=1;//incremento na matriz glcm_diagonal_135

           glcm_v_down = *(m_grass+((i+1)*number_of_columns)+j);//valor da posicao m_asphalt[i+1][j]
           *(glcm_vertical_down+(x*biggest_element)+glcm_v_down)+=1;//incremento na matriz glcm_vertical_down

           glcm_d_225 = *(m_grass+((i+1)*number_of_columns)+(j-1));//valor da posicao m_asphalt[i+1][j-1]
           *(glcm_diagonal_225+(x*biggest_element)+glcm_d_225)+=1;//incremento na matriz glcm_diagonal_225

         }

       }
     }
 }

 /*for(int i=0; i<biggest_element;i++){
   for(int j=0;j<biggest_element;j++){
     printf("%d ",*(glcm_horizontal_right+(i*biggest_element)+j));
   }
   printf("\n");
 }
 printf("\n\n\n\n\n\n\n******************************************************************\n");

 for(int i=0; i<biggest_element;i++){
   for(int j=0;j<biggest_element;j++){
     printf("%d ",*(glcm_horizontal_left+(i*biggest_element)+j));
   }
   printf("\n");
 }

 for(int i=0; i<biggest_element;i++){
   for(int j=0;j<biggest_element;j++){
     printf("%d ",*(glcm_vertical_up+(i*biggest_element)+j));
   }
   printf("\n");
 }

 for(int i=0; i<biggest_element;i++){
   for(int j=0;j<biggest_element;j++){
     printf("%d ",*(glcm_vertical_down+(i*biggest_element)+j));
   }
   printf("\n");
 }

 for(int i=0; i<biggest_element;i++){
   for(int j=0;j<biggest_element;j++){
     printf("%d ",*(glcm_diagonal_45+(i*biggest_element)+j));
   }
   printf("\n");
 }

 for(int i=0; i<biggest_element;i++){
   for(int j=0;j<biggest_element;j++){
     printf("%d ",*(glcm_diagonal_135+(i*biggest_element)+j));
   }
   printf("\n");
 }

 for(int i=0; i<biggest_element;i++){
   for(int j=0;j<biggest_element;j++){
     printf("%d ",*(glcm_diagonal_225+(i*biggest_element)+j));
   }
   printf("\n");
 }
*/

//NORMALIZANDO GLCMS

//CRIANDO NOVAS MATRIZES COM OS VALORES NORMALIZADOS

double *normalized_glcm_horizontal_right;
normalized_glcm_horizontal_right = (double *)calloc(biggest_element*biggest_element,sizeof(double));//MATRIZ GLCM
if(normalized_glcm_horizontal_right == NULL)printf("ERRO AO ALOCAR normalized_glcm_horizontal_right\n");

double *normalized_glcm_horizontal_left;
normalized_glcm_horizontal_left = (double *)calloc(biggest_element*biggest_element,sizeof(double));//MATRIZ GLCM
if(normalized_glcm_horizontal_left == NULL)printf("ERRO AO ALOCAR normalized_glcm_horizontal_left\n");

double *normalized_glcm_vertical_up;
normalized_glcm_vertical_up = (double *)calloc(biggest_element*biggest_element,sizeof(double));//MATRIZ GLCM
if(normalized_glcm_vertical_up == NULL)printf("ERRO AO ALOCAR normalized_glcm_vertical_up\n");

double *normalized_glcm_vertical_down;
normalized_glcm_vertical_down = (double *)calloc(biggest_element*biggest_element,sizeof(double));//MATRIZ GLCM
if(normalized_glcm_vertical_down == NULL)printf("ERRO AO ALOCAR normalized_glcm_vertical_down\n");

double *normalized_glcm_diagonal_135;
normalized_glcm_diagonal_135 = (double *)calloc(biggest_element*biggest_element,sizeof(double));//MATRIZ GLCM
if(normalized_glcm_diagonal_135 == NULL)printf("ERRO AO ALOCAR glcm_diagonal_135\n");

double *normalized_glcm_diagonal_45;
normalized_glcm_diagonal_45 = (double *)calloc(biggest_element*biggest_element,sizeof(double));//MATRIZ GLCM
if(normalized_glcm_diagonal_45 == NULL)printf("ERRO AO ALOCAR normalized_glcm_diagonal_45\n");

double *normalized_glcm_diagonal_225;
normalized_glcm_diagonal_225 = (double *)calloc(biggest_element*biggest_element,sizeof(double));//MATRIZ GLCM
if(normalized_glcm_diagonal_225 == NULL)printf("ERRO AO ALOCAR normalized_glcm_diagonal_225\n");

double *normalized_glcm_diagonal_315;
normalized_glcm_diagonal_315 = (double *)calloc(biggest_element*biggest_element,sizeof(double));//MATRIZ GLCM
if(normalized_glcm_diagonal_315 == NULL)printf("ERRO AO ALOCAR normalized_glcm_diagonal_315\n");

double soma_dos_elementos_horizontalz_right=0, soma_dos_elementos_horizontalz_left=0, soma_dos_elementos_vertical_up=0,
soma_dos_elementos_vertical_down=0, soma_dos_elementos_diagonal_45=0, soma_dos_elementos_diagonal_135=0, soma_dos_elementos_diagonal_225=0, soma_dos_elementos_diagonal_315=0;
for(int i=0;i<biggest_element;i++){
 for(int j=0;j<biggest_element;j++){
   soma_dos_elementos_horizontalz_right += *(glcm_horizontal_right+(i*biggest_element)+j);
   soma_dos_elementos_horizontalz_left += *(glcm_horizontal_left+(i*biggest_element)+j);
   soma_dos_elementos_vertical_up += *(glcm_vertical_up+(i*biggest_element)+j);
   soma_dos_elementos_vertical_down += *(glcm_vertical_down+(i*biggest_element)+j);
   soma_dos_elementos_diagonal_45 += *(glcm_diagonal_45+(i*biggest_element)+j);
   soma_dos_elementos_diagonal_135 += *(glcm_diagonal_135+(i*biggest_element)+j);
   soma_dos_elementos_diagonal_225 += *(glcm_diagonal_225+(i*biggest_element)+j);
   soma_dos_elementos_diagonal_315 += *(glcm_diagonal_315+(i*biggest_element)+j);
 }
}

printf("soma_dos_elementos_horizontalz_right = %.2lf\n soma_dos_elementos_horizontalz_left = %.2lf\n soma_dos_elementos_vertical_down = %.2lf\n soma_dos_elementos_vertical_up = %.2lf\n soma_dos_elementos_diagonal_45 = %.2lf\n soma_dos_elementos_diagonal_135 = %.2lf\n soma_dos_elementos_diagonal_225 = %.2lf\n soma_dos_elementos_diagonal_315= %.2lf\n",soma_dos_elementos_horizontalz_right, soma_dos_elementos_horizontalz_left, soma_dos_elementos_vertical_down, soma_dos_elementos_vertical_up, soma_dos_elementos_diagonal_45, soma_dos_elementos_diagonal_135, soma_dos_elementos_diagonal_225, soma_dos_elementos_diagonal_315);

for(int i=0;i<biggest_element;i++){
 for(int j=0;j<biggest_element;j++){
   *(normalized_glcm_horizontal_right+(i*biggest_element)+j) = (*(glcm_horizontal_right+(i*biggest_element)+j) / soma_dos_elementos_horizontalz_right);
   *(normalized_glcm_horizontal_left+(i*biggest_element)+j) = *(glcm_horizontal_left+(i*biggest_element)+j)/ soma_dos_elementos_horizontalz_left;
   *(normalized_glcm_vertical_up+(i*biggest_element)+j) = *(glcm_vertical_up+(i*biggest_element)+j)/ soma_dos_elementos_vertical_up;
   *(normalized_glcm_vertical_down+(i*biggest_element)+j) = *(glcm_vertical_down+(i*biggest_element)+j)/  soma_dos_elementos_vertical_down;
   *(normalized_glcm_diagonal_45+(i*biggest_element)+j) = *(glcm_diagonal_45+(i*biggest_element)+j)/   soma_dos_elementos_diagonal_45;
   *(normalized_glcm_diagonal_135+(i*biggest_element)+j) = *(glcm_diagonal_135+(i*biggest_element)+j)/   soma_dos_elementos_diagonal_135;
   *(normalized_glcm_diagonal_225+(i*biggest_element)+j) = *(glcm_diagonal_225+(i*biggest_element)+j)/   soma_dos_elementos_diagonal_225;
   *(normalized_glcm_diagonal_315+(i*biggest_element)+j) = (*(glcm_diagonal_315+(i*biggest_element)+j)/  soma_dos_elementos_diagonal_315);
 }
}
double lol = 0, lol1 = 0, lol2 = 0, lol3 = 0, lol4 = 0, lol5 = 0, lol6 = 0, lol7 = 0;
for(int i=0;i<biggest_element;i++){
 for(int j=0; j<biggest_element;j++){
   lol+= *(normalized_glcm_horizontal_right+(i*biggest_element)+j);
   lol1+= *(normalized_glcm_horizontal_left+(i*biggest_element)+j);
   lol2+= *(normalized_glcm_vertical_up+(i*biggest_element)+j);
   lol3+= *(normalized_glcm_vertical_down+(i*biggest_element)+j);
   lol4+= *(normalized_glcm_diagonal_45+(i*biggest_element)+j);
   lol5+= *(normalized_glcm_diagonal_135+(i*biggest_element)+j);
   lol6+= *(normalized_glcm_diagonal_225+(i*biggest_element)+j);
   lol7+= *(normalized_glcm_diagonal_315+(i*biggest_element)+j);
 }
 printf("\n");
}
printf("%.2lf\n %.2lf\n %.2lf\n %.2lf\n %.2lf\n %.2lf\n %.2lf\n %.2lf\n",lol,lol1,lol2,lol3,lol4,lol5,lol6,lol7); //PROVA QUE AS MATRIZES FORAM NORMALIZADAS DE MANEIRA CORRETA. POIS A SOMA DE SEUS ELEMENTOS É IGUAL A "1".

//FIM DAS NORMALIZAÇÕES

//FEATURE GLCM.1 - CONTRAST:


double contraste_glcm_horizontal_right=0, contraste_glcm_horizontal_left=0, contraste_glcm_vertical_up=0, contraste_glcm_vertical_down=0,
contraste_glcm_diagonal_45=0, contraste_glcm_diagonal_135=0, contraste_glcm_diagonal_225=0, contraste_glcm_diagonal_315=0;
for(int i=0; i<biggest_element; i++){
 for(int j=0; j<biggest_element; j++){
   contraste_glcm_horizontal_right+= ((i-j)*(i-j))*(*(normalized_glcm_horizontal_right+(i*biggest_element)+j));
   contraste_glcm_horizontal_left+= ((i-j)*(i-j))*(*(normalized_glcm_horizontal_left+(i*biggest_element)+j));
   contraste_glcm_vertical_up+= ((i-j)*(i-j))*(*(normalized_glcm_vertical_up+(i*biggest_element)+j));
   contraste_glcm_vertical_down+= ((i-j)*(i-j))*(*(normalized_glcm_vertical_down+(i*biggest_element)+j));
   contraste_glcm_diagonal_45+= ((i-j)*(i-j))*(*(normalized_glcm_diagonal_45+(i*biggest_element)+j));
   contraste_glcm_diagonal_135+= ((i-j)*(i-j))*(*(normalized_glcm_diagonal_135+(i*biggest_element)+j));
   contraste_glcm_diagonal_225+= ((i-j)*(i-j))*(*(normalized_glcm_diagonal_225+(i*biggest_element)+j));
   contraste_glcm_diagonal_315+= ((i-j)*(i-j))*(*(normalized_glcm_diagonal_315+(i*biggest_element)+j));
 }
}
printf("contraste_glcm_horizontal_right = %.2lf\n contraste_glcm_horizontal_left = %.2lf\n contraste_glcm_vertical_up = %.2lf\n contraste_glcm_vertical_down = %.2lf\ncontraste_glcm_diagonal_45 = %.2lf\n contraste_glcm_diagonal_135 = %.2lf\n contraste_glcm_diagonal_225 = %.2lf\n contraste_glcm_diagonal_335 = %.2lf\n ", contraste_glcm_horizontal_right, contraste_glcm_horizontal_left,contraste_glcm_vertical_up,contraste_glcm_vertical_down,contraste_glcm_diagonal_45,contraste_glcm_diagonal_135, contraste_glcm_diagonal_225, contraste_glcm_diagonal_315);
printf("---------------------------------------//---------------------------------------//---------------------------------------//---------------------------------------\n\n\n\n\n");

//-----------------------------//---------------------//-------

//FEATURE GLCM.2 - Energy:
double energy_glcm_horizontal_right=0, energy_glcm_horizontal_left=0, energy_glcm_vertical_up=0, energy_glcm_vertical_down=0, energy_glcm_diagonal_45=0, energy_glcm_diagonal_135=0, energy_glcm_diagonal_225=0, energy_glcm_diagonal_315=0;
for(int i=0;i<biggest_element;i++){
 for(int j=0; j<biggest_element; j++){
   energy_glcm_horizontal_right += ( (*(normalized_glcm_horizontal_right+(i*biggest_element)+j)) * (*(normalized_glcm_horizontal_right+(i*biggest_element)+j)));
   energy_glcm_horizontal_left += ( (*(normalized_glcm_horizontal_left+(i*biggest_element)+j)) * (*(normalized_glcm_horizontal_left+(i*biggest_element)+j)));
   energy_glcm_vertical_up += ( (*(normalized_glcm_vertical_up+(i*biggest_element)+j)) * (*(normalized_glcm_vertical_up+(i*biggest_element)+j)));
   energy_glcm_vertical_down += ( (*(normalized_glcm_vertical_down+(i*biggest_element)+j)) * (*(normalized_glcm_vertical_down+(i*biggest_element)+j)));
   energy_glcm_diagonal_45 += ( (*(normalized_glcm_diagonal_45+(i*biggest_element)+j)) * (*(normalized_glcm_diagonal_45+(i*biggest_element)+j)));
   energy_glcm_diagonal_135 += ( (*(normalized_glcm_diagonal_135+(i*biggest_element)+j)) * (*(normalized_glcm_diagonal_135+(i*biggest_element)+j)));
   energy_glcm_diagonal_225 += ( (*(normalized_glcm_diagonal_225+(i*biggest_element)+j)) * (*(normalized_glcm_diagonal_225+(i*biggest_element)+j)));
   energy_glcm_diagonal_315 += ( (*(normalized_glcm_diagonal_315+(i*biggest_element)+j)) * (*(normalized_glcm_diagonal_315+(i*biggest_element)+j)));

 }
}
printf("energy_glcm_horizontal_right = %.10lf\n energy_glcm_horizontal_left = %.10lf\n energy_glcm_vertical_up = %.10lf\n energy_glcm_vertical_down = %.10lf\n energy_glcm_diagonal_45 = %.10lf\n energy_glcm_diagonal_135 = %.10lf\n energy_glcm_diagonal_225 = %.10lf\n energy_glcm_diagonal_315 = %.10lf\n" , energy_glcm_horizontal_right, energy_glcm_horizontal_left, energy_glcm_vertical_up, energy_glcm_vertical_down, energy_glcm_diagonal_45, energy_glcm_diagonal_135, energy_glcm_diagonal_225, energy_glcm_diagonal_315);
printf("---------------------------------------//---------------------------------------//---------------------------------------//---------------------------------------\n\n\n\n\n");


//-----------------------------//---------------------//-------

//FEATURE GLCM.3 - Homogeneity
double homogeneity_glcm_horizontal_right = 0, homogeneity_glcm_horizontal_left=0, homogeneity_glcm_vertical_up=0, homogeneity_glcm_vertical_down=0, homogeneity_glcm_diagonal_45=0, homogeneity_glcm_diagonal_135=0, homogeneity_glcm_diagonal_225=0, homogeneity_glcm_diagonal_315=0;

for(int i=0; i<biggest_element; i++){
 for(int j=0;j<biggest_element; j++){
   homogeneity_glcm_horizontal_right += ((*(normalized_glcm_horizontal_right+(i*biggest_element)+j))/(1+sqrt((i-j)*(i-j))));
   homogeneity_glcm_horizontal_left += ((*(normalized_glcm_horizontal_left+(i*biggest_element)+j))/(1+sqrt((i-j)*(i-j))));
   homogeneity_glcm_vertical_up += ((*(normalized_glcm_vertical_up+(i*biggest_element)+j))/(1+sqrt((i-j)*(i-j))));
   homogeneity_glcm_vertical_down += ((*(normalized_glcm_vertical_down+(i*biggest_element)+j))/(1+sqrt((i-j)*(i-j))));
   homogeneity_glcm_diagonal_45 += ((*(normalized_glcm_diagonal_45+(i*biggest_element)+j))/(1+sqrt((i-j)*(i-j))));
   homogeneity_glcm_diagonal_135 += ((*(normalized_glcm_diagonal_135+(i*biggest_element)+j))/(1+sqrt((i-j)*(i-j))));
   homogeneity_glcm_diagonal_225 += ((*(normalized_glcm_diagonal_225+(i*biggest_element)+j))/(1+sqrt((i-j)*(i-j))));
   homogeneity_glcm_diagonal_315 += ((*(normalized_glcm_diagonal_315+(i*biggest_element)+j))/(1+sqrt((i-j)*(i-j))));
 }
}
printf("homogeneity_glcm_horizontal_right = %.10lf\n homogeneity_glcm_horizontal_left %.10lf\n homogeneity_glcm_vertical_up %.10lf\n homogeneity_glcm_vertical_down %.10lf\n homogeneity_glcm_diagonal_45 %.10lf\n homogeneity_glcm_diagonal_135 %.10lf\n homogeneity_glcm_diagonal_225 %.10lf\n homogeneity_glcm_diagonal_315 %.10lf\n ",homogeneity_glcm_horizontal_right, homogeneity_glcm_horizontal_left, homogeneity_glcm_vertical_up, homogeneity_glcm_vertical_down, homogeneity_glcm_diagonal_45, homogeneity_glcm_diagonal_135, homogeneity_glcm_diagonal_225, homogeneity_glcm_diagonal_315 );
printf("---------------------------------------//---------------------------------------//---------------------------------------//---------------------------------------\n\n\n\n\n");


m_metricas_grass[0][i] = contraste_glcm_horizontal_right;
m_metricas_grass[1][i] = contraste_glcm_horizontal_left;
m_metricas_grass[2][i] = contraste_glcm_vertical_up;
m_metricas_grass[3][i] = contraste_glcm_vertical_down;
m_metricas_grass[4][i] = contraste_glcm_diagonal_45;
m_metricas_grass[5][i] = contraste_glcm_diagonal_135;
m_metricas_grass[6][i] = contraste_glcm_diagonal_225;
m_metricas_grass[7][i] = contraste_glcm_diagonal_315;
m_metricas_grass[8][i] = energy_glcm_horizontal_right;
m_metricas_grass[9][i] = energy_glcm_horizontal_left;
m_metricas_grass[10][i] = energy_glcm_vertical_up;
m_metricas_grass[11][i] = energy_glcm_vertical_down;
m_metricas_grass[12][i] = energy_glcm_diagonal_45;
m_metricas_grass[13][i] = energy_glcm_diagonal_135;
m_metricas_grass[14][i] = energy_glcm_diagonal_225;
m_metricas_grass[15][i] = energy_glcm_diagonal_315;
m_metricas_grass[16][i] = homogeneity_glcm_horizontal_right;
m_metricas_grass[17][i] = homogeneity_glcm_horizontal_left;
m_metricas_grass[18][i] = homogeneity_glcm_vertical_up;
m_metricas_grass[19][i] = homogeneity_glcm_vertical_down;
m_metricas_grass[20][i] = homogeneity_glcm_diagonal_45;
m_metricas_grass[21][i] = homogeneity_glcm_diagonal_135;
m_metricas_grass[22][i] = homogeneity_glcm_diagonal_225;
m_metricas_grass[23][i] = homogeneity_glcm_diagonal_315;


 free(m_grass);
 free(glcm_horizontal_left);
 free(glcm_horizontal_right);
 free(glcm_vertical_up);
 free(glcm_vertical_down);
 free(glcm_diagonal_45);
 free(glcm_diagonal_135);
 free(glcm_diagonal_225);
 free(glcm_diagonal_315);

 free(normalized_glcm_horizontal_right);
 free(normalized_glcm_horizontal_left);
 free(normalized_glcm_vertical_up);
 free(normalized_glcm_vertical_down);
 free(normalized_glcm_diagonal_45);
 free(normalized_glcm_diagonal_135);
 free(normalized_glcm_diagonal_225);
 free(normalized_glcm_diagonal_315);


} //END FOR i<numero_de_imagens




  return 0;
}
