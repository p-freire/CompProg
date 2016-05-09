#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    double grade1, grade2, grade3, grade4, exam, avg;
    scanf("%lf %lf %lf %lf", &grade1, &grade2, &grade3, &grade4);
    avg = (grade1 * 2.0 + grade2 * 3.0 + grade3 * 4.0 + grade4 * 1.0) / 10.0;

    printf("Media: %.1lf\n", avg);
    if(avg >= 7.0)
        printf("Aluno aprovado.\n");
    else if(avg < 5.0)
        printf("Aluno reprovado.\n");
    else
    {
        printf("Aluno em exame.\n");
        scanf("%lf", &exam);
        printf("Nota do exame: %.1lf\n", exam);
        avg = (avg + exam) / 2.0;
        if(avg >= 5.0)
            printf("Aluno aprovado.\n");
        else
            printf("Aluno reprovado.\n");
        printf("Media final: %.1lf\n", avg);
    }
    return 0;
}