#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define BUFFER_SIZE 1024
using namespace std;

int main()
{
    char name[BUFFER_SIZE];
    double salary, sales;
    scanf("%s %lf %lf", name, &salary, &sales);
    printf("TOTAL = R$ %.2lf\n", salary + (sales * 0.15));
    return 0;
}