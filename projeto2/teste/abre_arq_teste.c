#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define numero_de_imagens 50




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

int number,number_of_lines = 0, number_of_columns = 0, number_of_elements = 0; //Proprieades Matriz.
int biggest_element = 0; // Maior elemento da Matriz.
char aux; //Contador caracteres Matriz.

fp_asphalt = fopen(full_path_asphalt[0],"r");

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
   printf(" %c",aux);
   if(aux == '\n')printf("DSAJNDASKJNDSKANDSKLNSALDNLKDSNKLSA\n\n\n\n\n\n\n\n");
}
fclose(fp_asphalt);


number_of_lines -= 1;  //pois a matriz comeca com um "\n"
number_of_columns = number_of_elements/number_of_lines; // Matriz quadrada
printf("number_of_lines = %d\n number_of_columns = %d\n number_of_elements = %d\n biggest_element = %d\n",number_of_lines,number_of_columns,number_of_elements,biggest_element);


int *m_asphalt;
m_asphalt = (int *)malloc(number_of_columns*number_of_lines*sizeof(int)); //MATRIZ DA IMAGEM ALOCADA DINAMICAMENTE

file_para_grama = fopen(full_path_asphalt[0],"r");
if(file_para_grama == NULL){
  printf("Cannot open the file\n");
}

for(int i=0; i<number_of_lines;i++){
  for(int j=0; j<number_of_columns;j++){
    int x = 0;
    char ch;
        fscanf(file_para_grama,"%d",&x);
        ch = getc(file_para_grama);
        printf("%d ",x);
        putchar(ch);
        printf("\n");
        *(m_asphalt+(i*number_of_columns)+j) = x;
  }
}

  for(int i = 0; i<number_of_lines; i++){
    for(int j = 0; j<number_of_columns; j++){
      printf("%d ",*(m_asphalt+(i*number_of_columns)+j));
    }
    printf("\n");
  }
  return 0;
}
