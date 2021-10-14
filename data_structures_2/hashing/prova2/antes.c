#include <stdio.h>

int main()
{

    int qtdrestaurantes = 0;
    int codigo = 0;
    int notaf = 0;
    int nota1 = 0, nota2 = 0;
    int vetcod[2];
    int dia = 1;
    while (scanf(" %d", &qtdrestaurantes) != EOF)
    {
        for (int i = 0; i < qtdrestaurantes; i++)
        {
            scanf(" %d", &vetcod[0]);
            scanf(" %d", &nota1);
            scanf(" %d", &vetcod[1]);
            scanf(" %d", &nota2);
            if (nota1 > nota2)
            { //nota1 maior
                codigo = vetcod[0];
                notaf = nota1;
            }
            else if (nota1 == nota2)
            {
                notaf = nota1;
                if (vetcod[0] > vetcod[1])
                    codigo = vetcod[1];
                else
                    codigo = vetcod[0];
            }
            else
            { // nota2 maior
                codigo = vetcod[1];
                notaf = nota2;
            }
        }
        printf("Dia %d\n", dia);
        printf("%d\n", codigo);
        printf("\n");
        dia++;
    }

    return 0;
}