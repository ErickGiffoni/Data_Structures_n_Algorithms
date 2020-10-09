#include "hash.h"
#include <string.h>

int modular_hash(int a, int b){
/* hash by modular division */
    int c = mod(a, b);
    if(c>=0) return c;
    else{
        printf("## modular_hash error ##\n\t|\n\t ----> returning -1\n\n");
        return -1;
    }
}

int mod(int a, int b){
/* implements modular division */
    if (b == 0){
        printf("## mod error - parameter b = 0 ##\n\t|\n\t ----> returning -1\n\n");
        return -1;
    }
    else if (a < 0){
        if(b < 0) return (a % b) + (-1 * b);
        else return (a % b) + b;
    }
    return a % b;
}

int string_hash(char * stringKey){
/* hash a string key - based on problem https://www.spoj.com/problems/HASHIT.pdf */
    return (int) mod( hashS(stringKey), 101 );
}

int hashS(char * stringKey){
/* hash every char of stringKey based on its ASCII number */
/* h(key)= 19 *(ASCII(a1)*1+...+ASCII(an)*n) */
    int mult = 0;
    for(int i=1; strcmp(&stringKey[0], "\0") != 0; stringKey ++, i++){
        mult += (stringKey[0]) * (i);
        //printf("stringKey %d * (%d)\nmult = %d\n", stringKey[0], (i), mult);
    }
    return 19 * mult;
}