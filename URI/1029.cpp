#include <stdio.h>
#include <stdlib.h>

int numOfCalls;

int fibonacci(int n)
{
    ++numOfCalls;
    if(n == 0)
         return 0;
    else if(n == 1)
         return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);   
}


int main()
{
    int n, x;// number of recursive calls, number of fibonacci sequence
    int result;
    scanf("%d", &n);
    while(n--)
    {
              scanf("%d", &x);
              numOfCalls = 0;
              result = fibonacci(x);
              printf("fib(%d) = %d calls = %d\n", x, --numOfCalls, result);
    }
    return 0;
}