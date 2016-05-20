#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX 100
using namespace std;

int main()
{
    double num;
    for(int i = 0; i < MAX; ++i)
    {
        scanf("%lf", &num);
        if(num <= 10)
            cout << "A[" << i << "] = " << num << endl;
    }
    return 0;
}
