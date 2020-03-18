#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct contatos{
  char nome_completo[101];
  char celular[11];
  char endereco[101];
  unsigned int CEP;
  char data_de_nascimento[11];

  struct contatos *anterior;
  struct contatos *proximo;
}typedef Contatos;

  Contatos *criaContatosVazia();
  Contatos *criaElemento();
  Contatos *adicionaContatosDoArquivo(char *);

int main(){

  Contatos *contatos;
  //contatos = criaContatosVazia();
  contatos = criaElemento();

  FILE *fp_cont;
  fp_cont = fopen("contatos/contatos.txt","r");
  if(fp_cont == NULL){
    printf("falha na abertura\n");
    exit(-1);
  }
  int cont_linhas=0;
  int cont_contatos=0;
  while(!feof(fp_cont)){
    char carac;
    fscanf(fp_cont, "%c", &carac);
    if(carac=='\n')cont_linhas++;
    if(carac=='$')cont_contatos++;
  }
  printf("Quantidade de linas = %d\nQuantidade de contatos = %d\n",cont_linhas,cont_contatos);
  fclose(fp_cont);

  char m_contatos[cont_linhas][100];
  fp_cont = fopen("contatos/contatos.txt","r");
  for(int i=0;i<(cont_linhas-1);i++){
      fscanf(fp_cont," %[^\n]",m_contatos[i]);
  }
  for(int i=0;i<(cont_linhas-1);i++){
    printf("%s\n",m_contatos[i]);
  }


return 0;
}

  Contatos *criaContatosVazia(){
    return NULL;
  }

  Contatos *criaElemento(){

    Contatos *temp;
    temp = (Contatos *)malloc(sizeof(Contatos));
    if(temp==NULL)printf("ALOCACAO FALHOU!\n");




    printf("Informe o nome nome_completo\n");
    scanf("%[^\n]", temp -> nome_completo);
    getchar();

    printf("Informe o número de celular\n");
    scanf("%[^\n]", temp -> celular );
    getchar();


    printf("Informe o endereco\n");
    scanf("%[^\n]", temp -> endereco);
    getchar();

    unsigned int aux=0;

    printf("Informe o CEP\n");
    scanf("%u", &aux);
    temp -> CEP = (unsigned int)aux;
    getchar();

    printf("Informe a data de nascimento\n");
    fgets(temp -> data_de_nascimento, sizeof(temp -> data_de_nascimento), stdin);



    printf("%s\n", temp->nome_completo);
    printf("%s\n",temp->celular);
    printf("%s\n",temp->endereco);
    printf("%d\n",temp->CEP );
    printf("%s\n",temp->data_de_nascimento);

    return temp;
  }
