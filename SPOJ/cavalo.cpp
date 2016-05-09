#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
#define MAX_HORSES 210
#define MAX_AFFINITY 1010
#define BIGINT 999999
#define MAX(a,b) ((a) > (b) ? (a) : (b))
 
int matched[MAX_AFFINITY];
int was_visited[MAX_HORSES];
int horse_capacity[MAX_HORSES];
int capacity[MAX_HORSES][MAX_HORSES], flow[MAX_HORSES][MAX_HORSES];
int nvertices;
using namespace std;
 
int DFS(int v, int destino, int menor)
{
    int i, auxiliar;
 
    if(v == destino)
        return menor;
    for(i = 0; i < nvertices; ++i)
    {
        if(capacity[v][i] && !was_visited[i])
        {
            was_visited[i] = true;
            if((auxiliar = DFS(i, destino, menor > capacity[v][i] ? capacity[v][i] : menor)))
            {
                menor = auxiliar;
                capacity[v][i] -= menor;
                capacity[i][v] += menor;
                return menor;
            }
            was_visited[i] = false;
        }
    }
    return 0;
}
 
int max_flow(int origem, int destino)
{
    int i, f, auxiliar;
 
    f = 0;
    do
    {
        for(i = 0; i < nvertices; ++i)
            was_visited[i] = false;
        auxiliar = 0;
        //was_visited[0] = true;
        was_visited[origem] = true;
        auxiliar = DFS(origem, destino, BIGINT);
        f += auxiliar;
    }while(auxiliar);
    return f;
}
 
 
int main()
{
        int num_horses, num_soldiers, num_affinities, num_vertices;
        int k = 1; // instance
        int u, v, s, t; // u and v are aux nodes; s and t are the entry and exit nodes, respectively
        while(scanf("%d %d %d", &num_horses, &num_soldiers, &num_affinities) != EOF)
        {
                s = num_soldiers + num_horses; t = s + 1;
                nvertices = num_soldiers + num_horses + 2;
                memset(capacity, 0, sizeof(capacity));
                memset(horse_capacity, 0, sizeof(horse_capacity));
 
                /* Get the capacities */
                for(int i = 0; i < num_horses; ++i)
                        scanf("%d", &horse_capacity[i]);
 
                /* Link horses and soldiers */
                for(int i = 0; i < num_affinities; ++i)
                {
                        scanf("%d %d", &u, &v);
                        capacity[v - 1][num_soldiers - 1 + u] = 1;
                }
 
                /* Soldiers */
                for(int i = 0; i < num_soldiers; ++i)
                {
                    capacity[s][i] = 1;
                }
 
                /* Horses */
                for(int i = num_soldiers; i < num_soldiers + num_horses; ++i)
                {
                    capacity[i][t] = horse_capacity[i - num_soldiers];
                }
 
                /* Find max matching */
//                for(int i = 0; i < num_horses + num_soldiers + 2; ++i)
//                {
//                    for(int j = 0; j < num_horses + num_soldiers + 2; ++j)
//                        printf("%d ", capacity[i][j]);
//                    printf("\n");
//                }
                printf("Instancia %d\n%d\n", k, max_flow(s, t));
                ++k;
        }
        return 0;
}