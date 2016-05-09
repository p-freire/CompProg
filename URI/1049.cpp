#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#define BUFFER 1024
using namespace std;

int main()
{
    char w1[BUFFER], w2[BUFFER], w3[BUFFER];
    scanf("%s %s %s", w1, w2, w3);
    if(strcmp(w1, "vertebrado") == 0)
    {
        if(strcmp(w2, "ave") == 0)
        {
            if(strcmp(w3, "carnivoro") == 0)
                printf("aguia\n");
            else
                printf("pomba\n");
        }
        else
        {
            if(strcmp(w3, "onivoro") == 0)
                printf("homem\n");
            else
                printf("vaca\n");
        }
    }
    else
    {
        if(strcmp(w2, "inseto") == 0)
        {
            if(strcmp(w3, "hematofago") == 0)
                printf("pulga\n");
            else
                printf("lagarta\n");
        }
        else
        {
            if(strcmp(w3, "hematofago") == 0)
                printf("sanguessuga\n");
            else
                printf("minhoca\n");
        }
    }
    return 0;
}
