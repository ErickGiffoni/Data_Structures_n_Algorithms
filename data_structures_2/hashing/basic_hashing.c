/*
*   © Erick Giffoni - University of Brasilia
*   Software Engineering - 2020
*   =)
*   compilation:
*   '_$ gcc basic_hashing.c hash.c -o prog'
*/

#include <stdio.h>
#include "hash.h"

int main(){
    //int modHash = modular_hash(-12, -36);
    //printf("%d\n", modHash);
    char stringKey[15];
    scanf(" %s", stringKey);
    printf("%s\n", stringKey);
    printf("%d\n", string_hash(stringKey));
}