#include <iostream>
using namespace std;
 
int main()
{
    char a[1001];
    int soma1, soma2, i, controle;
    i = 0;
    controle = 0;
 
    scanf("%s", a);
    while(a[i] != '\0')
    {
        controle += (int)a[i] - 48;
        i++;
    }
 
    while(controle != 0)
    {
        i = 0;
        soma1 = 0;
        soma2 = 0;
        controle = 0;
 
        while(a[i] != '\0')
        {
            controle += (int)a[i] - 48;
            if(i % 2 == 0)
                soma1 += (int)a[i] - 48; //Tabela ASCII
            else
                soma2 += (int)a[i] - 48; //Tabela ASCII
            i++;
        }
 
        if(controle == 0)
            break;
 
        i = 0;
        while(a[i] != '\0')
        {
            printf("%c", a[i]);
            i++;
        }
 
        if((soma1 % 11) == (soma2 % 11))
            printf(" is a multiple of 11.\n");
        else
            printf(" is not a multiple of 11.\n");
        scanf("%s", a);
    }
    return 0;
}