#ifndef HASH_H
#define HASH_H

int modular_hash(int a, int b);     // hash by modular division
int mod(int a, int b);              // {support func} implements modular division
int string_hash(char * stringKey);  // hash a string key
int hashS(char *stringKey);         // {support func} hash every char of stringKey based on its ASCII number

#endif