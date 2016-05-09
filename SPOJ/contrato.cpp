#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#define MAX_DIGITS 110
using namespace std;
 
char number[MAX_DIGITS];
 
int main()
{
    int n; // number that is missing
    bool isJustZero = true;
 
    while(scanf("%d", &n) && n != 0)
    {
       scanf("%s", number);
       for(int i = 0; number[i] != '\0'; ++i)
       {
          if((int)number[i] - 48 != n)
          {
             if((int)number[i] - 48 != 0)
             {
                isJustZero = false;
                printf("%c", number[i]);
             }
             else if((int)number[i] - 48 == 0 && !isJustZero)
                printf("%c", number[i]);
          }
       }
       if(isJustZero)
          printf("0");
       printf("\n");
       isJustZero = true;
    }
    return 0;
}