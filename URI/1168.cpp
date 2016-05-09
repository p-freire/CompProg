#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define MAX 110
using namespace std;

char digits[MAX];

int main()
{
    int n, numOfLeds; // number of test cases, number of leds
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", digits);
        numOfLeds = 0;
        for(int i = 0; digits[i] != '\0'; ++i)
        {
            if(digits[i] == '1')
                numOfLeds += 2;
            else if(digits[i] == '7')
                numOfLeds += 3;
            else if(digits[i] == '4')
                numOfLeds += 4;
            else if(digits[i] == '2' || digits[i] == '3' || digits[i] == '5')
                numOfLeds += 5;
            else if(digits[i] == '6' || digits[i] == '9' || digits[i] == '0')
                numOfLeds += 6;
            else
                numOfLeds += 7;
        }
        printf("%d leds\n", numOfLeds);
    }
}
