#include <stdio.h>

int main(){

  printf("--------------------------------------------------------------------------------\n");
 	printf("Aeroporto Internacional de Brasília\n");
 	printf("Hora inicial: %s\n",__TIME__);
 	printf("Fila de Pedidos: \n");
 	printf("Número de Voos Total: \n");
 	printf("Voos Aproximações: \n");
 	printf("Voos Decolagens: \n");
 	printf("--------------------------------------------------------------------------------\n");
 	printf("Listagem de eventos\n\n");

  char codigos_de_voos[64][6] = {{"VG3001"}, {"JJ4404"}, {"LN7001"}, {"TG1501"}, {"GL7602"}, {"TT1010"}, {"AZ1009"}, {"AZ1008"},
                                 {"AZ1010"}, {"TG1506"}, {"VG3002"}, {"JJ4402"}, {"GL7603"}, {"RL7880"}, {"AL0012"}, {"TT4544"},
                                 {"TG1505"}, {"VG3003"}, {"JJ4403"}, {"JJ4401"}, {"LN7002"}, {"AZ1002"}, {"AZ1007"}, {"GL7604"},
                                 {"AZ1006"}, {"TG1503"}, {"AZ1003"}, {"JJ4403"}, {"AZ1001"}, {"LN7003"}, {"AZ1004"}, {"TG1504"},
                                 {"AZ1005"}, {"TG1502"}, {"GL7601"}, {"TT4500"}, {"RL7801"}, {"JJ4410"}, {"GL7607"}, {"AL0029"},
                                 {"VV3390"}, {"VV3392"}, {"GF4681"}, {"F4690 "}, {"Z1020 "}, {"J4435 "}, {"VG3010"}, {"LF0920"},
                                 {"AZ1065"}, {"LF0978"}, {"RL7867"}, {"TT4502"}, {"GL7645"}, {"LF0932"}, {"JJ4434"}, {"TG1510"},
                                 {"TT1020"}, {"AZ1098"}, {"BA2312"}, {"VG3030"}, {"BA2304"}, {"KL5609"}, {"KL5610"}, {"KL5611"} };

  int unTempo = 5 ; //minutos
  int relogio_global[4] = {0,0,0,0} ; // 00:00 h -> hora de inicio dos trabalhos no aeroporto

  int NDecolagens ; // de 10 a 32
  int NAproximacoes ; // de 10 a 32
  int NVoos ; // NDecolagens + NAproximacoes // de 20 a 64

  int CombA ; // combustivel para aproximacao

  int tempo_de_aproximacao = 1*unTempo;
  int tempo_de_decolagem = 2*unTempo;
  int tempo_de_pouso = 3*unTempo;

  // escolher os NVoos etc de modo aleatorio



  // fazer a fila com os codigos de modo aleatorio



  //

  return 0;
}
