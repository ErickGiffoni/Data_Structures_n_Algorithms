#ifndef AEROLIBRARY_H
#define AEROLIBRARY_H

// ! Implementacoes no aeroLibrary.c !

// ******* Estruturas *******
typedef struct voo{
  char codigo_de_voo[7] ; // vetor de char, que e o codigo de voo alocado estaticamente na main
  char tipo; // D -> decolagem ; A -> aproximacao ; P -> pouso
  int combustivel; // se for do tipo aproximacao, tera um numero de combustivel : 0 e pouco e 12 e muito
  struct voo *proximo ; // proximo da fila de voos
}Voo;

typedef struct fila{
  Voo *primeiro; // ponteiro para Voo no inicio da fila, primeiro elemento a ser atendido
  Voo *ultimo; // ponteiro para Voo no final da fila, ultimo a ser atendido
}Fila;

// ******* Variaveis *******
char codigos_de_voos[64][7] = {{"VG3001"}, {"JJ4404"}, {"LN7001"}, {"TG1501"}, {"GL7602"}, {"TT1010"}, {"AZ1009"}, {"AZ1008"},
                               {"AZ1010"}, {"TG1506"}, {"VG3002"}, {"JJ4402"}, {"GL7603"}, {"RL7880"}, {"AL0012"}, {"TT4544"},
                               {"TG1505"}, {"VG3003"}, {"JJ4403"}, {"JJ4401"}, {"LN7002"}, {"AZ1002"}, {"AZ1007"}, {"GL7604"},
                               {"AZ1006"}, {"TG1503"}, {"AZ1003"}, {"JJ4403"}, {"AZ1001"}, {"LN7003"}, {"AZ1004"}, {"TG1504"},
                               {"AZ1005"}, {"TG1502"}, {"GL7601"}, {"TT4500"}, {"RL7801"}, {"JJ4410"}, {"GL7607"}, {"AL0029"},
                               {"VV3390"}, {"VV3392"}, {"GF4681"}, {"F4690 "}, {"Z1020 "}, {"J4435 "}, {"VG3010"}, {"LF0920"},
                               {"AZ1065"}, {"LF0978"}, {"RL7867"}, {"TT4502"}, {"GL7645"}, {"LF0932"}, {"JJ4434"}, {"TG1510"},
                               {"TT1020"}, {"AZ1098"}, {"BA2312"}, {"VG3030"}, {"BA2304"}, {"KL5609"}, {"KL5610"}, {"KL5611"} };

#define unTempo  5 ; //minutos
int relogio_global[4] = {0,0,0,0} ; // 00:00 h -> hora de inicio dos trabalhos no aeroporto

int NDecolagens ; // de 10 a 32
int NAproximacoes ; // de 10 a 32
int NVoos ; // NDecolagens + NAproximacoes // de 20 a 64

int CombA ; // combustivel para aproximacao

int tempo_de_aproximacao = 1*unTempo;
int tempo_de_decolagem = 2*unTempo;
int tempo_de_pouso = 3*unTempo;

// ******* Funcionalidades *******
criarVoo();
excluirVoo();

criarFila();
excluirFila();

#endif
