#include <stdio.h>
#include <stdlib.h>
#define MAX 110
 
int numOfTriangles[MAX];
 
void calculate()
{
    numOfTriangles[1] = 1;
    numOfTriangles[2] = 5;
    for(int i = 3; i < MAX; ++i)
        numOfTriangles[i] = numOfTriangles[i-1] + i*i;
}
 
int main()
{
    int n;
    calculate();
    while(scanf("%d", &n) && n != 0)
    {
        printf("%d\n", numOfTriangles[n]);
    }
    return 0;
}