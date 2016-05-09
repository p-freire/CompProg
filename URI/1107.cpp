#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define SET(a, b) memset((a), (b), sizeof(a))
using namespace std;

stack<int> s;

int main()
{
    int a, c, aux, num_mov;
    while(scanf("%d %d", &a, &c))
    {
        if(a == 0 && c == 0)
            break;
        num_mov = 0;
        scanf("%d", &aux);
        s.push(aux);
        FOR(i, 1, c)
        {
            scanf("%d", &aux);
            if(aux > s.top())
            {
                num_mov += aux - s.top();
                s.pop();
                s.push(aux);
            }
            else if(aux < s.top())
            {
                s.pop();
                s.push(aux);
            }
        }
        num_mov += a - s.top();
        printf("%d\n", num_mov);
        while(!s.empty())
            s.pop();
    }
    return 0;
}