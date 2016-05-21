#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3000

int main()
{
    char input[MAX], *tk, firstLetter;
    bool flag;
    while(fgets(input, MAX, stdin) && input[0] != '*')
    {
        flag = true;
        tk = strtok(input, " ");
        firstLetter = (int)tk[0] > 90 ? tk[0] - 32 : tk[0];
        while(tk != NULL && flag)
        {
            tk = strtok(NULL, " ");
            if(tk != NULL)
            {
                tk[0] = (int)tk[0] > 90 ? tk[0] - 32 : tk[0];
                if(tk[0] != firstLetter)
                    flag = false;
            }
        }
        printf(flag ? "Y\n" : "N\n");
    }

    return 0;
}
