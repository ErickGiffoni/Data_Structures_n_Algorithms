/*
*   © Erick Giffoni - University of Brasilia
*   Software Engineering - 2020
*   Final Assignment
*   Problem : https://moj.naquadah.com.br/contests/bcrEDA2-20201-trabalho/D.pdf
*   =)
*   compilation:
*   '_$ gcc database.c'
*/

#include <stdio.h>
#include <string.h>

int main(){

    int n; //qtt of emails
    scanf(" %d", &n);

    char emails[1000][101];
    char tmp[101];

    int unique_users = 0;

    if(n==1){
        scanf(" %s", tmp);
        printf("1\n");
        return 0;
    }

    //if(n==0)
    //    return 0;

    for(int i=0; i<n; i++){
        scanf(" %s", tmp);
        char * j = &tmp[0];
        while(strcmp(j, "\0")!=0){
            if(*j=='@')
                break;
            if(*j!='.'){
                strncat(emails[i], j, 1); //concatenates every caracter but skips this -> '.'
            }
            //printf("%c\n", *j);
            j++;
        }
        //find '+' and ignore
        char * sum = strchr(emails[i], '+');
        if(sum){
            emails[i][sum-emails[i]] = '\0'; //ignores '+' and everuthing after it
        }
        strcat(emails[i], j); //concatenates the remaining string starting at '@'
        //puts(emails[i]);
    }//end for reads emails

    int equal; //bool equal or not equal
    int dot1; //position of @ in string
    int dot2; //position of @ in string
    char username1[101]; //user name tmp
    char username2[101]; //user name tmp
    tmp[0] = '@'; tmp[1] = '\0';

    //printf("tmp -> %s\n\n", tmp);

    for(int i=0; i<n; i++){
        equal = 0; //not equal
        //if emails[i][0] == + then continue; already visited
        if(emails[i][0] == '+'){
            continue;
        }
        //printf("email %d -> %s\n", i, emails[i]);
        dot1 = strcspn(emails[i], tmp); //find the @ index
        //printf("dot1 is at %d\n", dot1);
        strncpy(username1, emails[i], dot1); //copy the first dot1 characters to username1
        username1[dot1] = '\0';
        //printf("username1 is %s\n\n", username1);
        for(int j=i+1; j<n; j++){
            //compare user names
                //if equal
                    //compare providers
                        //if equal then
                            //mark emails[j][0] with +
                            //mark equal = 1;
           dot2 = strcspn(emails[j], tmp); //find the @ index
           strncpy(username2, emails[j], dot2); //copy the first dot2 characters to username2
           username2[dot2] = '\0';

           if(strcmp(username1, username2) == 0){
               if(strcmp(&emails[i][dot1], &emails[j][dot2]) == 0){
                   emails[j][0] = '+';
                   equal = 1;
               }//end if providers are equal
           }//end if user names are equal
        }
        //if equal == 0 then unique_users++
        //if(equal == 0){
            unique_users++;
        //}
    }//end for count unique users

    printf("%d\n", unique_users);

    return 0;
}
