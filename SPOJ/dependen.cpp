#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
 
#define tamMax 110
 
using namespace std;
int matAdj[tamMax][tamMax];
bool jaVisitou[tamMax];
int tamanho = 0;
 
void depthFirst(int v, int tam)
{
    jaVisitou[v] = true;
 
    for(int j = 1; j <= tam; j++)
    {
        if(matAdj[v][j] == 1 && !jaVisitou[j])
        {
                tamanho++;
		/*cout<<"Indo para o vertice "<<j<<" com soma do caminho = "<<tamanho<<endl;*/
                /*if(nivel > tamanho)
                {
                    tamanho = nivel;
                }*/
            depthFirst(j, tam);
        }
    }
}
 
int main()
{
    int n, t, varControle = 1;
    int aux;
    int tarefa = 1;
    memset(matAdj, 0, sizeof(matAdj));
    memset(jaVisitou, 0, sizeof(jaVisitou));
    scanf("%d", &n);
 
    while(n != 0)
    {
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &t);
            while(t--)
            {
                scanf("%d", &aux);
                matAdj[varControle][aux] = 1;
            }
            varControle++;
        }
 
        aux = 0;
        for(int i = 1; i <= n; i++)
        {
            depthFirst(i, n);
	    /*cout<<"Para o vertice "<<i<<" a quantidade de dependencias eh: "<<tamanho<<endl;*/
            if(tamanho > aux)
            {
                aux = tamanho;
                tarefa = i;
            }
            tamanho = 0;
            memset(jaVisitou, 0, sizeof(jaVisitou));
        }
 
        printf("%d\n", tarefa);
        varControle = 1;
        memset(matAdj, 0, sizeof(matAdj));
        memset(jaVisitou, 0, sizeof(jaVisitou));
        tamanho = 0;
        tarefa = 1;
        scanf("%d", &n);
    }
    return 0;
} 