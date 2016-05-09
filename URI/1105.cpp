#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define SET(a, b) memset((a), (b), sizeof(a))
#define MAX 25
using namespace std;

int reservasBanco[MAX];

int main()
{
    int b, n;
    int d, c, v;
    while(scanf("%d %d", &b, &n))
    {
        if(b == 0 && n == 0)
            break;
        SET(reservasBanco, 0);

        FOR(i, 1, b + 1)
            scanf("%d", &reservasBanco[i]);

        FOR(i, 0, n)
        {
            scanf("%d %d %d", &d, &c, &v);
            reservasBanco[c] += v;
            reservasBanco[d] -=v;
        }

        bool ok = true;
        FOR(i, 1, b + 1)
        {
            if(reservasBanco[i] < 0)
            {
                ok = false;
                break;
            }
        }
        printf( ok == true ? "S\n" : "N\n" );
    }
    return 0;
}