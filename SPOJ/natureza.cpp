#include <iostream>
#include <string.h>
#include <algorithm>
#include <list>
#define tamMax 5010
#define tamChar 35
 
using namespace std;
 
struct relacoes
{
    char animal_1[tamChar];
    char animal_2[tamChar];
};
 
struct nomes
{
    char nome[tamChar];
};
//=====================================================================
//=====================================================================
relacoes r[tamMax];
nomes nAnimais[tamMax]; //guarda os nomes dos animais
bool jaVisitou[tamMax];
list<int> listaAdj[tamMax]; //guarda as relacoes entre os animais
int tamanhoMaximo; //maior caminho encontrado
int contador;
//=====================================================================
//=====================================================================
 
int compareNomes(const void *a, const void *b)
{
    struct nomes *ia = (struct nomes *)a;
    struct nomes *ib = (struct nomes *)b;
    return strcmp(ia->nome, ib->nome);
}
 
int pesqBinNomes(char *chave, nomes *n, int tamanho)
{
    int limSup = tamanho - 1;
    int limInf = 0;
    int meio;
    while(limInf <= limSup)
    {
        meio = limInf + (limSup - limInf)/2;
        if(strcmp(chave, n[meio].nome) == 0)
            return meio;
        else if(strcmp(chave, n[meio].nome) > 0)
            limInf = meio + 1;
        else
            limSup = meio - 1;
    }
    return -1; //nao encontrou
}
 
void depthFirst(int v, int &tam)
{
    jaVisitou[v] = true;
    list<int>::iterator it;
    int aux;
    for(it = listaAdj[v].begin(); it != listaAdj[v].end(); it++)
    {
        if(!jaVisitou[*it])
        {
            aux = *it;
            contador++;
            if(contador > tamanhoMaximo)
                tamanhoMaximo = contador;
            depthFirst(aux, tam); //chama o vertice que acabou de visitar
        }
    }
}
 
int main()
{
    memset(jaVisitou, false, sizeof(jaVisitou));
    tamanhoMaximo = 0;
    int c, rel;
    scanf("%d", &c);
    scanf("%d", &rel);
 
    while(c > 0)
    {
        for(int i = 0; i < c; i++)
        {
            scanf("%s", nAnimais[i].nome);
        }
 
        qsort(nAnimais, c, sizeof(struct nomes), compareNomes);
 
        if(rel > 0) //ou seja, existem relacoes de presa entre as criaturas
        {
            int ind1, ind2;
            for(int i = 0; i < rel; i++)
            {
                scanf("%s %s", r[i].animal_1, r[i].animal_2);
                ind1 = pesqBinNomes(r[i].animal_1, nAnimais, c); //pega posicao do primeiro animal no vetor nAnimais
                ind2 = pesqBinNomes(r[i].animal_2, nAnimais, c); //pega posicao do segundo animal no vetor nAnimais
                listaAdj[ind1].push_back(ind2); //marca na lista de adjacencia que os dois animais estao relacionados
                listaAdj[ind2].push_back(ind1);
            }
 
            int vertice;
 
            for(int i = 0; i < rel; i++)
            {
                contador = 1;
                vertice = pesqBinNomes(r[i].animal_1, nAnimais, c);
                depthFirst(vertice, c);
                for(int j = 0; j < c; j++)
                    jaVisitou[j] = false;
            }
            printf("%d\n", tamanhoMaximo);
        }
        else
        {
            printf("1\n");
        }
        tamanhoMaximo = 0;
        memset(jaVisitou, false, sizeof(jaVisitou));
        for(int i = 0; i < c; i++)
        {
            while(!listaAdj[i].empty())
                listaAdj[i].pop_back();
        }
        scanf("%d", &c);
        scanf("%d", &rel);
    }
 
    return 0;
}