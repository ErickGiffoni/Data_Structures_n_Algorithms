/*
*   © Erick Giffoni - University of Brasilia
*   Software Engineering - 2020
*   =)
*   compilation:
*   '_$ gcc basic_hashing.c hash.c -o basic.out'
*/

#include <stdio.h>
#include "hash.h"

int main(){
    //int modHash = modular_hash(-12, -36);
    //printf("%d\n", modHash);

    //char stringKey[15];
    //scanf(" %s", stringKey);
    //printf("%s\n", stringKey);
    //printf("%d\n", string_hash(stringKey));

    //int * ptr = (int *) new_hash_table(10);
    //if(ptr){
    //    printf("ok\n");
    //    for(int i=0; i<10; i++){
    //        printf("%d\n", ptr[i]);
    //        printf("size: %lu\n", sizeof(ptr[i]));
    //    }
    //    free(ptr);
    //}
    //else printf("error\n");

    //char stringKey[15];
    //scanf(" %s", stringKey);
    //printf("%s\n", stringKey);
    //printf("%d\n", string_hash(stringKey));
    //char ** hashTable = (char **) new_hash_table(101);
    //for(int i=0; i<10; i++)
    //    hashTable[i] = (char *) new_hash_table(15);
    //hashTable[string_hash(stringKey)] = stringKey;
    //int index = find_index_by_stringKey("erick", hashTable);
    //printf("index is: %d\n", index);

    // testing insertion //
    //char stringKey[16];
    Data data;
    scanf(" %s", data.stringKey);
    printf("%s\n", data.stringKey);
    int indice = string_hash(data.stringKey);
    printf("%d\n", indice);
    Data **hashTable = (Data **)new_hash_table(101);
    for (int i = 0; i < 101; i++){
        hashTable[i] = (Data *)new_hash_table(1);
        hashTable[i]->isFree = '1'; // problemas ?
    }
    //strcpy(hashTable[indice]->stringKey, data.stringKey);
    //printf("inserido -> %s\n", hashTable[indice]->stringKey);

    int insertedIndex = insert_stringkey_into_hashtable(data.stringKey, hashTable);
    if(insertedIndex != -1){
        printf("insercao bem feita no indice %d\n%s\n", insertedIndex, hashTable[insertedIndex]->stringKey);
        printf("achei a string no indice %d\n", find_index_by_stringKey("abcde", hashTable));
    }
    else puts("deu bom nao a insercao");
    //------------------//

    return 0;
}
