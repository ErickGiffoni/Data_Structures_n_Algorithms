#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "../library/aeroLibrary.h"

void menuInicial(int *, int *, int *);

int main(){


  // ******* Variaveis *******
  char codigo_de_voos[64][7] = {{"VG3001"}, {"JJ4404"}, {"LN7001"}, {"TG1501"}, {"GL7602"}, {"TT1010"}, {"AZ1009"}, {"AZ1008"},
                                 {"AZ1010"}, {"TG1506"}, {"VG3002"}, {"JJ4402"}, {"GL7603"}, {"RL7880"}, {"AL0012"}, {"TT4544"},
                                 {"TG1505"}, {"VG3003"}, {"JJ4403"}, {"JJ4401"}, {"LN7002"}, {"AZ1002"}, {"AZ1007"}, {"GL7604"},
                                 {"AZ1006"}, {"TG1503"}, {"AZ1003"}, {"JJ4403"}, {"AZ1001"}, {"LN7003"}, {"AZ1004"}, {"TG1504"},
                                 {"AZ1005"}, {"TG1502"}, {"GL7601"}, {"TT4500"}, {"RL7801"}, {"JJ4410"}, {"GL7607"}, {"AL0029"},
                                 {"VV3390"}, {"VV3392"}, {"GF4681"}, {"F4690 "}, {"Z1020 "}, {"J4435 "}, {"VG3010"}, {"LF0920"},
                                 {"AZ1065"}, {"LF0978"}, {"RL7867"}, {"TT4502"}, {"GL7645"}, {"LF0932"}, {"JJ4434"}, {"TG1510"},
                                 {"TT1020"}, {"AZ1098"}, {"BA2312"}, {"VG3030"}, {"BA2304"}, {"KL5609"}, {"KL5610"}, {"KL5611"} };


  int unTempo = 5 ; //minutos
  int relogio_global[4] = {0,0,0,0} ; // 00:00 h -> hora de inicio dos trabalhos no aeroporto



  int CombA ; // combustivel para aproximacao

  int tempo_de_aproximacao = 1*unTempo;
  int tempo_de_decolagem = 2*unTempo;
  int tempo_de_pouso = 3*unTempo;

  srand( (unsigned)time(NULL) );

  int NDecolagens ; // de 10 a 32
  NDecolagens = rand() % 23;  //Gerando aleatóris de 0 a 22
  NDecolagens += 10; // Somando 10 para o intervalo ser definido entre 10 e 32;
  int NAproximacoes ; // de 10 a 32
  NAproximacoes = rand() % 23; // Same as NDecolagens
  NAproximacoes += 10;


  int NVoos = NAproximacoes + NDecolagens; // NDecolagens + NAproximacoes // de 20 a 64
  printf("NVoos = %d\n\n", NVoos);
  char Voos[6][NVoos];


  //ESCOLHER OS NVOOS DE FORMA ALEATÓRIA
  int random_flight_numbers[NVoos]; //Vetor que ira receber os os valores aleatório para cada voo
  int aux  = 0;
  int aux2 = 0;
  int aux3 = 0;

  for(int i=0; i<NVoos; i++){ //INSERE NO VETOR random_flight_numbers NUMEROS ALEATÓRIOS DE 0 A 64, TRATANDO A REPETICAO.
      aux = 0;
      aux = rand() % 64;
      random_flight_numbers[i] = aux;
        for(int j=0; j<i; j++){
          if(random_flight_numbers[j] == random_flight_numbers[i]){
            aux = rand() % 64;
            random_flight_numbers[i] = aux;
            j=0;
          }
        }
    //  printf(" %d\n",random_flight_numbers[i] );
  }
/*  for(int i=0; i<NVoos; i++){ //PRINTA O VETOR COM NÚMEROS ALEATÓRIOS
    printf(" %d\n",random_flight_numbers[i]);
  } */



  // fazer a fila com os codigos de modo aleatorio e classificar cada voo conforme o codigo

    Voo *voo;
    voo = (Voo *)malloc(sizeof(Voo));
    if(voo==NULL)printf("ALOCACAO VOO NA MAIN FALHOU \n");
        //voo = criarVooNull();
    char voos_aleatorios[NVoos][7];

    for(int i=0; i<NVoos;i++){
      strcpy(voos_aleatorios[i],codigo_de_voos[random_flight_numbers[i]]);
      //printf("%s\n",voos_aleatorios[i]);

      char *auxc;
      auxc = (char *)malloc(7*sizeof(char));
      if (auxc == NULL)printf("erro ao alocar auxc\n");

      auxc = voos_aleatorios[i];
      if(i==0){
        voo = criarVoo(auxc);
        continue;
      }
      voo = insereInicio(voo,criarVoo(auxc));

    }
    randomizeModo(voo);
    randomizeNivelDeCombustivel(voo);
    //imprimeVoos(voo);


  // fazer a fila com os codigos de modo aleatorio e classificar cada voo conforme o codigo

  Fila *fila_de_aproximacao = criaFila(); //ponteiro para fila de aproximacao
  Fila *fila_de_decolagem = criaFila(); //ponteiro para fila de decolagem

  Voo *percorre_voos = (Voo *) malloc(sizeof(Voo)); //alocaao dinamica de um auxuliar para percorrer a lista de voos
  Voo *aux_percorre = (Voo *) malloc(sizeof(Voo)); //alocaao dinamica de um auxuliar para apontar para o percorre_voos
  if(percorre_voos == NULL) printf("Alocacao do percorre_voos falhou\n\n");
  if(aux_percorre == NULL) printf("Alocacao do aux do percorre_voos falhou\n\n");

  //percorre_voos = voo; //aponta para a lista de voos
  aux_percorre = percorre_voos; //aponta para percorre_voos

  for(percorre_voos = voo; voo!=NULL; ){
    //verificar o tipo e adicionar a fila correta, fazer percorre_voos = percorre_voos->proximo
      //tipo A
        if(voo->tipo == 'A'){
          percorre_voos = voo->proximo; //atualizacao do percorre_voos na lista

          //ja tem elemento na fila ?
            if(fila_de_aproximacao->primeiro == NULL){ //nao tem elemento na fila
              fila_de_aproximacao->primeiro = voo;
              voo->proximo = NULL;
              fila_de_aproximacao->ultimo = voo;
              //printf("Voo tipo = %c\n", voo->tipo);

            } // end if nao tem elemento na fila
            else{ //tem elemento na fila
              adicionaVooNaFila(voo, fila_de_aproximacao->ultimo);
              //printf("Voo codigo na fila = %s\n", voo->codigo_de_voo);

            }// end else tem elemento na fila

        }//end if tipo A

      //tipo D
        else{
          percorre_voos = voo->proximo; //atualizacao do percorre_voos na lista

          //ja tem elemento na fila ?
          if(fila_de_decolagem->primeiro == NULL){ //nao tem elemento na fila
            fila_de_decolagem->primeiro = voo;
            voo->proximo = NULL;
            fila_de_decolagem->ultimo = voo;
            //printf("Voo tipo = %c\n", voo->tipo);

          } // end if nao tem elemento na fila
          else{ //tem elemento na fila
            adicionaVooNaFila(voo, fila_de_decolagem->ultimo);
            //printf("Voo codigo na fila = %s\n", voo->codigo_de_voo);

          }// end else tem elemento na fila

        }//end else tipo D

    voo = percorre_voos; //atualiza o aux_percorre
  }// end for percorrer os voos

  // ordenar a fila de aproximacao  a partir do primeiro elemento 


  // chamar o menu, depois mostrar cada voo na tela, um por um



  // liberar toda a memoria usada



  // FIM

  return 0;
}

void menuInicial(int *NVoo, int *NAproximacoes, int *NDecolagens){
  printf("--------------------------------------------------------------------------------\n");
 	printf("Aeroporto Internacional de Brasília\n");
 	printf("Hora inicial: %s\n",__TIME__);
 	printf("Fila de Pedidos: \n");
 	printf("\tNúmero de Voos Total: %d\n", *NVoo);
 	printf("\tVoos Aproximações: %d\n", *NAproximacoes);
 	printf("\tVoos Decolagens: %d\n", *NDecolagens);
 	printf("--------------------------------------------------------------------------------\n");
 	printf("Listagem de eventos:\n\n");
}
