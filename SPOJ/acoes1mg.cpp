#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
 
int contaQtdeEmpresas(float valor, int k)
{
    if(valor > k)
    {
        return contaQtdeEmpresas(floor(valor/2), k) + contaQtdeEmpresas(ceil(valor/2), k);
    }
    else
    {
        return 1;
    }
}
 
 
int main()
{
    int k;
    float n;
 
    scanf("%f", &n);
 
    while( n != 0)
    {
        scanf("%d", &k);
        printf("%d\n", contaQtdeEmpresas(n, k));
        scanf("%f", &n);
    }
    return 0;
}