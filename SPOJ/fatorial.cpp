#include <iostream>
 
using namespace std;
//Global
long long int fatorial[1000001];
 
void calculaFatorial()
{
    long long int i;
    long long int temp;
    fatorial[0] = 1;
    fatorial[1] = 1;
    for(i = 2; i <= 1000000; ++i)
    {
        temp = fatorial[i-1]*i;
        do
        {
            if(temp % 10 == 0)
                temp = temp / 10;
        }
        while(temp % 10 == 0);
        if(temp > 1000000){
            temp = temp % 1000000;
        }
        fatorial[i] = temp;
    }
}
 
int getResultado(int n)
{
    long long int temp = fatorial[n];
    do
    {
        if(temp % 10 == 0)
            temp = temp / 10;
        else
            temp = temp % 10;
    }
    while(temp > 10);
    return (int)temp;
}
 
int main()
{
    calculaFatorial();
    int valor, instancia;
    instancia = 1;
    while(scanf("%d", &valor) != EOF)
    {
//        resultado = fatorial[valor];
//        printf("Instancia %d\n%d\n\n", instancia, resultado);
        cout<<"Instancia "<<instancia<<endl<<getResultado(valor)<<endl<<endl;
        instancia++;
    }
 
    return 0;
}