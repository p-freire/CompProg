#include <iostream>
#include <string.h>
#define tamMaxChar 40
#define tamMaxNumeros 15
using namespace std;
 
long long int vetorMaiorValor[tamMaxNumeros];
long long int vetorMenorValor[tamMaxNumeros];
char localizacaoSinais[tamMaxNumeros];
char expressao[tamMaxChar];
 
void extraiNumeros()
{
    int i = 0, indice = 0;
    while(i < strlen(expressao))
    {
        if((int)expressao[i] > 48) 
        {
            if(i + 1 < strlen(expressao) && (int)expressao[i + 1] >= 48) 
            {
                vetorMaiorValor[indice] = 10*((int)expressao[i] - 48) + ((int)expressao[i + 1] - 48);
                vetorMenorValor[indice] = 10*((int)expressao[i] - 48) + ((int)expressao[i + 1] - 48);
                indice++;
                i += 2;
            }
            else 
            {
                vetorMaiorValor[indice] = (int)expressao[i] - 48;
                vetorMenorValor[indice] = (int)expressao[i] - 48;
                indice++;
                i++;
            }
        }
        else
            i++;
    }
}
 
void extraiSinais()
{
    int i = 0, indice = 0;
 
    while(i < strlen(expressao))
    {
        if(expressao[i] == '+')
        {
            localizacaoSinais[indice] = '+';
            indice++;
        }
        else if(expressao[i] == '*')
        {
            localizacaoSinais[indice] = '*';
            indice++;
        }
        i++;
    }
}
 
long long int maiorValor(int tamanho)
{
    long long int valor = 1;
 
    for(int i = 0; localizacaoSinais[i] != '\0'; i++)
    {
        if(localizacaoSinais[i] == '+')
        {
            vetorMaiorValor[i + 1] += vetorMaiorValor[i];
            vetorMaiorValor[i] = 0;
        }
    }
 
    for(int i = 0; i < tamanho; i++)
    {
        if(vetorMaiorValor[i] != 0)
            valor *= vetorMaiorValor[i];
    }
 
    return valor;
}
 
long long int menorValor(int tamanho)
{
    long long int valor = 0;
 
    for(int i = 0; localizacaoSinais[i] != '\0'; i++)
    {
        if(localizacaoSinais[i] == '*')
        {
            vetorMenorValor[i + 1] *= vetorMenorValor[i];
            vetorMenorValor[i] = 0;
        }
    }
 
    for(int i = 0; i < tamanho; i++)
    {
        if(vetorMenorValor[i] != 0)
            valor += vetorMenorValor[i];
    }
 
    return valor;
}
 
int main()
{
    memset(vetorMaiorValor, 0, sizeof(vetorMaiorValor));
    memset(vetorMaiorValor, 0, sizeof(vetorMenorValor));
    memset(localizacaoSinais, '\0', sizeof(localizacaoSinais));
    int n;
    scanf("%d", &n);
 
    while(n--)
    {
        scanf("%s", expressao);
        extraiNumeros();
        extraiSinais();
 
        int i;
        for(i = 0; vetorMaiorValor[i] != 0; i++);
        printf("The maximum and minimum are %lld and %lld.\n", maiorValor(i), menorValor(i));
 
        memset(vetorMaiorValor, 0, sizeof(vetorMaiorValor));
        memset(vetorMaiorValor, 0, sizeof(vetorMenorValor));
        memset(localizacaoSinais, '\0', sizeof(localizacaoSinais));
    }
    return 0;
}