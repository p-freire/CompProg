#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX(A,B) ((A) > (B) ? (A) : (B))
using namespace std;

int main()
{
    int a, b, c, greater_num;
    scanf("%d %d %d", &a, &b, &c);
    greater_num = MAX(a,b);
    greater_num = MAX(greater_num, c);
    printf("%d eh o maior\n", greater_num);
    return 0;
}
