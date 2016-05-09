#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
        int n;
        long long int num, sum;
        scanf("%d", &n);
        while(n--)
        {
                sum = 1;
                scanf("%lld", &num);
                if(num % 2 == 0)
                {
                        for(int i = num / 2; i >= 2; --i)
                        {
                                if(sum > num)
                                        break;
                                else if(num % i == 0)
                                        sum += i;
                        }
                }
                if(sum != num || num == 1)
                        printf("%lld nao eh perfeito\n", num);
                else
                        printf("%lld eh perfeito\n", num);
        }
        return 0;
}
