#include <iostream>
#include <queue>
#define tamMax 1010
#define BIGINT 9999999
using namespace std;
 
int matAdj[tamMax][tamMax];
int distancias[tamMax];
bool foiVisitado[tamMax];
 
void Prim(int vInicial, int tamanho)
{
    int i;
    priority_queue< pair<int, int> > filaVertices;
    pair<int, int> tmp;
 
    distancias[vInicial] = 0;
    filaVertices.push(pair<int, int> (distancias[vInicial], vInicial));
 
    while(!filaVertices.empty())
    {
        tmp = filaVertices.top();
        filaVertices.pop();
        i = tmp.second;
        foiVisitado[i] = true;
        for(int j = 1; j <= tamanho; j++)
            if(matAdj[i][j] > 0 && !foiVisitado[j] && distancias[j] > matAdj[i][j])
            {
                distancias[j] = matAdj[i][j];
                filaVertices.push(pair<int, int> (-distancias[j], j));
            }
    }
}
int main()
{
    for(int i = 0; i < tamMax; i++)
    {
        for(int j = 0; j < tamMax; j++)
            matAdj[i][j] = 0;
        distancias[i] = BIGINT;
        foiVisitado[i] = false;
    }
 
    int n, m, indice1, indice2, peso, distancia = 0, instancia = 1;
 
    while(scanf("%d %d", &n, &m) != EOF)
    {
        while(m > 0)
        {
            scanf("%d %d %d", &indice1, &indice2, &peso);
            if(matAdj[indice1][indice2] == 0 || matAdj[indice1][indice2] > peso)
            {
                matAdj[indice1][indice2] = peso;
                matAdj[indice2][indice1] = peso;
            }
            m--;
        }
 
        for(int i = 1; i <= n; i++)
        {
            if(!foiVisitado[i])
                Prim(i, n+1);
        }
 
        for(int i = 1; i <= n; i++)
        {
            if(distancias[i] != BIGINT)
                distancia += distancias[i];
        }
 
        printf("Instancia %d\n%d\n\n", instancia, distancia);
        distancia = 0;
        instancia++;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
                matAdj[i][j] = 0;
            distancias[i] = BIGINT;
            foiVisitado[i] = false;
        }
 
    }
 
    return 0;
}