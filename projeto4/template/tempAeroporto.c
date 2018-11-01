#include <stdio.h>
#include "../library/aeroLibrary.h"

void menuInicial(int *, int *, int *);

int main(){

  // escolher os NVoos etc de modo aleatorio



  // fazer a fila com os codigos de modo aleatorio e classificar cada voo conforme o codigo



  // para cada voo de aproximacao, aleatorizar o numero de combustivel e reordenar a fila, se necessario
    //acho q nesse caso, a gente percorre a fila e ve se tem 3 aeronaves com combustivel 0, tenta pousar elas,
    // e se nao der, simplismente as remove da fila, nao importa a posicao em que aquele voo esteja 



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
