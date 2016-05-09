#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
 
int **alocaMatriz(int n)
{
//    int **matriz;
//    int i;
//
//    if(n < 1)
//        return(NULL);
//
//    matriz = (int**) calloc(n, sizeof(int*));
//    if(!matriz)
//        return(NULL);
//
//    for(i = 0; i < n; i++)
//    {
//        matriz[i] = (int*) calloc(n, sizeof(int));
//        if(!matriz[i])
//            return(NULL);
//    }
//
//    return(matriz);
    int **matriz;
    int i;
 
    if (n < 1)
        return(NULL);
 
    matriz = new int*[n];
 
    for(i = 0; i < n; ++i)
    {
        matriz[i] = new int[n];
    }
 
    return(matriz);
}
 
void liberaMatriz(int** matriz, int n)
{
    if(!matriz)
        return;
    for(int i = 0; i < n; i++)
    {
        delete((int*)matriz[i]);
    }
    delete []matriz;
//    for(int i = 0; i < n; i++)
//        free(matriz[i]);
//    free (matriz);
}
 
int somaColunas(int **matriz, int n)
{
    int somaTemp = 0;
    int temp = 0;
 
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            temp += matriz[j][i];
        }
        if(temp > somaTemp)
            somaTemp = temp;
        temp = 0;
    }
 
    return somaTemp;
}
 
int main()
{
    int n;
    scanf("%d", &n);
    while(n != 0)
    {
        int **mat = alocaMatriz(n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &mat[i][j]);
        int resultado = somaColunas(mat, n);
        printf("%d\n", resultado);
        liberaMatriz(mat, n);
        scanf("%d", &n);
    }
 
    return 0;
}
 