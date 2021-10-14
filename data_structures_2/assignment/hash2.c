#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * hashTable[101];

int hashS(char * str, int len){
    int value = 0;
    for(int i=0; i<len; i++){
        value += (str[i] * (i+1)) % 101;
    }
    return (value * 19) % 101;
}//end hashS

int main(){

    int t, n1, count_keys, index, found, len;
    char str[16], addordel, * stringkey;

    scanf(" %d", &t);

    for(int i=0; i<t; i++){

        for(int k=0; k<101; k++){
            hashTable[i] = NULL;
        }

        count_keys = 0;

        scanf(" %d", &n1);

        for(int j=0; j<n1; j++){

            scanf(" %s", str);

            stringkey = &str[4];

            addordel = str[0];

            len = strlen(stringkey);

            switch(addordel){
                case 'A':

                    found = 1;

                    for(int k=0; k<20; k++){
                        
                        index = (hashS(stringkey, len) + k*k + 23*k) % 101;

                        if(hashTable[index] != NULL && strcmp(stringkey, hashTable[index]) == 0){
                            found = 0;
                            break;
                        }

                    }//end for search element

                    if(found){

                        for(int k=0; k<20; k++){
                            index = (hashS(stringkey, len) + k * k + 23 * k) % 101;
                            if(hashTable[index] == NULL){
                                hashTable[index] = malloc(sizeof(char) * (len+1));
                                strcpy(hashTable[index], stringkey);
                                count_keys++;
                                break;
                            }
                        }

                    }//end if insert

                    break;

                case 'D':

                    for(int k=0; k<20; k++){
                        
                        index = (hashS(stringkey, len) + k*k + 23*k) % 101;

                        if(hashTable[index] != NULL && strcmp(stringkey, hashTable[index]) == 0){
                            free(hashTable[index]);
                            hashTable[index] = NULL;
                            count_keys--;
                            break;
                        }

                    }//end for delete element

                    break;

                default:
                    break;
            }//end switch add or del operations

        }//end for operations

        printf("%d\n", count_keys);
        for(int j=0; j<101; j++){
            if(hashTable[j] != NULL){
                printf("%d:%s\n", j, hashTable[j]);
                free(hashTable[j]);
                hashTable[j] = NULL;
            }
        }

    }//end for test cases

    return 0;
}