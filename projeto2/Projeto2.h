#ifndef PROJETO_2_H
#define PROJETO_2_H



void pasta_arquivos(char *p){

  char m_locals[50][100];
  int x = 0;
  char *teste;
  char nomeArquivo_1[] = "/Users/caiovf13/Desktop/UnB/eda/Projeto02/DataSet/asphalt/asphalt_";
  char nomeArquivo_2[] = ".txt";
  char lol[] = "/Users/caiovf13/Desktop/UnB/eda/Projeto02/DataSet/asphalt/asphalt_01.txt";
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




#endif
