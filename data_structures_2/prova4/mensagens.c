/*
*   © Erick Giffoni - University of Brasilia
*   Software Engineering - 2020
*   Final Test 4
*   Problem : https://moj.naquadah.com.br/contests/bcrEDA2-20201-4aatividadeavaliacao/mensagens.html
*   =)
*   compilation:
*   '_$ gcc euvou.c'
*/

#include <stdio.h>
#include <stdlib.h>

#define seq_max 2147483648 //long int 2^31
#define msn_max 1048576*2 //int tamanho max da mensagem
#define number 1048583

char mensagem[msn_max];
char c;
long int s;
long int menor = seq_max;
long int maior = 0;
long int * indices;
long int count = 0;

int main(void){

    int index;
    indices = (long int *) calloc(msn_max, sizeof(long int));

    while(scanf(" %ld %c", &s, &c) != EOF){
        index = s % number;
        //if(s >= (number)){
        //    s = s % (number); //deixa dentro do intervalo de msn_max
        //}
        //printf("caracter %c\n", c);
        if(indices[index] == 0){
            count++;
            if(s < menor) menor = s;
            if(s > maior) maior = s;
            mensagem[index] = c;
            indices[index] = 1;
        }
        //printf("mensagem s %ld é %c\n\n", s, mensagem[s]);
    }//end while
    //mensagem[maior+1] = '\0';

    int tmp;
    for(int i=0; i<count; i++){
        tmp = (menor + i) % number;
        printf("%c", mensagem[tmp]);
    }//end for print

    puts("");

    //printf("%s\n", &mensagem[menor]);
    //printf("\ncount e %ld\n", count);

    return 0;
}//end main