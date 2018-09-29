#include <stdio.h>
#include "../libraries/ILBP_library.h"

int main(){
  int n1, n2;
  scanf("%d %d", &n1, &n2);
  int result = s_function(n1,n2);
  printf("Result : %d\n", result);
}
