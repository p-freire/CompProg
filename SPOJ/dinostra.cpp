#include <iostream>
#define tamMax 1050
#define valorMaximo 1048576
using namespace std;
 
struct fatorPrimo
{
    int numero;
    int qtdeVezesQueRepetiu;
};
 
fatorPrimo fp[tamMax];
 
bool buscaBin(int chave, int tamanho, int *v)
{
    int limInf = 0;
    int limSup = tamanho - 1;
    int meio;
 
    while(limInf <= limSup)
    {
        meio = limInf + (limSup - limInf)/2;
 
        if(v[meio] == chave)
            return true;
        else if(v[meio] < chave)
            limInf = meio + 1;
        else
            limSup = meio - 1;
    }
    return false;
}
 
int main()
{
    int *vetor = new int[valorMaximo];
    int *vetorPrimos;
    int n;
    int aux = 0;
    int contadorPrimos = 0;
    int contador = 0;
    bool isDin = false;
    int instancia = 1;
 
    for(int i = 0; i < valorMaximo; i++)
        vetor[i] = i + 2;
 
    for(int i = 0; i < valorMaximo; i++)
    {
        if(vetor[i] != 0)
        {
            contador++;
            int aux = vetor[i];
            for(int j = aux + i; j < valorMaximo; j += aux)
                vetor[j] = 0;
 
        }
    }
 
    vetorPrimos = new int[contador];
 
    for(int i = 0; i < valorMaximo; i++)
    {
        if(vetor[i] != 0)
        {
            vetorPrimos[contadorPrimos] = vetor[i];
            contadorPrimos++;
        }
    }
 
    while(scanf("%d", &n) != EOF)
    {
        if(n >= 36 && vetor[n - 2] == 0)//!buscaBin(n, contador, vetorPrimos))
        {
            int i = 0;
            while(n > 1)
            {
                if(n % vetorPrimos[i] == 0)
                {
                    fp[aux].numero = vetorPrimos[i];
                    fp[aux].qtdeVezesQueRepetiu = 1;
                    n = n / vetorPrimos[i];
                    while(n % vetorPrimos[i] == 0)
                    {
                        fp[aux].qtdeVezesQueRepetiu++;
                        n = n / vetorPrimos[i];
                    }
                    aux++;
                }
                i++;
            }
 
            if(aux == 1 && fp[0].qtdeVezesQueRepetiu >= 8){
                isDin = true;
            }
            else if(aux == 2 && fp[0].qtdeVezesQueRepetiu >= 2 && fp[1].qtdeVezesQueRepetiu >= 2)
            {
                isDin = true;
            }
            else if(aux == 2 && fp[0].qtdeVezesQueRepetiu == 1 && fp[1].qtdeVezesQueRepetiu >= 5)
            {
                isDin = true;
            }
            else if(aux == 2 && fp[1].qtdeVezesQueRepetiu == 1 && fp[0].qtdeVezesQueRepetiu >= 5)
            {
                isDin = true;
            }
            else if(aux == 3 && (fp[0].qtdeVezesQueRepetiu >= 2 || fp[1].qtdeVezesQueRepetiu >= 2 || fp[2].qtdeVezesQueRepetiu >= 2)){
                isDin = true;
            }
            else if(aux >= 4){
                isDin = true;
            }
        }
        if(isDin)
            printf("Instancia %d\nsim\n\n", instancia);
        else
            printf("Instancia %d\nnao\n\n", instancia);
 
        isDin = false;
        aux = 0;
        instancia++;
    }
 
    delete [] vetor;
    delete [] vetorPrimos;
    return 0;
}