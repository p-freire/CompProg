#include <iostream>
#include <algorithm>
#define tamMax 110
#define BIGINT 999999
#define maxConsultas 10000
using namespace std;
 
struct consulta
{
    int origem;
    int destino;
    int nroCidades;
    int resultado;
    int indiceOriginal;
};
 
int matAdj[tamMax][tamMax];
consulta consultas[maxConsultas];
 
int compare(const void *a, const void *b)
{
    struct consulta *ia = (struct consulta *) a;
    struct consulta *ib = (struct consulta *) b;
    return (ia->nroCidades - ib->nroCidades);
}
 
int comparePorIndices(const void *a, const void *b)
{
    struct consulta *ia = (struct consulta *) a;
    struct consulta *ib = (struct consulta *) b;
    return (ia->indiceOriginal - ib->indiceOriginal);
}
 
void Floyd_Warshall(int tamanho, int restricao)
{
    for(int k = 1; k <= restricao; k++)
        for(int i = 1; i <= tamanho; i++)
            for(int j = 1; j <= tamanho; j++)
                matAdj[i][j] = min(matAdj[i][j], matAdj[i][k] + matAdj[k][j]);
}
 
int main()
{
    int n, m, c, o, d, t, u, v, w;
    int aux;
    int instancia = 1;
 
    for(int i = 0; i < tamMax; i++)
        for(int j = 0; j < tamMax; j++)
        {
            if(i == j)
                matAdj[i][j] = 0;
            else
                matAdj[i][j] = BIGINT;
        }
 
    while(scanf("%d %d", &n, &m) != EOF)
    {
        while(m--)
        {
            scanf("%d %d %d", &u, &v, &w);
            if(matAdj[u][v] > w)
                matAdj[u][v] = w;
        }
 
        scanf("%d", &c);
        int i = 0;
        for(int j = 0; j < c; j++)
        {
            scanf("%d %d %d", &consultas[j].origem, &consultas[j].destino, &consultas[j].nroCidades);
            consultas[j].indiceOriginal = j;
        }
 
        qsort(consultas, c, sizeof(struct consulta), compare);
 
        int a = 0;
 
        for(int j = 0; j < c; j++)
        {
            if(consultas[j].nroCidades != a)
            {
                Floyd_Warshall(n, consultas[j].nroCidades);
                a = consultas[j].nroCidades;
            }
            consultas[j].resultado = matAdj[consultas[j].origem][consultas[j].destino];
        }
 
        qsort(consultas, c, sizeof(struct consulta), comparePorIndices);
        i = 0;
        printf("Instancia %d\n", instancia);
        instancia++;
        while(c--)
        {
            if(consultas[i].resultado == BIGINT)
                printf("-1\n");
            else
                printf("%d\n", consultas[i].resultado);
            i++;
        }
 
        printf("\n");
 
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
            {
                if(i == j)
                    matAdj[i][j] = 0;
                else
                    matAdj[i][j] = BIGINT;
            }
    }
    return 0;
}