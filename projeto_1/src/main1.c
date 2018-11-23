#include <stdio.h>
#define MAX 10


void print_vector(double *vector, double elements);
int *fneuronio(double *ENTRADAS, double *PESOS, double limiar, double len, int *status);

int main ()
{
    double ENTRADAS[MAX] = {0};
    double PESOS[MAX] = {0};
    double T;
    int status = 0;
    int *check;

    printf("Enter with 10 value of ENTRADAS:\n");

    for (int i = 0; i <= MAX; i++)

        scanf("%lf", &ENTRADAS[i]);

    print_vector(ENTRADAS, MAX);

    printf("Enter with 10 value of PESOS:\n");

    for (int j = 0; j <= 10; j++)

        scanf("%lf", &PESOS[j]);

    print_vector(PESOS, MAX);

    printf("Enter with the value of limiar:\n");

    scanf("%lf", &T);

    printf("\n\nLimiar = %.4lf\n", T);

    check = fneuronio(ENTRADAS, PESOS, T, 10, &status);

    if (status == 1)
        printf("\nNeurônio ativado!\n");

    else     
        printf("\nNeurôno inibido!\n");

    return 0;
}

void print_vector(double *vector, double elements)
{
    printf("Valores:\n");

    for (int i = 0; i <= elements; i++)

        printf("%.4lf\n", *(vector + i));

}

int *fneuronio(double *ENTRADAS, double *PESOS, double limiar, double len, int *status)
{
    double SOMAP = 0;

    for (int i = 0; i < len; i++)

        SOMAP += ENTRADAS[i] * PESOS[i];

    *status = SOMAP > limiar;

    return status;
}