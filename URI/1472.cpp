#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define MAX 100100

using namespace std;

int vPoints[MAX];

int binSearch(int begin, int end, int key)
{
    while(end >= begin)
    {
        int middle = begin + ((end - begin)/2);
        if(vPoints[middle] < key)
            begin = middle + 1;
        else if(vPoints[middle] > key)
            end = middle - 1;
        else
            return middle;
    }
    return -1;
}

int main()
{
    int n, numTriangles; // number of given points, number of triangles found

    while(scanf("%d", &n) != EOF)
    {
        memset(vPoints, 0, sizeof(vPoints));
        numTriangles = 0;
        scanf("%d", &vPoints[0]);

        for(int i = 1; i < n; i++)
        {
            scanf("%d", &vPoints[i]);
            vPoints[i] += vPoints[i-1];
        }

        for(int i = 0; i < n; i++)
            if(binSearch(0, n-1, vPoints[i] + (vPoints[n-1]/3)) != -1 && binSearch(0, n-1, vPoints[i] + 2*(vPoints[n-1]/3)) != -1)
                numTriangles++;
        printf("%d\n", numTriangles);
    }

    return 0;
}