#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void print_vector(double *vector, int elements);
int *recebe_notas(double *nota, int elements, int APR[]);
void conta_notas(int *APR, int elements, int *aprov, int *reprov);
int percent_aprov(int *aprov, int *reprov, double *percent_aprov, double *percent_reprov, int *status);

int main ()
{
    double notas[10];
    int APR[10];
    int *var;

    int aprovados = 0;
    int reprovados = 0;

    int percent;

    int status = 0;

    double per_aprov = 0;
    double per_reprov = 0;

    printf("\nEnter with 10 values of NOTAS:\n");

    for (int i = 0; i < MAX; i++)
    {
        scanf("%lf", &notas[i]);
    }
    printf("Notas:\n");
    print_vector(notas, MAX);

    var = recebe_notas(notas, MAX, APR); 

    conta_notas(APR, MAX, &aprovados ,&reprovados);

    percent = percent_aprov(&aprovados, &reprovados, &per_aprov, &per_reprov, &status);

    printf("\nAprovados: %d\tReprovados: %d\n\n", aprovados, reprovados);
    printf("Percentual de aprovados: %.2lf\tPercentual de reprovados: %.2lf\n\n", per_aprov, per_reprov);

    printf("Mais da metade da turma está %s\n", (status == 1) ? "APROVADA" : "REPROVADA --> SEUS MERDA");

    //free(APR);

    return 0;
}

void print_vector(double *vector, int elements)
{
    for (int i = 0; i < elements; i++)

        printf("%.2lf\n", *(vector+i));
}

int *recebe_notas(double *nota, int elements, int APR[])
{
    for (int i = 0; i < elements; i++)
    {
        if (nota[i] >= 6)
            APR[i] = 1;
        else
            APR[i] = 0;
    }

    return APR;
}

void conta_notas(int *APR, int elements, int *aprov, int *reprov)
{
    for(int i = 0; i < elements; i++)
        *aprov += APR[i];

    *reprov = elements - *aprov;
}

int percent_aprov(int *aprov, int *reprov, double *percent_aprov, double *percent_reprov, int *status)
{
    double total = *aprov + *reprov;

    *percent_aprov = (double)(*aprov/total)*100;
    *percent_reprov = (double)(*reprov/total)*100;

    (*percent_aprov > 50) ? (*status = 1) : (*status = 0);

    return *status; 
}