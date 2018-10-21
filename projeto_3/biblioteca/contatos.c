#include "contatos.h"
#include <string.h>
#include <stdio.h>

void menu(int *opcao){
  printf("\t\t\t***** MENU *****\nPor favor, digite o numero da opcao desejada:\n");
  printf("\t1- Inserir novo registro ;\n");
  printf("\t2- Remover registro que contenha certa string no nome ;\n");
  printf("\t3- Visualizar registro que contenha certa string no nome ;\n");
  printf("\t4- Visualizar todos os registros, em ordem alfabetica, de acordo com o nome ;\n");
  printf("\t5- Sair ;\n\n");
  printf("Opcao : ");
  scanf("%d", opcao);

}//end menu

FILE *criaArquivoContatos_txt(){
 return NULL;
}//

Contatos *criaContatosVazia(){
  return NULL;

}// end criaContatosVazia

Contatos *inserirNovoRegistro(Contatos *contatos){
  Contatos *temp;
  temp = (Contatos *)malloc(sizeof(Contatos));
  if(temp==NULL)printf("ALOCACAO FALHOU!\n");

  printf("Informe o nome nome_completo\n");
  scanf("%[^\n]", temp -> nome_completo);
  getchar();

  printf("Informe o número de celular no formato : xxxxx-xxxx\n");
  scanf("%[^\n]", temp -> celular );
  for(int i =6; i<10; i++){
    if(temp->celular[5]!= '-'){
      printf("Formato nao aceito! Tente novamente.\n");
      getchar();
      break;
    }
    if(temp->celular[i]){
      printf("LOL\n");
    }
}

  getchar();  //tratar o erro caso ele digite no formato errado


  printf("Informe o endereco\n");
  scanf("%[^\n]", temp -> endereco);
  getchar();

  unsigned int aux=0;

  printf("Informe o CEP\n");
  scanf("%u", &aux);
  temp -> CEP = (unsigned int)aux;
  getchar();

  printf("Informe a data de nascimento no formato : dd/mm/aaaa\n");
  fgets(temp -> data_de_nascimento, sizeof(temp -> data_de_nascimento), stdin); //tratar o erro caso ele digite no formato errado
  if(temp->data_de_nascimento[2]!= '/' || temp->data_de_nascimento[5]!= '/' ){
    printf("FORMATO INVALIDO, TENTE NOVAMENTE!!\n");
  }

  temp = insertionSort(contatos,temp);
  return temp;

}// end inserirNovoRegistro

Contatos *adicionaContatosDoArquivo(FILE *ponteiroParaArquivo){

  ponteiroParaArquivo = fopen("../contatos/contatos.txt","r");
  if(ponteiroParaArquivo==NULL){
  printf("FALHA AO ABRIR ARQUIVO\n");
  exit(1);
}
int cont_linhas=0;
int cont_contatos=0;

while(!feof(ponteiroParaArquivo)){ //WHILE PARA DETERMINAR QUANTIDADE DE LINHAS E QUANTIDADE DE COLUNAS.
  char carac;
  fscanf(ponteiroParaArquivo, "%c", &carac);
  if(carac=='\n')cont_linhas++;
  if(carac=='$')cont_contatos++;
}
printf("Quantidade de linas = %d\nQuantidade de contatos = %d\n",cont_linhas,cont_contatos);
fclose(ponteiroParaArquivo);

char m_contatos[cont_linhas][100];//MATRIZ QUE ARMAZENA CONTATOS INICIAIS .txt
ponteiroParaArquivo = fopen("../contatos/contatos.txt","r");
if(ponteiroParaArquivo==NULL){
  printf("ERRO AO ABRIR ARQUIVO\n" );
  exit(-2);
}

for(int i=0;i<(cont_linhas-1);i++){
    fscanf(ponteiroParaArquivo," %[^\n]",m_contatos[i]);
}
for(int i=0;i<(cont_linhas-1);i++){
  printf("%s\n",m_contatos[i]);
}


Contatos *temp;
temp = (Contatos *)malloc(sizeof(Contatos));
if(temp == NULL){
  printf("erro de alocagem temp\n" );
}
Contatos *temp2;
temp2 = (Contatos *)malloc(sizeof(Contatos));
if(temp2==NULL){
  printf("erro de alocagem temp2\n");
}

strcpy(temp->nome_completo,m_contatos[0]);
strcpy(temp->celular,m_contatos[1]);
strcpy(temp->endereco,m_contatos[2]);
temp->CEP =  ((unsigned int) m_contatos[3]);
strcpy(temp->data_de_nascimento,m_contatos[4]);
printf("%s\n",temp->nome_completo );
printf("%s\n",temp->celular );
printf("%s\n",temp->endereco );
printf("%u\n",temp->CEP );
printf("%s\n",temp->data_de_nascimento );
temp -> proximo = NULL;
temp -> anterior = NULL;
printf("erro aqui3\n");

   for(int i=6;(i<cont_linhas);i++){
     if(strcmp(m_contatos[i],"$")==0)i++;
     strcpy(temp2->nome_completo,m_contatos[i]);
     i++;
     strcpy(temp2->celular,m_contatos[i]);
     i++;
     strcpy(temp2->endereco,m_contatos[i]);
     i++;
     temp2->CEP =  ((unsigned int) m_contatos[i]);
     i++;
     strcpy(temp2->data_de_nascimento,m_contatos[i]);
     temp2 -> proximo = NULL;
     temp2 -> anterior = NULL;
     printf("erro aqu4\n" );
     temp = insertionSort(temp,temp2);
   }
return temp;
}// end adicionaContatosDoArquivo

void liberaContatos(Contatos *contatos){

}// end liberaContatos


int removerContatosPorString(char *stringParaRemover, Contatos *deOndeRemover){
  return 0;

}// end removerContatosPorString

Contatos *visualizarContatosPorString(char *stringInformada, Contatos *ondePesquisar){
  return NULL;

}// end visualizarContatosPorString

void visualizarTodosOsContatos(Contatos *contatos){
  while(contatos->prox!= NULL){
    printf("%s\n",contatos->nome_completo );
    printf("%s\n",contatos->celular );
    printf("%s\n",contatos->endereco );
    printf("%u\n",contatos->CEP);
    printf("%s\n",contatos->data_de_nascimento );
    printf("\n\n\n\n\n");
    contatos = contatos->proximo;
  }


}// end visualizarTodosOsContatos

void sair(){

}// end sair

Contatos *insertionSort(Contatos *base,Contatos *compare) {
  int c;
  int c_aux;
  Contatos *aux;
  Contatos *aux2;
  aux = (Contatos *)malloc(sizeof(Contatos));

  if(aux==NULL){
    printf("ERRO DE ALOCAGEM AUX\n");
  }

  aux2 = (Contatos *)malloc(sizeof(Contatos));
  if(aux2==NULL){
    printf("ERRO DE ALOCAGEM AUX2\n");
  }

  aux  = base->proximo;
  int cont=0;
  do{
      printf("erro\n" );
    c = strcmp(base->nome_completo, compare->nome_completo);
  printf("Erro\n" );
  if(base->proximo==NULL && base->anterior==NULL){
    if(c>0) {
      compare->proximo = base;
      compare->anterior = NULL;
      base->anterior = compare;
      base->proximo = NULL;
      return compare;
    }
    else if(c<0){
      compare->proximo = NULL;
      compare -> anterior = base;
      base->anterior = NULL;
      base ->proximo = compare;
      return base;
    }
  }
  else{
    c_aux = strcmp(aux->nome_completo, compare->nome_completo);
    if(c<0){
      compare->proximo = base;
      compare->anterior = NULL;
      base->anterior = compare;
      aux2 = compare;
      break;
    }
    else if(c<0 && c_aux>0){
      base->proximo = compare;
      compare->anterior = base;
      compare->proximo = aux;
      aux->anterior = compare;
      aux2 = base;
      break;
    }
    else if(c_aux<0){
      base = base -> proximo;
      aux = aux->proximo;
    }
  }
}while(compare->anterior!=NULL || compare->proximo!=NULL);
  return aux2;
}
