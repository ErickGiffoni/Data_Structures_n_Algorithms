#ifndef HASH_H
#define HASH_H

int modular_hash(int a, int b);     // hash by modular division
int mod(int a, int b);              // {support func} implements modular division
int string_hash(char * stringKey);  // hash a string key
int hashS(char *stringKey);         // {support func} hash every char of stringKey based on its ASCII number
void *new_hash_table(int qttElements); // returns a void * hash table (uses malloc)
int find_index_by_stringKey(char *stringKey, char **hashTable); // {support func} finds the index of the element defined by the stringKey
int hashtable_index_not_null(int *index, char **hashTable);     // {support func} verifies if a position in a hash table is not null given an index
int insert_stringkey_into_hashtable(char *stringkey, char **hashtable); // {support func} inserts string key into hash table

#endif