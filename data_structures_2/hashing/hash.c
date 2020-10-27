#include "hash.h"
#include <string.h>
#include <stdlib.h>

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

void * new_hash_table(int qttElements){
/* returns a void * hash table (uses malloc) */
    void * hashTable = malloc(qttElements);
    if(!hashTable){
        printf("## new hash table error ##\n\t|\n ----> unable to alocate\n\n");
        return NULL;
    }
    return hashTable;
}

int find_index_by_stringKey(char * stringKey, Data ** hashTable){
/* finds the index of the element defined by the stringKey */
/* returns the index or -1 in case of not found */
    int indexToFind = string_hash(stringKey);
    //printf("index to find is: %d\n", indexToFind);

    if(hashtable_index_not_null(&indexToFind, hashTable)){
        //printf("hashtable[indexToFind] is: %s\n", hashTable[indexToFind]);

        if(strcmp(hashTable[indexToFind]->stringKey, stringKey) == 0){
            /* contents match */
            //printf("MATCH !!! %s and %s\n", hashTable[indexToFind], stringKey);
            return indexToFind;
        }
    }
    else{
        //printf("entrei\n");
        /* tries to find stringKey in other positions */
        int nextIndex = 0;
        //int counter = 20;
        for(int j=1; j<=19; j++){
            //if(counter<1){
            //    return -1; // we only try to find the index 20 times
            //}

            nextIndex = indexToFind + j*j + 23*j;
            nextIndex = mod(nextIndex, 101);
            //printf("now NEXT index to find is: %d\n", nextIndex);

            if(hashtable_index_not_null(&nextIndex, hashTable)){
                //printf("hashtable[NEXT] is: %s\n", hashTable[nextIndex]);

                if (strcmp(hashTable[nextIndex]->stringKey, stringKey) == 0){
                    /* contents match */
                    //printf("MATCH !!! %s and %s at index %d\n", hashTable[nextIndex], stringKey, nextIndex);
                    return nextIndex;
                }
            }
            //else counter --;
        }
    }
    return -1;
}

int hashtable_index_not_null(int * index, Data ** hashTable){
/* Verifies if a position in a hash table is not null given an index */
    if(hashTable[*index] != NULL){
        return 1; // index is valid
    }
    else return 0; // index is null
}

int insert_stringkey_into_hashtable(char * stringkey, Data ** hashtable){
/* Returns the index where stringkey was inserted in case of successful insertion, -1 otherwise */
    int indexToInsert = string_hash(stringkey);
    // verificar se index esta vazio
    printf("inicio do insert\n");
    if(hashtable_index_not_null(&indexToInsert, hashtable)){
        printf("entrei\n");
        //verificar se ja ha algo naquele indice

        //printf("o que tem aqui e: %s |||\n", hashtable[indexToInsert]);
        strcpy(hashtable[indexToInsert]->stringKey, stringkey);
        hashtable[indexToInsert]->isFree = 0; // marks it as not free
        return indexToInsert;
    }
    else return -1;
}