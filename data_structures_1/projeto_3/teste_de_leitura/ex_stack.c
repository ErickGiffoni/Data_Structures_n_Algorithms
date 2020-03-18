#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>

int main(void)
{
  int i = 0;
  char *a = (char *) malloc(sizeof(char) * 1024);
  while (1) {
    scanf("%c", &a[i]);
    if (a[i] == '\n') {
      break;
    }
    else {
      i++;
    }
  }
  a[i] = '\0';
  i = 0;
  printf("\n");
  while (a[i] != '\0') {
    printf("%c", a[i]);
    i++;
  }
  free(a);
  puts("\n");
  //getch();
  return 0;
}
