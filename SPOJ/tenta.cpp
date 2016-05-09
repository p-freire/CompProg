#include <iostream>
#include <algorithm>
#define tamMax 8
using namespace std;
 
long long int vetor[tamMax];
 
int compare(const void *a, const void *b)
{
    return(*(int*)a - *(int*)b);
}
 
inline void print(int tamanho)
{
    printf("%lld", vetor[0]);
    for(int i = 1; i < tamanho; i++)
        printf(" %lld", vetor[i]);
    printf("\n");
}
 
inline void swap(int a, int b)
{
    long long int aux = vetor[a];
    vetor[a] = vetor[b];
    vetor[b] = aux;
}
 
inline void rotacionaEsquerda(int inicio, int tamanho)
{
    long long int tmp = vetor[inicio];
    for(int i = inicio; i < tamanho - 1; i++)
        vetor[i] = vetor[i + 1];
    vetor[tamanho - 1] = tmp;
}
 
void permuta(int inicio, int tamanho)
{
    print(tamanho);
    if(inicio < tamanho)
    {
        int i, j;
        for(i = tamanho - 2; i >= inicio; i--)
        {
            for(j = i + 1; j < tamanho; j++)
            {
                swap(i, j);
                permuta(i + 1, tamanho);
            }
            rotacionaEsquerda(i, tamanho);
        }
    }
}
 
 
int main()
{
    int n;
    scanf("%d", &n);
 
    while(n > 0)
    {
        for(int i = 0; i < n; i++)
            scanf("%lld", &vetor[i]);
 
        qsort(vetor, n, sizeof(long long int), compare);
 
        permuta(0, n);
        printf("\n");
        scanf("%d", &n);
    }
 
    return 0;
}