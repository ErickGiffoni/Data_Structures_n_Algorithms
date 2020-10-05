#include "hash.h"

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