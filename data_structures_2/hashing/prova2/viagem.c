/*
*   © Erick Giffoni - University of Brasilia
*   Software Engineering - 2020
*   =)
*   Problem : Viagem Aconselha
*/

#include <stdio.h>

int main(){

    int qtdrestaurantes = 0;
    int codigo = 0;
    int notaf = 0;
    int vetcod[200];
    int vetnota[200];
    int dia = 1;
    while (scanf(" %d", &qtdrestaurantes)!=EOF){
       for(int i=0; i<qtdrestaurantes; i++){
           scanf(" %d", &vetcod[i]);
           scanf(" %d", &vetnota[i]);
       }// leitura
       notaf = vetnota[0];
       codigo = vetcod[0];
       for(int i=1; i<qtdrestaurantes; i++){
           if(vetnota[i]>notaf){
               notaf = vetnota[i];
               codigo = vetcod[i];
           }
           else if(vetnota[i]==notaf){
               if(codigo>vetcod[i]){
                   codigo = vetcod[i];
               }
           }
        }// end compara notas
       printf("Dia %d\n", dia);
       printf("%d\n", codigo);
       printf("\n");
       dia++;
    }

    return 0;
}