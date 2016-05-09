#include <iostream>
#define MAX 30
#define MAX_SOMA 1000
using namespace std;
 
int vetor[MAX];
bool matrizSoma[MAX_SOMA + 1][MAX + 1];
 
bool taOrdenado(int tam)
{
    int menor = vetor[0];
    int i = 1;
    while( i < tam )
    {
        if(menor >= vetor[i])
            return false;
        menor = vetor[i];
        i++;
    }
    return true;
}
 
void montaTabela()
{
    for(int i = 0; i <= MAX; i++)
        matrizSoma[0][i] = true;
 
    for(int i = 1; i <= MAX_SOMA; i++)
        matrizSoma[i][0] = false;
 
    for(int i = 1; i <= MAX_SOMA; i++)
    {
        for(int j = 1; j<= MAX; j++)
        {
            matrizSoma[i][j] = matrizSoma[i][j-1];
            if(i >= vetor[j-1])
            {
                matrizSoma[i][j] = matrizSoma[i][j] || matrizSoma[i - vetor[j-1]][j-1];
            }
        }
    }
}
 
bool temSoma(int numero, int indice)
{
    return matrizSoma[numero][indice];
}
 
int main()
{
    int d, i;
    int numeroCaso = 1;
 
    while(scanf("%d", &d) != EOF)
    {
        for(int i = 0; i < d; i++)
            scanf("%d", &vetor[i]);
 
        montaTabela();
        i = 1;
        bool achouSoma = false;
 
        printf("Case #%d: %d", numeroCaso, vetor[0]);
        for(int i = 1; i < d; i++)
            printf(" %d", vetor[i]);
        printf("\n");
 
        if(taOrdenado(d))
        {
            while(!achouSoma && i < d )
            {
                achouSoma = temSoma(vetor[i], i);
                i++;
            }
 
            if(!achouSoma)
                printf("This is an A-sequence.\n");
            else
                printf("This is not an A-sequence.\n");
        }
        else
            printf("This is not an A-sequence.\n");
 
        for(int i = 0; i <= MAX_SOMA; i++)
            for(int j = 0; j <= MAX; j++)
                matrizSoma[i][j] = false;
 
        for(int i = 0; i < MAX; i++)
            vetor[i] = 0;
 
        numeroCaso++;
    }
    return 0;
}