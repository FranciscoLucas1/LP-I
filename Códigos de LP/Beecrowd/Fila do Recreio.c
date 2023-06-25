#include <stdio.h>
#include <stdlib.h>

void imprimir(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%04d\n", v[i]);
    }
}

void bubble(int v[], int n)
{
    int i, j, aux, trocas = 0;
    for (i = n - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (v[j] > v[j + 1])
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                trocas++;
            }
        }
    }
    if (trocas == 0)
    {
        printf("%i\n", n);
    }
    else
    {
        printf("%i\n", n - trocas);
    }
}

int main(void)
{

    int nCasos;
    int nAlunos;

    scanf("%i", &nCasos);

    for (int i = 0; i < nCasos; i++)
    {
        scanf("%i", &nAlunos);

        int alunos[nAlunos];

        for (int i = 0; i < nAlunos; i++)
        {
            scanf("%i", &alunos[i]);
        }

        bubble(alunos, nAlunos);
    }

    return 0;
}
