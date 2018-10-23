#include "contatos.h"
#include <string.h>
#include <stdio.h>

void menu(int *opcao){
  printf("\t\t\t***** MENU *****\nPor favor, digite o numero da opcao desejada:\n");
  printf("\t1- Inserir novo registro;\n");
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
}// end cria contatos.txt

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

  int verifica = 0 ; // false
  do{
    printf("Informe o número de celular no formato : xxxxx-xxxx\n");
    scanf("%[^\n]", temp -> celular );
    //for(int i=6; i<10; i++){
      if(temp->celular[5]!= '-'/* || temp->celular[i-6] < '48' || temp->celular[i-6] > '57'*/){
        printf("Formato nao aceito! Tente novamente.\n");
        getchar();
        verifica = 1;

      }// end if verifica se tem '-' e se tem numeros nas posicoes 0,1,2,3
      /*if(temp->celular[4] < '48' || temp->celular[4] > '57' || temp->celular[i] < '48' || temp->celular[i] > '57'){
        printf("Formato nao aceito! Tente novamente.\n");
        getchar();
        verifica = 0;
        break;
      }*///end if verifica se tem numeros nas posicoes 6,7,8,9
      else verifica = 0; // false
    }while(verifica);

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

  contatos = insertionSort(contatos, temp);
//printf("cheguei\n");
  return contatos;

}// end inserirNovoRegistro

Contatos *adicionaContatosDoArquivo(FILE *ponteiroParaArquivo){

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

char *p_m_contatos;
p_m_contatos = (char *)malloc(sizeof(cont_linhas*100));
char m_contatos[cont_linhas][100];//MATRIZ QUE ARMAZENA CONTATOS INICIAIS .txt

rewind(ponteiroParaArquivo);
if(ponteiroParaArquivo==NULL){
  printf("ERRO AO ABRIR ARQUIVO\n" );
  //exit(-2);
  return NULL;
}

for(int i=0;i<(cont_linhas-1);i++){
    fscanf(ponteiroParaArquivo," %[^\n]",m_contatos[i]);
}

fclose(ponteiroParaArquivo);
p_m_contatos = m_contatos;

for(int i=0;i<(cont_linhas-1);i++){
  printf("%s\n",p_m_contatos + (i * 100));
}


Contatos *temp;
temp = criaLista(p_m_contatos, 0);
for(int i = 6;i< cont_linhas-5; i+=6){
  printf("temp->nome_completo = %s\n",temp->nome_completo );
  temp = insertionSort(temp,criaLista(p_m_contatos, i));
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


/*Contatos *adicionaLista(Contatos *temp, Contatos *temp2){
  temp2->proximo = temp;
  temp ->anterior = temp2;

  return temp2;
}*/

Contatos *criaLista(char *p_m_contatos,int posicao){
  Contatos *temp;
  temp = (Contatos *)malloc(sizeof(Contatos));
  if(temp == NULL)printf("FALHA NA ALOCACAO TEMO CRIALIST\n");
  printf("erro aqui\n");
  int contador = 0;

  for(int i = posicao ;contador == 0; i++){
  strcpy(temp->nome_completo, (p_m_contatos + (i * 100)));
  printf("\n\n\ntemp-> nome_completo: %s\n",temp->nome_completo );
  i++;
  strcpy(temp->celular, (p_m_contatos + (i * 100)));
  printf("temp-> nome_celular : %s\n\n\n",temp->celular );
  i++;
  strcpy(temp->endereco, (p_m_contatos + (i * 100)));
  i++;
  temp->CEP = (unsigned int)(p_m_contatos + (i * 100));
  i++;
  strcpy(temp->data_de_nascimento, (p_m_contatos + (i * 100)));
  contador ++;
}
  temp->proximo= NULL;
  temp->anterior = NULL;


    return temp;
}

int removerContatosPorString(char *stringParaRemover, Contatos *deOndeRemover){
  //retorna 1 se removeu, 0 caso contrario. Deve percorrer a lista e tentar remover aquele nome, depois reordenar a lista
  Contatos *aux, *aux2 = deOndeRemover; //aux2 = deOndeRemover

  aux = aux2;
  char *verificador; // usado para verificar se a string esta contida no nome de algum contato
  int conta_verificador=0;

  for(aux2; aux2!=NULL; aux2 = aux2->proximo){// for percorre lista

    aux = aux2; //aux = deOndeRemover

    verificador = strstr(aux2->nome_completo, stringParaRemover);
    if(verificador != NULL){ //if string contida no nome_completo
      conta_verificador ++;
      printf("Nome %s encontrado\n", aux2->nome_completo);
      if(aux2->anterior == NULL){ // if string esta no primeiro contato da lista
        aux2->proximo->anterior = NULL;
        //aux2 = aux2->proximo;
        free(aux);
        deOndeRemover = aux2->proximo; // atualiza o primeiro elemento da lista
        //aux = aux2; //aux = deOndeRemover
      }// end if string esta no primeiro contato da lista
      else if(aux2->proximo == NULL){// if string esta no ultimo contato da lista
        aux2->anterior->proximo = NULL;
        //aux2 = aux2->anterior;
        free(aux);
      //  aux = aux2;
      } // end if string esta no ultimo contato da lista
      else{ // string nem no primeiro nem no ultimo
        aux2->anterior->proximo = aux2->proximo;
        aux2->proximo->anterior = aux2->anterior;
        //aux2 = aux2->proximo; nao precisa, por conta do for acima
        free(aux);
        aux = aux2;
      }// end else string nem no primeiro nem no ultimo

    }// end if string contida no nome_completo
    else{ // string nao contida no nome_completo
      continue;
    }// end else string nao contida no nome_completo

  }// end for percorre lista

  if(conta_verificador > 0) return 1;
  else {printf("Contato nao identificado na base de dados existente\n");return 0;}

}// end removerContatosPorString

void visualizarContatosPorString(char *stringInformada, Contatos *ondePesquisar){
  Contatos *aux;
  if(ondePesquisar->anterior != NULL){
    do{ //fazer os ponteiros chegarem ao primeiro elemento na lista
      aux = ondePesquisar->anterior;
      ondePesquisar = aux;
    }while(aux->anterior != NULL);
  }

  char *verificador; // usado para verificar se a string esta contida no nome de algum contato
  int conta_os_prints = 0;

  for(aux; aux!=NULL; aux = aux->proximo){// for percorre lista

    ondePesquisar = aux;

    verificador = strstr(ondePesquisar->nome_completo, stringInformada);
    if(verificador != NULL){ //if string contida no nome_completo
      printf("Contato encontrado :\n");
      printf("\t%s\n",ondePesquisar->nome_completo );
      printf("\t%s\n",ondePesquisar->celular );
      printf("\t%s\n",ondePesquisar->endereco );
      printf("\t%u\n",ondePesquisar->CEP);
      printf("\t%s\n",ondePesquisar->data_de_nascimento );
      getchar();
      conta_os_prints ++;
    }
    else{ // string nao contida no nome_completo
      continue;
    }// end else string nao contida no nome_completo

  }// end for percorre lista
  if(conta_os_prints == 0){
    printf("Nenhum contato encontrado. Tente novamente.\n");
    getchar();
  }

}// end visualizarContatosPorString

void visualizarTodosOsContatos(Contatos *contatos){
  Contatos *aux;
  if(contatos == NULL){
    printf("Nenhum contato cadastrado. Cadastre um contato.\n");
  }


  for(aux = contatos; aux!=NULL; aux = aux->proximo){
    printf("%s\n",aux->nome_completo );
    printf("%s\n",aux->celular );
    printf("%s\n",aux->endereco );
    printf("%u\n",aux->CEP);
    printf("%s\n",aux->data_de_nascimento );
    printf("\n\n\n\n\n");
    contatos = contatos->proximo;
  }


}// end visualizarTodosOsContatos

void sair(Contatos *contatos){
  Contatos *aux;

  FILE *file_sair;
  file_sair = fopen("../contatos/contatos.txt", "w");
  if(file_sair == NULL){
    FILE *novo_sair;
    novo_sair = fopen("../contatos/newListOfContacts", "w");

    for(aux = contatos; aux != NULL; aux = aux->proximo){
      fprintf(novo_sair, "%s",aux->nome_completo);
      fprintf(novo_sair, "\n");
      fprintf(novo_sair, "%s",aux->celular);
      fprintf(novo_sair, "\n");
      fprintf(novo_sair, "%s",aux->endereco);
      fprintf(novo_sair, "\n");
      fprintf(novo_sair, "%u",aux->CEP);
      fprintf(novo_sair, "\n");
      fprintf(novo_sair, "%s",aux->data_de_nascimento);
      fprintf(novo_sair, "\n$\n");
    }
  }
  if(contatos == NULL){
    printf("Nenhum contato cadastrado. Cadastre um contato.\n");
    getchar();
  }
  for(aux = contatos; aux != NULL; aux = aux->proximo){
    fprintf(file_sair, "%s",aux->nome_completo);
    fprintf(file_sair, "\n");
    fprintf(file_sair, "%s",aux->celular);
    fprintf(file_sair, "\n");
    fprintf(file_sair, "%s",aux->endereco);
    fprintf(file_sair, "\n");
    fprintf(file_sair, "%u",aux->CEP);
    fprintf(file_sair, "\n");
    fprintf(file_sair, "%s",aux->data_de_nascimento);
    fprintf(file_sair, "\n$\n");
  }

}// end sair

Contatos *insertionSort(Contatos *temp,Contatos *temp2) {

Contatos *aux_temp;
aux_temp = (Contatos *)malloc(sizeof(Contatos));
if(aux_temp==NULL)printf("Alocacao aux_temp falhou\n");
aux_temp = temp;


Contatos *aux_temp2;
aux_temp2 = (Contatos *)malloc(sizeof(Contatos));
if(aux_temp2==NULL)printf("Alocacao aux_temp falhou\n");

  int cont  = 1;

  int c = strcmp(temp->nome_completo, temp2->nome_completo);


  //  getchar();
    if((temp->proximo==NULL) && (temp->anterior==NULL)){
      if(c<0){
        temp->proximo = temp2;
        temp2->anterior = temp;
      //  printf("\n\n\ntemp nome_completo: %s\n", temp->nome_completo);
      //  printf("temp2 nome_completo: %s\n\n\n",temp->proximo->nome_completo );
        return temp;

      }
      if(c>0){
        temp2->proximo = temp;
        temp->anterior = temp2;
        return temp2;

      }
    }
    else if(temp->proximo!=NULL){
      aux_temp2 = temp->proximo;
      int c_aux = strcmp(aux_temp2->nome_completo,temp2->nome_completo);
    //  printf("\n\n\ntemp nome_completo: %s\n", temp->nome_completo);
    //  printf("aux_temp2 nome_completo: %s\n",aux_temp2->nome_completo );
    //  printf("temp2 nome_completo: %s\n\n\n",temp2->nome_completo );
      if(c>0){
        temp2 ->proximo = temp;
        temp->anterior = temp2;
        temp->proximo = aux_temp2;
        aux_temp2->anterior = temp;
        return temp2;

      }
      else if(c<0 && c_aux>0){
        temp->proximo = temp2;
        temp2->anterior = temp;
        temp2->proximo = aux_temp2;
        aux_temp2->anterior = temp2;

        return temp;

      }
      else if(c<0 && c_aux<0){
        aux_temp = temp;
        aux_temp2 = aux_temp2;
        do{
          temp = temp->proximo;
          aux_temp2 = aux_temp2->proximo;
          c = strcmp(temp->nome_completo, temp2->nome_completo);
          c_aux = strcmp(aux_temp2->nome_completo,temp2->nome_completo);
            if(c<0 && c_aux>0){
              aux_temp2->anterior = temp2;
              temp2 -> proximo = aux_temp2;
              temp2->anterior = temp;
              temp->proximo = temp2;
              cont = 0;
              return aux_temp;
            }
            if(aux_temp2->proximo == NULL){
              temp->proximo = aux_temp2;
              aux_temp2->anterior = temp;
              temp2 -> anterior = aux_temp2;
              aux_temp2->proximo = temp2;
              return aux_temp;
            }

        }while (cont != 0);
      }
    }
  return NULL;
}
