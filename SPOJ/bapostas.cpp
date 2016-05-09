#include <iostream>
#define max 10000
using namespace std;
 
int main()
{
    int vetor[max];
    int num;
    int maiorSoma = 0, aux = 0, n;
 
    scanf("%d", &n);
 
    while(n != 0)
    {
//        for(int i = 0; i < n; i++)
//            scanf("%d", &vetor[i]);
 
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &num);
            if(aux + num > 0)
            {
                if(aux + num > maiorSoma)
                {
                    aux += num;
                    maiorSoma = aux;
                }
                else
                    aux += num;
            }
            else
                aux = 0;
        }
 
        if(maiorSoma > 0)
            printf("The maximum winning streak is %d.\n", maiorSoma);
        else
            printf("Losing streak.\n");
 
        maiorSoma = 0;
        aux = 0;
        scanf("%d", &n);
    }
    return 0;
}