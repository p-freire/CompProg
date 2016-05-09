#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    double salary, new_salary;
    int percentage;
    scanf("%lf", &salary);

    if(salary > 0 && salary <= 400.00)
    {
        new_salary = salary * 1.15;
        percentage = 15;
    }
    else if(salary > 400.00 && salary <= 800.00)
    {
        new_salary = salary * 1.12;
        percentage = 12;
    }
    else if(salary > 800.00 && salary <= 1200.00)
    {
        new_salary = salary * 1.10;
        percentage = 10;
    }
    else if(salary > 1200.00 && salary <= 2000.00)
    {
        new_salary = salary * 1.07;
        percentage = 7;
    }
    else
    {
        new_salary = salary * 1.04;
        percentage = 4;
    }
    printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: %d %%\n", new_salary, new_salary - salary, percentage);

    return 0;
}
