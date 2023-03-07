#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct dados
{
    char nome[50];
    int dia;
    int mes;
    int ano;
    int idade;
} Dados;
//int calcIdade(int diaN, int mesN, int anoN, int opc);

Dados info[14];
int main()
{
    FILE *in, *out;
    char n[20], nascimento[30];
    char dia[6], mes[6], ano[6];
    char barra[2];
    int maisVelha = 0, maisNova = 0;
    int i = 0;
    int maiorI, menorI = 0;

    in = fopen("dados.txt", "r");
    if (in == NULL)
    {
        printf("Arquivo não encontrado\n");
        return 0;
    }

    fscanf(in, "%s %s", n, nascimento);

    while (!feof(in))
    {
        fscanf(in, "%s %s %c %s %c %s", info[i].nome, dia, &barra[0], mes, &barra[1], ano);

        info[i].dia = atoi(dia);
        info[i].mes = atoi(mes);
        info[i].ano = atoi(ano);

        info[i].idade = 2023 - info[i].ano;

        if (info[i].idade > maisVelha)
        {
            maisVelha = info[i].idade;
            maiorI = i;
            maisNova = maisVelha;
        }
        if (info[i].idade < maisNova)
        {
            maisNova = info[i].idade;
            menorI = i;
        }

        i++;
    }
    fclose(in);

    out = fopen("saida.txt", "w");

    for (int j = 0; j < i; j++)
    {
        fprintf(out, "%s %i / %i / %i - %i \n", info[j].nome, info[j].dia, info[j].mes, info[j].ano, 2023 - info[j].ano);
    }
    fprintf(out, "A pessoa mais velha é %s é com %i anos\n", info[maiorI].nome, info[maiorI].idade);
    fprintf(out, "A pessoa mais nova é %s é com %i anos", info[menorI].nome, info[menorI].idade);
    fclose(out);

    return 0;
}
/*
int calcIdade(int diaN, int mesN, int anoN, int opc)
{
    int da = 7, ma = 03, aa = 2023, qtdDia = 0, qtdMes = 0, qtdAno = 0;

    while (mesN < ma - 1 || anoN < aa)
    {

        if (qtdMes == 12)
        {
            mesN++;
            qtdMes++;
        }

        if (mesN == 12)
        {
            anoN++;
            mesN = 0;
        }
    }
    // ajustes para o último mes
    if (diaN == da)
    {
        qtdMes++;
        qtdDia = 0;
    }
    else if (diaN < da)
    {
        qtdMes++;
        qtdDia = da - diaN;
    }
    print("%i anos %i meses e %i dias.\n", qtdAno, qtdMes, qtdDia);
}
*/