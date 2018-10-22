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
  FILE *newFile;
  do{
  newFile = fopen("../contatos/newListOfContacts.txt", "w");
}while(newFile == NULL);
 return newFile;
}//

Contatos *criaContatosVazia(){
  Contatos *temp;
  temp = (Contatos *)malloc(sizeof(Contatos));
  if(temp==NULL){
  printf("Criacao de novo contato falhou!\n");
  return NULL;
  }
  else {
    temp -> proximo = NULL;
    temp -> anterior = NULL;
  }
return temp;
}// end criaContatosVazia

Contatos *inserirNovoRegistro(Contatos *contatos){
  Contatos *temp;
  temp = (Contatos *)malloc(sizeof(Contatos));
  if(temp==NULL){
    printf("Alocacao de novo registro falhou!\n");
    return NULL;
  }

  printf("Informe o nome nome_completo\n");
  scanf("%[^\n]", temp -> nome_completo);
  getchar();

  do{
    int verifica = 1 ; // true
    printf("Informe o número de celular no formato : xxxxx-xxxx\n");
    scanf("%[^\n]", temp -> celular );
    for(int i =6; i<10; i++){
      if(temp->celular[5]!= '-' || temp->celular[i-6] < '48' || temp->celular[i-6] > '57'){
        printf("Formato nao aceito! Tente novamente.\n");
        getchar();
        verifica = 0;
        break;
      }// end if verifica se tem '-' e se tem numeros nas posicoes 0,1,2,3
      if(temp->celular[4] < '48' || temp->celular[4] > '57' || temp->celular[i] < '48' || temp->celular[i] > '57'){
        printf("Formato nao aceito! Tente novamente.\n");
        getchar();
        verifica = 0;
        break;
      }//end if verifica se tem numeros nas posicoes 6,7,8,9
    }

  }while(!verifica);

  getchar();  //tratar o erro caso ele digite no formato errado


  printf("Informe o endereco\n");
  scanf("%[^\n]", temp -> endereco);
  getchar();

  unsigned int aux=0;

  printf("Informe o CEP\n");
  scanf("%u", &aux);
  temp -> CEP = (unsigned int)aux;
  getchar();

 do{
  printf("Informe a data de nascimento no formato : dd/mm/aaaa\n");
  fgets(temp -> data_de_nascimento, sizeof(temp -> data_de_nascimento), stdin); //tratar o erro caso ele digite no formato errado
    if(temp->data_de_nascimento[2]!= '/' || temp->data_de_nascimento[5]!= '/' ){
      printf("FORMATO INVALIDO, TENTE NOVAMENTE!!\n");
    }

  }while(temp->data_de_nascimento[2]!= '/' || temp->data_de_nascimento[5]!= '/');

  //temp = insertionSort(contatos,temp);
//printf("cheguei\n");
  return temp;

}// end inserirNovoRegistro

Contatos **adicionaContatosDoArquivo(FILE *ponteiroParaArquivo){

  ponteiroParaArquivo = fopen("../contatos/contatos.txt","r");
  if(ponteiroParaArquivo==NULL){
  printf("FALHA AO ABRIR ARQUIVO\n");
  //exit(1);
  return NULL;
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
  //exit(-2);
  return NULL;
}

for(int i=0;i<(cont_linhas-1);i++){
    fscanf(ponteiroParaArquivo," %[^\n]",m_contatos[i]);
}
for(int i=0;i<(cont_linhas-1);i++){
  printf("%s\n",m_contatos[i]);
}


Contatos **temp;
temp = (Contatos **)malloc(cont_contatos * sizeof(Contatos *)); //cont_contatos linhas, cada uma aponta para um contato

for(int i =0; i<cont_contatos; i++){
  temp[i] = (Contatos *) malloc(1 * sizeof(Contatos)); //1 coluna, cada uma e um contato
}

if(temp == NULL){
  printf("erro de alocagem temp\n" );
}
//Contatos *temp2;
//temp2 = (Contatos *)malloc(sizeof(Contatos));
//if(temp2==NULL){
//  printf("erro de alocagem temp2\n");
//}

  for(int i=0; i< cont_contatos; i++){
    if() continue;
    strcpy(temp[i][0]->nome_completo,m_contatos[i]);
    strcpy(temp[i][0]->celular,m_contatos[i+1]);
    strcpy(temp[i][0]->endereco,m_contatos[i+2]);
    temp[i][0]->CEP =  ((unsigned int) m_contatos[i+3]);
    strcpy(temp[i][0]->data_de_nascimento,m_contatos[i+4]);
    printf("%s\n",temp[i][0]->nome_completo );
    printf("%s\n",temp[i][0]->celular );
    printf("%s\n",temp[i][0]->endereco );
    printf("%u\n",temp[i][0]->CEP );
    printf("%s\n",temp[i][0]->data_de_nascimento );
    temp -> proximo = NULL;
    temp -> anterior = NULL;
    printf("erro aqui3\n");
  }

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

   ponteiroParaArquivo = fopen("../contatos/contatos2.txt","w"); //mudar para escrita
return temp;
}// end adicionaContatosDoArquivo

void liberaContatos(Contatos *contatos){
  Contatos *aux;

    if(contatos->anterior == NULL){ // primeiro elemento da lista

      do{
        aux = contatos->proximo; // aux aponta para proximo
        free(contatos);
        contatos = aux;
      }while(aux != NULL);

    }// primeiro elemento da lista
    else{ //nao e o primeiro da lista

      do{ //fazer os ponteiros chegarem ao primeiro elemento na lista
        aux = contatos->anterior;
        contatos = aux;
      }while(aux->anterior != NULL);

      do{ // liberar tudo
        aux = contatos->proximo; // aux aponta para proximo
        free(contatos);
        contatos = aux;
      }while(aux != NULL);

    }// end else nao e o primeiro da lista

}// end liberaContatos


int removerContatosPorString(char *stringParaRemover, Contatos *deOndeRemover){
  return 0;

}// end removerContatosPorString

Contatos *visualizarContatosPorString(char *stringInformada, Contatos *ondePesquisar){
  return NULL;

}// end visualizarContatosPorString

void visualizarTodosOsContatos(Contatos *contatos){
  Contatos *aux;
  do{ //fazer os ponteiros chegarem ao primeiro elemento na lista
    aux = contatos->anterior;
    contatos = aux;
  }while(aux->anterior != NULL);

  while(contatos!= NULL){ // criterio de parada e quando o ponteiro em si nao aponta para nenhum contato
    printf("%s\n",contatos->nome_completo );
    printf("%s\n",contatos->celular );
    printf("%s\n",contatos->endereco );
    printf("%u\n",contatos->CEP);
    printf("%s\n",contatos->data_de_nascimento );
    printf("\n\n\n\n\n");
    contatos = contatos->proximo;
  }


}// end visualizarTodosOsContatos

void sair(FILE *ondeSalvar, Contatos *contatos){
  Contatos *aux;
  if(contatos->anterior!=NULL){ //checar se estamos no primeiro elemento da lista
    do{ //fazer os ponteiros chegarem ao primeiro elemento na lista
      aux = contatos->anterior;
      contatos = aux;
    }while(aux->anterior != NULL);
  }


  //percorrer todos os contatos e escreve-los no arquivo
  for(aux = contatos; aux != NULL; aux = aux->proximo){
    fprintf(ondeSalvar, "%s",aux->nome_completo);
    fprintf(ondeSalvar, "\n");
    fprintf(ondeSalvar, "%s",aux->celular);
    fprintf(ondeSalvar, "\n");
    fprintf(ondeSalvar, "%s",aux->endereco);
    fprintf(ondeSalvar, "\n");
    fprintf(ondeSalvar, "%u",aux->CEP);
    fprintf(ondeSalvar, "\n");
    fprintf(ondeSalvar, "%s",aux->data_de_nascimento);
    fprintf(ondeSalvar, "\n$\n");
  }

}// end sair

Contatos *insertionSort(Contatos *base,Contatos *compare) {
  Contatos *aux;
  aux = (Contatos *)malloc(sizeof(Contatos));
  if(aux==NULL)printf("ERRO DE ALOCACAO AUX\n");

  Contatos *aux2;
  aux2 = (Contatos *)malloc(sizeof(Contatos));
  if(aux2==NULL)printf("ERRO DE ALOCACAO AUX2\n");

  Contatos *aux_base;
  aux_base = (Contatos *)malloc(sizeof(Contatos));
  if(aux_base ==NULL)printf("ERRO DE ALOCACAO aux_base\n");

  Contatos *aux_compare;
  aux_compare = (Contatos *)malloc(sizeof(Contatos));
  if(aux_compare ==NULL)printf("ERRO DE ALOCACAO AUX\n");
  aux_compare = compare;


  int cont  = 1;

  int c = strcmp(base->nome_completo, compare->nome_completo);

  printf("%d\n",c);
  printf("%s\n",base->nome_completo);
  printf("%s\n",base->proximo->nome_completo);
  printf("%s\n",compare->nome_completo);
  printf("%s\n",base->proximo );
  printf("%s\n",base->anterior );
    if((base->proximo==NULL) && (base->anterior==NULL)){
      if(c<0){
        base->proximo = aux_compare;
        aux_compare->anterior = base;
        aux_compare->proximo = NULL;
        printf("\n\n\nbase nome_completo: %s\n", base->nome_completo);
        printf("compare nome_completo: %s\n\n\n",base->proximo->nome_completo );
        aux = base;
        return aux;

      }
      if(c>0){
        aux_compare->anterior = NULL;
        aux_compare->proximo = base;
        base->anterior = aux_compare;
        aux = aux_compare;
        return aux;

      }
    }
    else if(base->proximo!=NULL){
      aux2 = base->proximo;
      int c_aux = strcmp(aux2->nome_completo,aux_compare->nome_completo);
      printf("\n\n\nbase nome_completo: %s\n", base->nome_completo);
      printf("aux2 nome_completo: %s\n",aux2->nome_completo );
      printf("compare nome_completo: %s\n\n\n",aux_compare->nome_completo );
      if(c>0){
        aux_compare ->proximo = base;
        base->anterior = aux_compare;
        aux = aux_compare;
        return aux;

      }
      else if(c<0 && c_aux>0){
        aux_compare->anterior = base;
        base->proximo = aux_compare;
        aux2->anterior = aux_compare;
        aux = base;
        return aux;

      }
      else if(c<0 && c_aux<0){
        aux_base
        do{
          base = base->proximo;
          aux2 = aux2->proximo;
          c = strcmp(base->nome_completo, aux_compare->nome_completo);
          c_aux = strcmp(aux2->nome_completo,aux_compare->nome_completo);
            if(c<0){
              base->proximo = aux_compare;
              aux_compare->anterior = base;
              aux_compare -> proximo = aux2;
              aux2->anterior = aux_compare;
              cont = 0;
              aux = base;
              return aux;

            }
            else if(c>0 && c_aux<0){
              aux_compare->anterior = NULL;
              aux_compare->proximo = base;
              base->anterior = aux_compare;
              cont = 0;
              aux = aux_compare;
              return aux;
            }
        }while (cont != 0);
        printf("\n\n\n\n\n\n" );
        printf("%d\n",c);
        printf("%s\n",base->nome_completo);
        printf("%s\n",compare->nome_completo);
        printf("%s\n",base->proximo);
        printf("%s\n",base->anterior);

      }
    }
  return aux;
}
