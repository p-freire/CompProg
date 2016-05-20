#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define MAX 100100
#define BIGINT 999999
using namespace std;

int degrees[MAX];
int indexes[MAX];
long long int firstSum[MAX];
long long int secondSum[MAX];

int compare(const void *a, const void *b)
{
    return(*(int*)b - *(int*)a); // non-ascending order
}

void calculateFirstSum(int n)
{
    firstSum[1] = degrees[1];
    for(int i = 2; i <= n; ++i)
        firstSum[i] = firstSum[i - 1] + degrees[i];
}

void calculateSecondSum(int n)
{
    int k = 1;
    for(int i = 2; i <= n; ++i)
        secondSum[k] += degrees[i];
    for(int i = 3; i <= n; ++i)
    {
        ++k;
        secondSum[k] = secondSum[k - 1] - degrees[i - 1];
    }
}

void getIndexes(int n)
{
    int k = n;
    int i = 1;
    while(k >= 1)
    {
        if(i < n)
        {
            //cout << "Valor de degrees[" << i << "] = " << degrees[i] << endl;
            if(degrees[i] >= k)
            {
                indexes[k] = i;
                ++i;
               // cout << "indexes[" << k << "] = " << indexes[k] << endl;
            }
            else
            {
                indexes[k] = i - 1;
                --k;
                //cout << "Valor de K depois do else = " << k << endl;
            }
        }
        else
        {
            if(degrees[i] >= k)
                indexes[k] = i;
            else
                indexes[k] = i - 1;
            --k;
        }
        //cout << endl;
    }
}

bool erdos_gallai(int n)
{
    long long int sum1, sum2;
    long long int i, j, k, l;
    sum1 = 0;
    if(degrees[1] > n - 1)
        return false;
    calculateFirstSum(n);
    if(firstSum[n] % 2 != 0)
        return false;
    calculateSecondSum(n);
    getIndexes(n);
//    for(int i = 1; i <= n; ++i)
//        cout << indexes[i] << "  ";
//    cout << endl;
    for(k = 1; k <= n; ++k)
    {
        sum1 = firstSum[k];
        sum2 = k * (k - 1);
        if(indexes[k] > k)
            sum2 += k * (indexes[k] - k) + secondSum[indexes[k]];
        else
            sum2 += secondSum[k];
        if(sum1 > sum2)
            return false;
    }
    return true;
}

int main()
{
    int n; // number of friends
    while(scanf("%d", &n) != EOF)
    {
        memset(degrees, 0, sizeof(degrees));
        memset(indexes, 0, sizeof(indexes));
        memset(firstSum, 0, sizeof(firstSum));
        memset(secondSum, 0, sizeof(secondSum));
        degrees[0] = BIGINT;
        for(int i = 1; i <= n; ++i)
            scanf("%d", &degrees[i]);
        qsort(degrees, n + 1, sizeof(int), compare);
//        for(int i = 0; i <= n; ++i)
//            cout << degrees[i] << " ";
        erdos_gallai(n) ? printf("possivel") : printf("impossivel");
        printf("\n");
    }
    return 0;
}
