/*
*   © Erick Giffoni - University of Brasilia
*   Software Engineering - 2020
*   =)
*   compilation:
*   '_$ gcc hashit.c'
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// ERRO - caso de teste in5.txt //

typedef struct Data{

    char stringKey[16]; // string
    char isFree;        // "0" is not free ; "1" is free

} Data;

int modular_hash(int a, int b);                                         // hash by modular division
int mod(int a, int b);                                                  // {support func} implements modular division
int string_hash(char *stringKey);                                       // hash a string key
int hashS(char *stringKey);                                             // {support func} hash every char of stringKey based on its ASCII number
void *new_hash_table(int qttElements);                                  // returns a void * hash table (uses malloc)
int find_index_by_stringKey(char *stringKey, Data **hashTable);         // {support func} finds the index of the element defined by the stringKey
int hashtable_index_not_null(int *index, Data **hashTable);             // {support func} verifies if a position in a hash table is not null given an index
int insert_stringkey_into_hashtable(char *stringkey, Data **hashtable); // {support func} inserts string key into hash table

int main(){

    int t, n1, index_to_delete, count_keys = 0;
    scanf(" %d", &t); //test cases

    char str[16];

    for(int i=0; i<t; i++){

        count_keys = 0;

        Data **hashTable = (Data **)new_hash_table(101*sizeof(Data *));
        for (int k = 0; k < 101; k++){
            hashTable[k] = (Data *)new_hash_table(sizeof(Data));
            hashTable[k]->isFree = '1';
        }

        scanf(" %d", &n1); //operations

        char adddell; //str ADD or DEL

        for(int j=0; j<n1; j++){

            scanf(" %s", str); //fazer o split
            //printf("eu li %s\n", str);

            adddell = str[0];
            //printf("essa é %c\n", adddell);

            //when you see str+4 it means : a 4 bytes shift to avoid "ADD:" or "DEL:"

            switch (adddell){
            case 'A': //add
                //printf("adding %s\n", str);
                if(find_index_by_stringKey(str+4, hashTable) == -1){
                    //printf("adding %s\n", str+4);
                    insert_stringkey_into_hashtable(str+4, hashTable);
                    count_keys ++;
                }//insert
                break;

            case 'D': //del
                //printf("deliting %s\n", str);
                index_to_delete = find_index_by_stringKey(str+4, hashTable);
                if(index_to_delete != -1){                                  // ta errando aqui !!! tenta comparar p.ex. ADD:do e DEL:do - solve : split str em ADD do ou DEL do
                    //printf("deliting %s\n", str+4);
                    hashTable[index_to_delete]->isFree = '1'; //mark as free
                    count_keys --;
                }//delete
                break;
            
            default:
                break;
            }//end switch add or dell string

        }//end for number of operations

        //printf("count keys = %d\n", count_keys);
        printf("%d\n", count_keys);
        //count_keys = 0;

        for(int k=0; k<101; k++){
            if(hashTable[k]->isFree == '0'){
                printf("%d:%s\n", k, hashTable[k]->stringKey);
            }
            free(hashTable[k]);
        }
        free(hashTable);

    }//end for test cases

    return 0;
}

int modular_hash(int a, int b)
{
    /* hash by modular division */
    int c = mod(a, b);
    if (c >= 0)
        return c;
    else
    {
        //printf("## modular_hash error ##\n\t|\n\t ----> returning -1\n\n");
        return -1;
    }
}

int mod(int a, int b)
{
    /* implements modular division */
    if (b == 0)
    {
        //printf("## mod error - parameter b = 0 ##\n\t|\n\t ----> returning -1\n\n");
        return -1;
    }
    else if (a < 0)
    {
        if (b < 0)
            return (a % b) + (-1 * b);
        else
            return (a % b) + b;
    }
    return a % b;
}

int string_hash(char *stringKey)
{
    /* hash a string key - based on problem https://www.spoj.com/problems/HASHIT.pdf */
    return (int)mod(hashS(stringKey), 101);
}

int hashS(char *stringKey)
{
    /* hash every char of stringKey based on its ASCII number */
    /* h(key)= 19 *(ASCII(a1)*1+...+ASCII(an)*n) */
    int mult = 0;
    for (int i = 1; strcmp(&stringKey[0], "\0") != 0; stringKey++, i++)
    {
        mult += ((stringKey[0]) * (i)) % 101;
        //printf("stringKey %d * (%d)\nmult = %d\n", stringKey[0], (i), mult);
    }
    return 19 * mult;
}

void *new_hash_table(int qttElements)
{
    /* returns a void * hash table (uses malloc) */
    void *hashTable = malloc(qttElements);
    if (!hashTable)
    {
        //printf("## new hash table error ##\n\t|\n ----> unable to alocate\n\n");
        return NULL;
    }
    return hashTable;
}

int find_index_by_stringKey(char *stringKey, Data **hashTable)
{
    /* finds the index of the element defined by the stringKey */
    /* returns the index or -1 in case of not found */
    int indexToFind = string_hash(stringKey);
    //printf("index to find is: %d\n", indexToFind);

    if (hashtable_index_not_null(&indexToFind, hashTable))
    {
        //printf("hashtable[indexToFind] is: %s\n", hashTable[indexToFind]->stringKey);

        if (strcmp(hashTable[indexToFind]->stringKey, stringKey) == 0)
        {
            /* contents match */
            //printf("MATCH !!! %s and %s\n", hashTable[indexToFind]->stringKey, stringKey);
            return indexToFind;
        }
        else
        {
            /* tries to find stringKey in other positions */
            int nextIndex = 0;
            //int counter = 20;
            for (int j = 1; j <= 19; j++)
            {
                //if(counter<1){
                //    return -1; // we only try to find the index 20 times
                //}

                nextIndex = indexToFind + j * j + 23 * j;
                nextIndex = mod(nextIndex, 101);
                //printf("now NEXT index to find is: %d\n", nextIndex);

                if (hashtable_index_not_null(&nextIndex, hashTable))
                {
                    //printf("hashtable[NEXT] is: %s\n", hashTable[nextIndex]);

                    if (strcmp(hashTable[nextIndex]->stringKey, stringKey) == 0)
                    {
                        /* contents match */
                        //printf("MATCH !!! %s and %s at index %d\n", hashTable[nextIndex]->stringKey, stringKey, nextIndex);
                        return nextIndex;
                    }
                }
                //else counter --;
            }
        }
    } //end if hashtable index not null

    //printf("index_to_find returning -1\n");

    return -1;
}

int hashtable_index_not_null(int *index, Data **hashTable)
{
    /* Verifies if a position in a hash table is not null given an index */
    if (hashTable[*index] != NULL)
    {
        return 1; // index is valid
    }
    else
        return 0; // index is null
}

int insert_stringkey_into_hashtable(char *stringkey, Data **hashtable)
{
    /* Returns the index where stringkey was inserted in case of successful insertion, -1 otherwise */
    int indexToInsert = string_hash(stringkey);
    if (hashtable_index_not_null(&indexToInsert, hashtable))
    {
        if (hashtable[indexToInsert]->isFree == '1')
        {
            /* do insertion */
            strcpy(hashtable[indexToInsert]->stringKey, stringkey);
            hashtable[indexToInsert]->isFree = '0'; // marks it as not free
            return indexToInsert;
        } //end if is free
        else
        {
            /* colision: find another place to insert */
            int nextIndex = 0;
            for (int j = 1; j <= 19; j++)
            {

                nextIndex = indexToInsert + j * j + 23 * j;
                nextIndex = mod(nextIndex, 101);

                if (hashtable_index_not_null(&nextIndex, hashtable))
                {

                    if (hashtable[nextIndex]->isFree == '1')
                    {
                        /* do insertion */
                        strcpy(hashtable[nextIndex]->stringKey, stringkey);
                        hashtable[nextIndex]->isFree = '0'; // marks it as not free
                        return nextIndex;
                    } //end if is free
                } //end if not null
            }   //end for
        }     //end colision
    }       //end if not null
    return -1;
}