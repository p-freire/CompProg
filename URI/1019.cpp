#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
    int num, seconds, minutes, hours;
    scanf("%d", &num);
    seconds = num > 59 ? num % 60 : num;
    num = (num / 60);
    minutes = num > 59 ? num % 60 : num;
    num = (num / 60);
    hours = num;
    printf("%d:%d:%d\n", hours, minutes, seconds);
    return 0;
}