
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

typedef struct no No;
struct no{
    char* nome;
    char* tipo;          // P = pouso, D = decolagem
    int comb;           //  entre 0-12, 0 = prioridade maxima de pouso
    No* prox;
};

typedef struct head Head;
struct head{
    No* inicio;
    No* fim;
};

int randomize(int lower, int upper, int count){
    int i;
    for (i = 0; i < count; i++) {
        int num = (rand() %
           (upper - lower + 1)) + lower;
        return num;
    }
}

int main(){
    srand(time(NULL));

	int nVoos;
	int nAprox = randomize(10, 32, 1);
    int nDecol = randomize(10, 32, 1);

    nVoos = nAprox + nDecol;

    int arrayVoos[nVoos];
    int arrayDecol[nDecol], arrayAprox[nAprox];
    int i=1,j=0;

	int pista = 0;
    int critic = 0;
    int horaAtual = 0, minutoAtual = 0;
    int cont = 0;

    arrayVoos[0]=rand()%63+1;

    do {
        arrayVoos[i]=rand()%63+1;
        j=0;
        while (j<i) {
            if (arrayVoos[j]==arrayVoos[i]) {
                --i;
                break;
            }
            ++j;
        }
        ++i;
    } while (i<nVoos);

    int k=0;
    for (i=0;i<nAprox;i++) {
        arrayAprox[i] = arrayVoos[i];
        k++;
    }

    for (i=0;i<nDecol;i++) {
        arrayDecol[i] = arrayVoos[k];
        k++;
    }

    char codAvioes[64][7] = {"VG3001", "JJ4404", "LN7001", "TG1501",
                    "GL7602", "TT1010", "AZ1009", "AZ1008",
                    "AZ1010", "TG1506", "VG3002", "JJ4402",
                    "GL7603", "RL7880", "AL0012", "TT4544",
                    "TG1505", "VG3003", "JJ4403", "JJ4401",
                    "LN7002", "AZ1002", "AZ1007", "GL7604",
                    "AZ1006", "TG1503", "AZ1003", "JJ4403",
                    "AZ1001", "LN7003", "AZ1004", "TG1504",
                    "AZ1005", "TG1502", "GL7601", "TT4500",
                    "RL7801", "JJ4410", "GL7607", "AL0029",
                    "VV3390", "VV3392", "GF4681", "GF4690",
                    "AZ1020", "JJ4435", "VG3010", "LF0920",
                    "AZ1065", "LF0978", "RL7867", "TT4502",
                    "GL7645", "LF0932", "JJ4434", "TG1510",
                    "TT1020", "AZ1098", "BA2312", "VG3030",
                    "BA2304", "KL5609", "KL5610", "KL5611"};

    No* lista = NULL;
    Head* head = (Head*)malloc(sizeof(Head));
    head->inicio = NULL;
    head->fim = NULL;

    for (i = 0; i < nAprox; i++) {
        No* atual = lista;
        No* anterior = NULL;
        int combRandom = randomize(0,12,1);

        No* novo = (No*)malloc(sizeof(No));
        novo->nome = codAvioes[arrayAprox[i]];
        novo->tipo = "A";
        novo->comb = combRandom;

        if (atual == NULL) {
            novo->prox = NULL;
            lista = novo;
        } else {
            while (atual != NULL && atual->comb < combRandom){
                anterior = atual;
                atual = atual->prox;
            }
            novo->prox = atual;

            if (anterior == NULL) {
                lista = novo;
            } else {
                anterior->prox = novo;
            }
        }
    }

    for (i = 0; i < nDecol; i++) {
        No* aux = head->inicio;
        int combRandom = -1;

        No* novo = (No*)malloc(sizeof(No));
        novo->nome = codAvioes[arrayDecol[i]];
        novo->tipo = "D";
        novo->comb = combRandom;
        novo->prox = NULL;

        if (head->fim == NULL) {
            head->inicio = novo;
            head->fim = novo;
        } else {
            head->fim->prox = novo;
            head->fim = novo;
        }
    }

    No* aux2 = lista;
    while (aux2->prox != NULL) {
        aux2 = aux2->prox;
    }

    aux2->prox = head->inicio;

	time_t now;
    now = time(NULL);

 	printf("--------------------------------------------------------------------------------\n");
 	printf("Aeroporto Internacional de Brasília\n");
 	printf("Hora inicial: %s\n",__TIME__);
 	printf("Fila de Pedidos: \n");
 	printf("Número de Voos Total: %d\n",nVoos);
 	printf("Voos Aproximações: %d\n",nAprox);
 	printf("Voos Decolagens: %d\n",nDecol);
 	printf("--------------------------------------------------------------------------------\n");
 	printf("Listagem de eventos\n\n");

    No* node;
    for (node = lista; node != NULL; node = node->prox) {
	    if (node->comb == 0) {
	    	pista = randomize(1,3,1);
	    	if (pista == 3) {
	    		cont++;
	    	}
	    	critic++;
	    	if (critic == 3) {
	    		printf("ALERTA GERAL DE DESVIO DE AERONAVE\n\n");
	    		critic = 0;
	    		if(cont == 3) {
	    			printf("ALERTA CRÍTICO, AERONAVE IRÁ CAIR\n\n");
	    		}
	    	} else {
	    		printf("Código do voo: %s\n", node->nome);
 				printf("Status: Pousou\n");
 				printf("Número da pista: %d\n\n", pista);
	    	}
	    }

	    if (strcmp(node->tipo, "D") == 0) {
    		pista = randomize(1,3,1);
    		printf("Código do voo: %s\n", node->nome);
			printf("Status: Decolou\n");
			printf("Número da pista: %d\n\n", pista);
			if (pista == 3) {
				cont++;
			}
    	} else {
    		pista = randomize(1,2,1);
    		printf("Código do voo: %s\n", node->nome);
			printf("Status: Pousou\n");
			printf("Número da pista: %d\n\n", pista);
    	}
    }

    return 0;
}
