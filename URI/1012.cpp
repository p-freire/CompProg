#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define PI 3.14159
using namespace std;

int main()
{
    double triangle, circle, trap, square, rect;
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    triangle = (a * c)/ 2.0;
    circle = PI * c * c;
    trap = (a + b) * c / 2.0;
    square = b * b;
    rect = a * b;
    printf("TRIANGULO: %.3lf\n", triangle);
    printf("CIRCULO: %.3lf\n", circle);
    printf("TRAPEZIO: %.3lf\n", trap);
    printf("QUADRADO: %.3lf\n", square);
    printf("RETANGULO: %.3lf\n", rect);
    return 0;
}