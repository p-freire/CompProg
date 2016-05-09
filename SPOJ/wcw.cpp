#include <iostream>
#define tamMax 10010
int vetor[tamMax];
int qtdePermutacoes = 0;
 
using namespace std;
 
bool estaOrdenado(int tam)
{
    for(int i = 1; i <= tam; i++)
    {
        if(vetor[i] != i)
            return false;
    }
    return true;
}
 
void contaPermutacoes(int tam)
{
    int aux, indice;
    while(!estaOrdenado(tam))
    {
        for(int i = 1; i <= tam; i++)
        {
            if(vetor[i] != i)
            {
                aux = vetor[i];
                vetor[i] = vetor[aux];
                vetor[aux] = aux;
                qtdePermutacoes++;
            }
        }
    }
}
 
int main()
{
    int t, n;
    scanf("%d", &t);
 
    while(t > 0)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &vetor[i]);
 
        contaPermutacoes(n);
        printf("%d\n", qtdePermutacoes);
        qtdePermutacoes = 0;
        t--;
    }
    return 0;
}