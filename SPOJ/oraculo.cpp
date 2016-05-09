#include <iostream>
#include <math.h>
#define tamMax 25
using namespace std;
 
int main()
{
    unsigned long long int resultado = 1;
    int num = 0, numExclamacoes = 0, i = 0, aux, contadorNum, contadorExclamacoes, tmp, instancias;
    char entrada[tamMax];
 
    scanf("%d", &instancias);
 
    while(instancias--)
    {
        scanf("%s", entrada);
 
        for(contadorNum = 0; entrada[contadorNum] != '!'; contadorNum++); //conta a quantidade de digitos que o numero tem
        for(contadorExclamacoes = contadorNum + 1; entrada[contadorExclamacoes] != '\0'; contadorExclamacoes++); //conta a quantidade de exclamacoes depois do digito
 
        numExclamacoes = contadorExclamacoes - contadorNum;
        tmp = 1;
        contadorNum--; //subtrai 1 para ficar na posiÃ§Ã£o correta do vetor
        while(contadorNum >= 0)
        {
            num += ((int)entrada[contadorNum] - 48)*tmp; //num armazena o valor do numero entrado no vetor
            tmp *= 10;
            contadorNum--;
        }
 
        while((numExclamacoes * i) < num)
        {
            aux = num - (numExclamacoes * i);
            if(aux <= 0)
                break;
            resultado *= aux;
            i++;
        }
 
        printf("%llu\n", resultado);
        i = 0;
        num = 0;
        resultado = 1;
    }
    return 0;
}