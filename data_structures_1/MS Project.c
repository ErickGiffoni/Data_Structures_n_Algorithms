#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
int main (){
char aleat[100][80] = {"C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_01.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_02.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_03.txt","C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_04.txt","C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_05.txt","C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_06.txt","C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_07.txt","C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_08.txt","C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_09.txt","C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_10.txt","C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_11.txt","C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_12.txt","C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_13.txt","C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_04.txt","C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_15.txt","C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_16.txt","C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_17.txt","C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_18.txt","C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_19.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_20.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_21.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_22.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_23.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_24.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_25.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_26.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_27.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_28.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_29.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_30.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_31.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_32.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_33.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_34.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_35.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_36.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_37.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_38.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_39.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_40.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_41.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_42.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_43.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_44.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_45.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_46.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_47.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_48.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_49.txt", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\asphalt\\asphalt_50.txt"};
    char arq[80];
    int num, bin[9];
    int count = 1, i, valores,j, coluna;
    char c;
    float avg;

    srand(time(NULL));
    num = rand()%50;
    strcpy(arq, aleat[num]);
    printf("\n%s\n", arq);
    FILE *arquivo;
    arquivo = fopen (arq, "r");
        if (arquivo == NULL){
                printf("Falha!");
                                }
        for (i = 0;c != '\n' ; i++){
            fscanf (arquivo, "%d%c", &valores, &c);
                            }
                        coluna = i;
                printf ("Colunas: %d\n", i);
                    while ((c = fgetc(arquivo)) != EOF){
                        if (c =='\n'){
                            count++;}}
                        printf ("Lines: %d\n", count);
                                fclose(arquivo);
int *pont;

            pont = (int*) malloc(count*coluna*sizeof(int));

                    arquivo = fopen (arq, "r");

  for (i = 0; i < count; i++)
    {//
       for (j = 0; j < coluna; j++)
       {
            fscanf (arquivo, "%d;", pont+(i*coluna)+j);
       }
  }

  //for (i =0; i < count; i++){
    //for (j = 0; j < coluna;j++){
      // printf("%d ", *(pont+(i*coluna)+j));
//    }
//printf("Goku");
//int a[count][coluna];
//for (i = 0; i < count; i++){

  //  for (j = 0; j < coluna; j++){

//a[i][j] = (*(pont+i)+j);
  //  }
//}
//printf("Gohan");


i = 1;
j = 1;

  // Media/vetor frequencia

avg = *((pont+i)+j) + *((pont+i)+j+1) + *((pont+i)+j - 1) + *((pont+i - 1)+j) +*((pont+i -1)+j -1)+ *((pont+i - 1)+j + 1) + *((pont+i + 1)+j )+*((pont+i + 1)+j +1) + *((pont+i + 1)+j -1);
     avg = avg/9;
      printf("Media =  %.1f\n", avg);
if (*((pont+i)+j) > avg)
    {
    bin[4] = 1;
    }else
    {
        bin[4] = 0;
} if (*((pont+i)+j - 1) >= avg)
    {
    bin[3] = 1;
    }else
    {
        bin[3] = 0;
} if (*((pont+i)+j +1) >= avg)
    {
    bin[5] = 1;
    }else
    {
        bin[5] = 0;
}if (*((pont+i+1)+j) >= avg)
    {
    bin[7] = 1;
    }else
    {
        bin[7] = 0;
} if (*((pont+i+1)+j-1) >= avg)
    {
    bin[6] = 1;
    }else
    {
        bin[6] = 0;
}if (*((pont+i+1)+j+1) > avg)
    {
    bin[8] = 1;
    }else
    {
        bin[8] = 0;
}if (*((pont+i-1)+j) > avg)
    {
    bin[1] = 1;
    }else
    {
        bin[1] = 0;
}if (*((pont+i-1)+j-1) > avg)
    {
    bin[0] = 1;
    }else
    {
        bin[0] = 0;
}
if (*((pont+i-1)+j+1) >= avg)
    {
    bin[2] = 1;
    }else
    {
        bin[2] = 0;
}
for (i =0; i <9; i++){
    printf("%d ", bin[i]);
}

  }






//,"C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_01","C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_02", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_03", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_04", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_05", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_06", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_07", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_08", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_09", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_10", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_11", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_12", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_13", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_14", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_15", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_16", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_17", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_18", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_19", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_20", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_21", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_22", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_23", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_24", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_25", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_26", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_27", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_28", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_29", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_30", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_31", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_32", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_33", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_34", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_35", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_36", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_37", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_38", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_39", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_40","C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_41", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_42", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_43", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_44","C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_45", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_46", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_47", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_48", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_49", "C:\\Users\\brunn\\Desktop\\Final Project\\DataSet\\grass\\grass_50"
