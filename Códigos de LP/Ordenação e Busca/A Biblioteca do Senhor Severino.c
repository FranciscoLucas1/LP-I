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
    int i, j, aux;
    for (i = n - 1; i > 0; i--)
    { // da última posição para a primeira
        for (j = 0; j < i; j++)
        { // passa por todos os elementos ainda não ordenados
            if (v[i] < v[j])
            { // bolha - troca
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

int main(void)
{
    int n;

    while (scanf("%d", &n) != EOF)
    {

        int listaLivros[n];

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &listaLivros[i]);
        }

        bubble(listaLivros, n);
        imprimir(listaLivros, n);
    }

    return 0;
}
