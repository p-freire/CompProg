#include <iostream>
#include <algorithm>
#define max 2000
using namespace std;
 
int vetor[max];
char palavra[21];
 
int palavraEmNumero(char word[])
{
    int i = 0;
    int numero = 0;
    while(word[i] != '\0')
    {
        if((int)word[i] >= 97)
            numero += (int)word[i] - 96;
        else
            numero += (int)word[i] - 38;
        i++;
    }
    return numero;
}
 
bool buscaBin(int vetor[], int valor, int minInd, int maxInd) //Faz a busca binÃ¡ria do nÃºmero encontrado no vetor de primos
{
    if (maxInd < minInd)
        return false;
    else
    {
        int meio = minInd +(maxInd - minInd) / 2;
        if(vetor[meio] > valor)
            return buscaBin(vetor, valor, minInd, meio-1);
        else if(vetor[meio] < valor)
            return buscaBin(vetor, valor, meio+1, maxInd);
        else
            return true;
    }
}
 
int main()
{
    int i, j, aux, contador;
    int *vetorPrimos;
    contador = 0;
 
    for(i = 0; i < max; i++)
        vetor[i] = i+1;
 
    //Crivo de EratÃ³stenes
    for(i = 1; i < max; i++)
    {
        if(vetor[i] != 0)
        {
            aux = vetor[i];
            contador++;
            for(j = i + aux; j < max; j+=aux)
            {
                vetor[j] = 0;
            }
        }
    }
 
    vetorPrimos = new int[contador];
    j = 0;
    for(i = 0; i < max; i++)
    {
        if(vetor[i] != 0)
        {
            vetorPrimos[j] = vetor[i];
            j++;
        }
    }
 
    while(scanf("%s", palavra) != EOF)
    {
        if(buscaBin(vetorPrimos, palavraEmNumero(palavra), 0, contador-1))
            printf("It is a prime word.\n");
        else
            printf("It is not a prime word.\n");
    }
 
    delete []vetorPrimos;
    return 0;
}