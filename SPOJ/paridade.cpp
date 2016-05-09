#include <iostream>
#include <stack>
 
using namespace std;
stack<int> numBin;
 
void printDecToBin(int num)
{
    int resto, contadorParidade;
    contadorParidade = 0;
    do
    {
        resto = num % 2;
        if(resto == 1)
            contadorParidade++;
        numBin.push(resto);
        num = num / 2;
    }
    while(num > 0);
    while(!numBin.empty())
    {
        printf("%d", numBin.top());
        numBin.pop();
    }
    printf(" is %d (mod 2).\n", contadorParidade);
}
 
int main()
{
    int n;
    cin>>n;
    while(n != 0)
    {
        printf("The parity of ");
        printDecToBin(n);
        cin>>n;
    }
    return 0;
}
 