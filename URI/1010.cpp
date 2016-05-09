#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
    int cod, num_of_pieces;
    double value, total;
    scanf("%d %d %lf", &cod, &num_of_pieces, &value);
    total = (double)num_of_pieces * value;
    scanf("%d %d %lf", &cod, &num_of_pieces, &value);
    total += (double)num_of_pieces * value;
    printf("VALOR A PAGAR: R$ %.2lf\n", total);
    return 0;
}