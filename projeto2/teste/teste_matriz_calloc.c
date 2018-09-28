#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* calloc, exit, free */

int main ()
{
  int linha,n,coluna,k;
  int ** pData;

  printf ("Amount of numbers to be entered: rows columns");
  scanf ("%d %d",&linha, &coluna);

  pData = (int**) calloc (linha,sizeof(int*));

  for(k=0; k<linha; k++) pData[k] = (int *)calloc(coluna,sizeof(int));

  if (pData==NULL) exit (1);

  for (n=0;n<linha;n++)
  {
    for( k=0; k<coluna; k++){
      printf ("Enter number #%d: ",n+1);
      scanf ("%d", &pData[n][k]);
    }
  }

  printf ("You have entered: \n");
  for (n=0;n<linha;n++){
    for( k=0; k<coluna; k++)
     printf ("%d ", pData[n][k]);
    printf("\n");
  }

  free (pData);
  return 0;
}
