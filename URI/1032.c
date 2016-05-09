#include <stdio.h>
#define MAX_CRIVO 50000
#define MAX_N 3510

int crivo[MAX_CRIVO];
int primos[MAX_CRIVO];
int pessoas[MAX_N];

void crivo_eratostenes()
{
    int i, j, k;
    k = 1;
    for(i = 0; i < MAX_CRIVO; ++i)
        crivo[i] = i + 2;

    for(i = 0; i < MAX_CRIVO; ++i)
        if(crivo[i] != 0)
        {
        	primos[k++] = crivo[i];
            for(j = (i << 1) + 2; j < MAX_CRIVO; j += (i + 2))
                crivo[j] = 0;
        }

}

int formula(int n, int k, int ith_prime)
{
    //return(n == 1 ? 0 : (formula(n - 1, findithPrime(crivo, ith_prime + 1), ith_prime + 1) + k) % n);
    return(n == 1 ? 0 : (formula(n - 1, primos[ith_prime + 1], ith_prime + 1) + k) % n);
}


int findithPrime(int crivo[MAX_CRIVO], int ith_prime)
{
    int i = 0, counter = 0;
    while(counter < ith_prime)
    {
        while(crivo[i] == 0)
            ++i;
        ++counter;
        if(counter < ith_prime)
            ++i;
    }
    return crivo[i];
}

int main(int argc, char **argv)
{
    int n, i, j, counter, aux;
    crivo_eratostenes();

    while(scanf("%d", &n) && n)
    {
        //printf("%d\n", formula(n, findithPrime(crivo, 1), 1) + 1);
        printf("%d\n", formula(n, primos[1], 1) + 1);

    }
    /*for(i = 1; i <= 3501; ++i)
    	//printf("%d\n", formula(i, findithPrime(crivo, 1), 1) + 1);
    	printf("%d\n", formula(i, primos[1], 1) + 1);*/
    return 0;
}