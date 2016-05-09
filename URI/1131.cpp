#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
int score_inter, score_gremio, wins_inter, wins_gremio, num_wo, num_grenais;

void calc_score()
{
    int a, b;
    scanf("%d %d", &a, &b);
    ++num_grenais;
    score_inter += a;
    score_gremio += b;
    if(a > b)
        ++wins_inter;
    else if(b > a)
        ++wins_gremio;
    else
        ++num_wo;
}

int main()
{
    score_inter = score_gremio = wins_inter = wins_gremio = num_wo = num_grenais = 0;
    int option;
    calc_score();
    do
    {
        printf("Novo grenal (1-sim 2-nao)\n");
        scanf("%d", &option);
        if(option == 1)
            calc_score();
    }while(option != 2);
    printf("%d grenais\n", num_grenais);
    printf("Inter:%d\nGremio:%d\nEmpates:%d\n", wins_inter, wins_gremio, num_wo);
    if(wins_inter == wins_gremio)
        printf("Nao houve vencedor\n");
    else
        printf((wins_inter > wins_gremio) ? "Inter venceu mais\n" : "Gremio venceu mais\n");

    return 0;
}
