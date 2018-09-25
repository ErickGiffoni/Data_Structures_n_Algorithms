/* fopen example */
#include <stdio.h>
int main ()
{
  FILE * pFile;
  pFile = fopen ("arq_teste/grass/grass_01.txt","r");
  if (pFile!=NULL)
  {
    printf("Abriu\n");
    fclose (pFile);
    printf("Fechou\n");
  }
  return 0;
}
