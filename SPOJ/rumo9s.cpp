#include <iostream>
#define max 1001
 
using namespace std;
int contaQtdeRecursoes  = 0;
 
bool depth9(int num)
{
    int aux = 0;
 
    contaQtdeRecursoes++;
 
    if(num < 10)
    {
        if(num % 9 == 0)
            return true;
        else
            return false;
    }
 
    while(num > 0)
    {
        aux += num % 10;
        num = num / 10;
    }
 
    return depth9(aux);
}
 
int main()
{
    char vetor[max];
    int num = 0, i = 0;
    scanf("%s", vetor);
 
    while(vetor[i] != '\0')
    {
        num += (int)vetor[i] - 48;
        i++;
    }
 
    while(num != 0)
    {
        i = 0;
        while(vetor[i] != '\0')
        {
            printf("%c", vetor[i]);
            i++;
        }
 
        if(depth9(num))
            printf(" is a multiple of 9 and has 9-degree %d.\n", contaQtdeRecursoes);
        else
            printf(" is not a multiple of 9.\n");
 
        num = 0;
        contaQtdeRecursoes = 0;
        i = 0;
        //memset(vetor, '\0', max*sizeof(char));
 
        scanf("%s", vetor);
 
        while(vetor[i] != '\0')
        {
            num += (int)vetor[i] - 48;
            i++;
        }
    }
 
    return 0;
}