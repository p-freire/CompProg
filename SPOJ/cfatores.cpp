#include <iostream>
#define max 1000000
using namespace std;
 
int main()
{
    int *vetor = new int[max];
    int *vetorPrimos;
    int contador = 0;
    int qtdePrimos = 0;
    int numero;
    int aux = 0;
 
    for(int i = 0; i < max; i++)
        vetor[i] = i+2;
 
    //Crivo de EratÃ³stenes
    for(int i = 0; i < max; i++)
    {
        if(vetor[i] != 0)
        {
            contador++;
            int aux = vetor[i];
            for (int j = i + aux; j < max; j += aux)
                vetor[j] = 0;
        }
    }
 
    vetorPrimos = new int[contador];
    for(int i = 0; i < max; i++)
        if(vetor[i] != 0)
        {
            vetorPrimos[aux] = vetor[i];
            aux++;
        }
 
    scanf("%d", &numero);
    while(numero != 0)
    {
        for(int i = 0; i < contador; i++)
            if(numero % vetorPrimos[i] == 0)
                qtdePrimos++;
        printf("%d : %d\n", numero, qtdePrimos);
        qtdePrimos = 0;
        scanf("%d", &numero);
    }
 
    delete []vetor;
    delete []vetorPrimos;
 
    return 0;
}