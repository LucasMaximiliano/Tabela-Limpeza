#include "util.h"

int anoBissexto(const int ano)
{
    if(ano != 0)
    {
        if(ano%4 == 0)
        {
            if(ano%100 == 0)
            {
                if(ano%400 == 0)
                    return 1;
                else
                    return 0;
            }
            return 1;
        }
    }
    return 0;
}

int diasDecorridos(const int ano, const int mes, const int dia)
{
    int diasDecorridos = 0;
    int dnm[] = {31,28,31,30,31,30,31,31,30,31,30,31};  // *D*ias *n*o *m*es
    
    for(int i = 1; i < ano; i++)
    {
        if(anoBissexto(i))
            diasDecorridos += 366;
        else
            diasDecorridos += 365;
    }
        
    for(int i = 0; i < mes - 1; i++)
    {
        if(anoBissexto(ano))
        {
            if(i == 1)
                diasDecorridos += 29;   // Lidar com fevereiro separadamente
        }
        diasDecorridos += dnm[i];
    }
        
    diasDecorridos += dia;

    return diasDecorridos;
}

int inputData(int& ano, int& mes, int& dia, int& n_semanas)
{
    printf("INSIRA A DATA ATUAL\nAno: ");
    scanf("%i", &ano);
    if(ano < 0)
    {
        printf("Entrada incorreta.\n");
        return 1;
    }
    printf("Mes: ");
    scanf("%i", &mes);
    if(mes < 1 || mes > 12)
    {
        printf("Entrada incorreta.\n");
        return 1;
    }
    printf("Dia: ");
    scanf("%i", &dia);
    if(dia < 1 || dia > 31)
    {
        printf("Entrada incorreta.\n");
        return 1;
    }
    if(anoBissexto(ano))
    {
        if(mes == 2)
            if(dia > 29)
            {
                printf("Entrada incorreta.\n");
                return 1;
            }
    }
    if(!anoBissexto(ano))
    {
        if(mes == 2)
            if(dia > 28)
            {
                printf("Entrada incorreta.\n");
                return 1;
            }
    }
    printf("\nINSIRA NUMERO DE SEMANAS: ");
    scanf("%i", &n_semanas);
    if(n_semanas < 0)
    {
        printf("Entrada incorreta.\n");
        return 1;
    }
    return 0;
}
