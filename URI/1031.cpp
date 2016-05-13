#include <stdio.h>
#include <stdlib.h>
#include <iostream>

/*
    The idea here is to use the closed formula for calculating the Josephus problem.
    Since the first region will always be eliminated, we use N - 1 instead of N.
    We add 2 to the final result because this implementation gives the answer in the
    range [0, N - 1] for N. Since we are using N - 1, the interval is actually [1, N - 2].
    Therefore, we need to add 2 to comply with the correct answer.

*/

int josephus(int n, int m)
{
    return(n == 1 ? 0 : (josephus(n - 1, m) + m) % n);
}

int main(int argc, char **argv)
{
    int n, i, m;
    while(scanf("%d", &n) && n)
    {
        i = 1;
        while(josephus(n - 1, i) != 11) // 13 - 2
            ++i;
        printf("%d\n", i);
    }
    return 0;
}
