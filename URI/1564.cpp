/*
  Idea: simply read N and print accordingly
*/

#include <stdio.h>

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
        printf(n ? "vai ter duas!\n" : "vai ter copa!\n");
    return 0;
}
