#include <stdio.h>
#include <stdlib.h>

void bolhaReversa(int v[], int n)
{
    int i, j, aux;
    for (i = n - 1; i > 0; i--)
    { // da última posição para a primeira
        for (j = 0; j < i; j++)
        { // passa por todos os elementos ainda não ordenados
            if (v[j] < v[j + 1])
            { // bolha - troca
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

int main(void)
{

    int qntH; // habitantes
    int nConsultas; // consultas
    int posi;
    while (scanf("%i %i", &qntH, &nConsultas) != EOF)
    {

        int notasCid[qntH];

        for (int i = 0; i < qntH; i++)
        {
            scanf("%i", &notasCid[i]);
        }

        bolhaReversa(notasCid, qntH);

        for (int j = 0; j < nConsultas; j++)
        {
            scanf("%i", &posi);
            printf("%i\n", notasCid[posi-1]);
        }
    }

    return 0;
}
