/* strstr example */
#include <stdio.h>
#include <string.h>

//Return Value
//A pointer to the first occurrence in str1 of the entire sequence of characters specified in str2,
//or a null pointer if the sequence is not present in str1.

int main ()
{
  char str[] ="This is a simple string";
  char * pch;
  char is[] = "Is";
  pch = strstr (str,is);
  //strncpy (pch,"sample",6);
  //puts (str);
  if(pch == NULL) printf("Nao contido\n");
  else printf("Contido\n");
  return 0;
}
