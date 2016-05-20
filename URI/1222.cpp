#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#define MAX 75

using namespace std;

char word[MAX];

int main()
{
    int n, l, c; // number of words, number of lines per page, number of characters per line
    int numPages; // number of pages needed to fit the words


    while(scanf("%d %d %d", &n, &l, &c) != EOF)
    {
        numPages = 0;
        int charCount = 0;
        int linesCount = 1;
        int pagesCount = 1;

        for(int i = 0; i < n; i++)
        {
            scanf("%s", word);
            if(charCount + strlen(word) <= c)
                charCount += strlen(word) + 1; // plus one for the blank space
            else
            {
                charCount = strlen(word) + 1; // again, plus one for the blank space
                if(linesCount < l)
                    linesCount++;
                else
                {
                    linesCount = 1;
                    pagesCount++;
                }
            }
        }
        printf("%d\n", pagesCount);

    }
    return 0;
}
