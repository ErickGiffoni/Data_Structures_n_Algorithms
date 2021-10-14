#include <stdio.h>
#include <stdlib.h>

int main(){
    int * aout = (int *) calloc(3, sizeof(int));
    int * i = aout;
    while(i!=NULL){
        printf("...\n");
        i++;
    }
    return 0;
}