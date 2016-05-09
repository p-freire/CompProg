#include <iostream>
#include <queue>
#include <string.h>
#define MAX 110
 
using namespace std;
 
int matAdj[ MAX ][ MAX ];
int distCidadeOrigem[ MAX ];
int distCidadeDestino[ MAX ];
int qtdeCidades, qtdeArestas;
int cidadeInicial, cidadeFinal, qtdeDeDias;
bool encontrouCaminho = false;
 
void breadthFirst( int verticeInicial, int qtdeCidades, int *vetorDistancias )
{
    int verticeAux;
    queue<int> filaBusca;
    filaBusca.push( verticeInicial );
    {
        vetorDistancias[ verticeInicial ] = 0;
        while( !filaBusca.empty() )
        {
            verticeAux = filaBusca.front();
            filaBusca.pop();
            for( int i = 1; i <= qtdeCidades; i++ )
            {
                if( matAdj[ verticeAux ][ i ] != 0 && vetorDistancias[ i ] == 0 && i != verticeInicial )
                {
                    vetorDistancias[ i ] = vetorDistancias[ verticeAux ] + 1;
                    filaBusca.push( i );
                }
            }
        }
    }
}
 
int main()
{
    scanf( "%d", &qtdeCidades );
    scanf( "%d", &qtdeArestas );
    memset( matAdj, 0, sizeof( matAdj ) );
    memset( distCidadeOrigem, 0, sizeof( distCidadeOrigem ) );
    memset( distCidadeDestino, 0, sizeof( distCidadeDestino ) );
 
    int a, b; // Cidade A, Cidade B
    int i, j, soma;
 
    for( i = 0; i < MAX; i++ )
    {
        distCidadeOrigem[ i ] = distCidadeDestino[ i ] = 0;
    }
 
    while( qtdeCidades != 0 )
    {
        for( i = 0; i < qtdeArestas; i++ )
        {
            scanf( "%d %d", &a, &b );
            matAdj[ a ][ b ] = 1;
            matAdj[ b ][ a ] = 1;
        }
        scanf( "%d %d %d", &cidadeInicial, &cidadeFinal, &qtdeDeDias );
 
        breadthFirst( cidadeInicial, qtdeCidades, distCidadeOrigem );
        breadthFirst( cidadeFinal, qtdeCidades, distCidadeDestino );
 
        if( qtdeDeDias == 0 )
        {
            if( cidadeFinal != cidadeInicial )
            {
                encontrouCaminho = false;
                qtdeCidades = 0;
            }
            else
                encontrouCaminho = true;
        }
        else if( qtdeArestas  == 0 )
        {
            if( qtdeDeDias == 0 && cidadeFinal != cidadeInicial )
            {
                encontrouCaminho = false;
                qtdeCidades = 0;
            }
            else if( qtdeDeDias == 0 && cidadeFinal == cidadeInicial )
                encontrouCaminho = true;
            else
            {
                encontrouCaminho = false;
                qtdeCidades = 0;
            }
        }
        else if( distCidadeOrigem[ cidadeFinal ] == 0 ) // Grafos disjuntos
        {
            encontrouCaminho= false;
            qtdeCidades = 0;
        }
        else
        {
            if( (distCidadeOrigem[ cidadeFinal ] <= qtdeDeDias && distCidadeOrigem[ cidadeFinal ] % 2 == 0 && qtdeDeDias % 2 == 0)
                    ||(distCidadeOrigem[ cidadeFinal ] <= qtdeDeDias && distCidadeOrigem[ cidadeFinal ] % 2 == 1 && qtdeDeDias % 2 == 1) )
                encontrouCaminho = true;
            else
            {
                i = 1;
                while( !encontrouCaminho && i <= qtdeCidades )
                {
                    if( distCidadeDestino[ i ] != 0 && distCidadeOrigem[ i ] != 0 )
                    {
                        soma = distCidadeDestino[ i ] + distCidadeOrigem[ i ];
                        if( soma == qtdeDeDias )
                            encontrouCaminho = true;
                        else if( soma < qtdeDeDias )
                        {
                            if( (soma % 2 == 0 && qtdeDeDias % 2 == 0) || (soma % 2 == 1 && qtdeDeDias % 2 == 1) )
                                encontrouCaminho = true;
                        }
                    }
                    i++;
                }
            }
        }
 
        if( encontrouCaminho )
            printf( "Yes, Teobaldo can travel.\n" );
        else
            printf( "No, Teobaldo can not travel.\n" );
 
        encontrouCaminho = false;
 
        for( i = 0; i < MAX; i++ )
        {
            distCidadeDestino[ i ] = distCidadeOrigem[ i ] = 0;
            for( j = 0; j < MAX; j++ )
            {
                matAdj[ i ][ j ] = 0;
            }
        }
 
        scanf( "%d", &qtdeCidades );
        scanf( "%d", &qtdeArestas );
 
    }
    return 0;
}