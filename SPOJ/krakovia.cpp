#include <iostream>
#include <string.h>
#define tamMax 30
using namespace std;
char entrada[tamMax];
int termo[tamMax];
int soma[tamMax];
int resultado[tamMax];
int n, f; //n ==> numero de itens na conta; f==> numero de amigos para dividir o valor da conta
bool deuZero = true;
 
void somar(int termo[tamMax])
{
    int tamanho, num1, num2, aux, indice = tamMax - 1;
 
    for(tamanho = 0; termo[tamanho] != -1; tamanho++);
    tamanho--;
 
    while(tamanho >= 0)
    {
        num1 = soma[indice];
        num2 = termo[tamanho];
        soma[indice] = (num1 + num2) % 10;
        if(tamanho == 0 && num1 + num2 >= 10)
        {
            int carry = 1;
            while(carry == 1)
            {
                indice--;
                aux = soma[indice];
                soma[indice] = (carry + aux) % 10;
                carry = (carry + aux) / 10;
            }
        }
        else if(num1 + num2 >= 10 && tamanho > 0)
            soma[indice - 1] = soma[indice - 1] + 1;
        tamanho--;
        indice--;
    }
}
 
void dividir(int soma[tamMax])
{
    int i, j = 0;
    int quociente = 0, resto = 0, numero = 0;
    for(i = 0; soma[i] == 0; i++);
 
    while(i < tamMax)
    {
        numero += soma[i];
        quociente = numero / f;
        if(quociente > 0) deuZero = false;
        resto = numero % f;
        numero = resto * 10;
        resultado[j] = quociente;
        j++;
        i++;
    }
}
 
void passaPraInt(char entrada[tamMax])
{
    memset(termo, -1, sizeof(termo));
    for(int i = 0; entrada[i] != '\0'; i++)
        termo[i] = (int)entrada[i] - 48;
 
}
 
int main()
{
    int instancia = 1, i;
    memset(entrada, '\0', sizeof(entrada));
    memset(soma, 0, sizeof(soma));
    memset(resultado, -1, sizeof(resultado));
 
    scanf("%d %d", &n, &f);
 
    while(n > 0 && f > 0)
    {
        while(n > 0)
        {
            scanf("%s", entrada);
            passaPraInt(entrada);
            somar(termo);
            n--;
        }
 
        dividir(soma);
        printf("Bill #%d costs ", instancia);
 
        for(i = 0; soma[i] == 0; i++);
        while(i < tamMax)
        {
            printf("%d", soma[i]);
            i++;
        }
        printf(": each friend should pay ");
        if(deuZero)
            printf("0\n\n");
        else
        {
            for(i = 0; resultado[i] == 0; i++);
            while(resultado[i] != -1)
            {
                printf("%d", resultado[i]);
                i++;
            }
            printf("\n\n");
        }
 
        memset(entrada, '\0', sizeof(entrada));
        memset(soma, 0, sizeof(soma));
        memset(resultado, -1, sizeof(resultado));
        instancia++;
        deuZero = true;
        scanf("%d %d", &n, &f);
    }
 
    return 0;
}