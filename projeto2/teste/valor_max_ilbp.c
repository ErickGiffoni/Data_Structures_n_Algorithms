#include <stdio.h>
#include <math.h>

void somatorio_de_2(int *);

int main(){

int soma = 0;
somatorio_de_2(&soma);
printf("valor max ILBP : %d\n", soma); // 511

return 0;
}

void somatorio_de_2(int * soma){

  for (int i=0; i<=8; i++){
    *soma += pow(2,i);
  }
// 511
}
