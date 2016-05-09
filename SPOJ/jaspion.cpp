#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define tamMax 81
 
using namespace std;
 
 
struct dicionario
{
    char palavra[tamMax];
    char traducao[tamMax];
};
 
struct musica
{
    char lyrics[tamMax];
};
 
dicionario d[1000010];
musica mus[1010];
 
int compare(const void *a, const void *b)
{
    struct dicionario *ia = (struct dicionario *)a;
    struct dicionario *ib = (struct dicionario *)b;
    return strcmp(ia->palavra, ib->palavra);
}
 
int pesqBin(dicionario *d, char *chave, int m)
{
    int limInf = 0;
    int limSup = m - 1;
    int meio;
    while(limInf <= limSup)
    {
        meio = limInf + (limSup - limInf)/2;
        if(strcmp(chave,d[meio].palavra) == 0)
            return meio;
        else if(strcmp(chave, d[meio].palavra) < 0)
            limSup = meio - 1;
        else
            limInf = meio + 1;
    }
    return -1; //nao achou
}
 
int main()
{
    char linhaMusica[tamMax];
    int aux;
    int t, n, m, i;
    scanf("%d", &t);
    while(t > 0)
    {
        scanf("%d %d", &m, &n);
        for(i = 0; i < m; i++)
            scanf("%s %[^\n]", d[i].palavra, d[i].traducao);
 
        qsort(d, m, sizeof(struct dicionario), compare);
 
        for(i = 0; i < n; i++)
        {
            getchar();
            memset(mus[i].lyrics, '\0', sizeof(mus[i].lyrics));
            scanf("%[^\n]", mus[i].lyrics);
        }
 
        char *pch; //pointer char
        for(int i = 0; i < n; i++)
        {
            pch = NULL;
            pch = strtok(mus[i].lyrics, " ,.-");
 
            if(pch != NULL)
            {
                aux = pesqBin(d, pch, m);
                if(aux != -1)
                    printf("%s", d[aux].traducao);
                else
                    printf("%s", pch);
            }
            else
                printf("\n");
 
            pch = strtok(NULL, " ,.-");
 
            while(pch != NULL)
            {
                aux = pesqBin(d, pch, m);
                if(aux != -1)
                    printf(" %s", d[aux].traducao);
                else
                    printf(" %s", pch);
                pch = strtok(NULL, " ,.-");
            }
            printf("\n");
        }
        t--;
    }
    return 0;
}