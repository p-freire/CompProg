#include <iostream>
#include <stdlib.h>
#define max 1110
#define tam 50010
#define BIGINT 99999
 
using namespace std;
int moedas[max];
int calculo[tam];
 
void percorre(int &qtdeMoedas, int &preco)
{
    for(int i = moedas[0]; i <= preco; i++)
    {
        for(int j = 0; j < qtdeMoedas; j++)
        {
            if(i - moedas[j] == 0)
            {
                calculo[i] = 1;
            }
            else if(i - moedas[j] > 0)
            {
                if(calculo[i] > calculo[i - moedas[j]] + 1)
                    calculo[i] = calculo[i - moedas[j]] + 1;
            }
 
        }
    }
}
 
 
int main()
{
    for(int i = 0; i < tam; i++)
        calculo[i] = BIGINT;
 
    for(int i = 0; i < max; i++)
        moedas[i] = 0;
 
    int n, m, contador;
 
    scanf("%d", &m);
 
    while(m != 0)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &moedas[i]);
 
        percorre(n, m);
 
//        for(int i = moedas[0]; i <= m; i++)
//            if(calculo[i] != BIGINT)
//                printf("i = %d      Calculo[i] = %d\n", i, calculo[i]);
 
        contador = calculo[m];
 
        if(contador == BIGINT)
            printf("Impossivel\n");
        else
            printf("%d\n", contador);
 
        for(int i = 0; i <= m ; i++)
            calculo[i] = BIGINT;
 
        for(int i = 0; i < n; i++)
            moedas[i] = 0;
 
        scanf("%d", &m);
    }
    return 0;
}
 