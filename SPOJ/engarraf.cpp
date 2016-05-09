#include <iostream>
#include <queue>
#include <string.h> //memset
#define tam 110
#define distMax 999999
 
int matAdj[tam][tam];
int distancias[tam];
bool foiVisitado[tam];
 
using namespace std;
 
void Djikstra(int vInicial, int tamanho)
{
    int i;
 
    priority_queue< pair<int,int> > filaVertices;
    pair<int, int> tmp;
 
    distancias[vInicial] = 0;
    filaVertices.push(pair<int,int> (distancias[vInicial], vInicial));
 
    while(!filaVertices.empty())
    {
        tmp = filaVertices.top();
        filaVertices.pop();
        i = tmp.second;
        if(!foiVisitado[i])
        {
            foiVisitado[i] = true;
            for(int j = 1; j < tamanho; j++)
            {
                if(!foiVisitado[j] && matAdj[i][j] > 0 && distancias[j] > distancias[i] + matAdj[i][j])
                {
                    distancias[j] = distancias[i] + matAdj[i][j];
                    filaVertices.push(pair<int, int> (-distancias[j], j)); //distancias[j] fica negativa porque a ordenaÃ§Ã£o se dÃ¡ do maior valor pro menor. Colocando o sinal negativo, a ordem fica invertida, de acordo com o funcionamento do algoritmo
                }
            }
        }
    }
}
 
int main()
{
    for(int i = 0; i < tam; i++)
    {
        distancias[i] = distMax;
        foiVisitado[i] = false;
    }
 
    memset(matAdj, -1, sizeof(matAdj));
 
    int n, m, i, j, t, s, d; //ver no pdf o que cada variÃ¡vel significa
    scanf("%d %d", &n, &m);
 
    while(n != 0)
    {
        while(m > 0)
        {
            scanf("%d %d %d", &i, &j, &t);
            matAdj[i][j] = t;
            m--;
        }
 
        scanf("%d %d", &s, &d);
        Djikstra(s, n+1);
 
        if(distancias[d] != distMax)
            printf("%d\n", distancias[d]);
        else
            printf("-1\n");
 
        for(int i = 0; i < tam; i++)
        {
            distancias[i] = distMax;
            foiVisitado[i] = false;
        }
 
        memset(matAdj, -1, sizeof(matAdj));
        scanf("%d %d", &n, &m);
    }
 
 
    return 0;
}