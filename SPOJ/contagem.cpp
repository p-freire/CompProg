#include <iostream>
#define max 61
 
using namespace std;
 
int main()
{
    char palavraOriginal[max];
    int ponteDeBs[max];
    int tam = 0;
    int j =0;
    int nroPalavra = 1;
    unsigned long long int soma = 0;
    unsigned long long int temp = 1;
 
    while(!feof(stdin))
    {
        scanf("%s", palavraOriginal);
 
        if(feof(stdin)) break;
 
        while(palavraOriginal[tam] != '\0')
        {
            if(palavraOriginal[tam] == 'b')
            {
                ponteDeBs[j] = tam;
                j++;
            }
            tam++;
        }
 
        if(j >= 1)
        {
            for(int k = 0; k < j; k++)
            {
                for(int c = 0; c < (tam - (ponteDeBs[k] + 1)); c++)
                {
                    temp *= 2;
                }
                soma = soma + temp;
                temp = 1;
            }
        }
        else
            soma = 0;
 
        printf("Palavra %d\n%llu\n\n", nroPalavra, soma);
        soma = 0;
        tam = 0;
        j = 0;
 
        nroPalavra++;
    }
    return 0;
}