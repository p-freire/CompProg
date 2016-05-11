#include <stdio.h>
#include <stdlib.h>
#define TAM 100000010
typedef long long int lli;

lli numbers[TAM];

lli euclides(lli a, lli b)
{
    lli r;
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(int argc, char **argv)
{
    lli n, i, mod_sum, denominator, loop_prune;
    //lli *numbers = (lli*)malloc(TAM * sizeof(lli));

    for(i = 0; i < TAM; ++i)
        numbers[i] = -1;

    while(scanf("%lld", &n) != EOF)
    {
        denominator = n * n;
        if(numbers[n] == -1)
        {
            mod_sum = 0;
            loop_prune = n / 2;

            for(i = 2; i <= loop_prune; ++i)
                mod_sum += n % i;

            // from (n / 2) + 1, the remainders will form an arithmetic progression
            // this value can be calculated effortlessly using a closed formula
            lli remainder = n % (loop_prune + 1);
            mod_sum += remainder > 1 ? ((1 + remainder) * remainder) / 2 : remainder;

            numbers[n] = mod_sum;
        }
        lli divi = euclides(denominator, numbers[n]);
        printf("%lld/%lld\n", numbers[n] / divi, denominator / divi);
    }
    //free(numbers);
    return 0;
}
