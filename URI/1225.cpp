#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define MAX 10010

using namespace std;

int notes[MAX]; // notes the choir singers will initially sing

int main()
{
    int average, n, compasses; // average of notes, number of singers, number of compasses needed
    int i; // index

    while(scanf("%d", &n) != EOF)
    {
        memset(notes, 0, sizeof(notes));
        average = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &notes[i]);
            average += notes[i];
        }

        if(average % n != 0)
            printf("-1\n");
        else
        {
            average /= n;
            compasses = 1;
            i = 0;
            while(notes[i] < average)
            {
                compasses += average - notes[i];
                i++;
            }
            printf("%d\n", compasses);
        }
    }
    return 0;
}
