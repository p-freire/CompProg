#include <iostream>
#include<vector>
 
using namespace std;
 
unsigned long int f91(unsigned long int n)
{
    if(n <= 100)
        return f91(f91(n + 11));
    else
        return n - 10;
}
 
int main()
{
    vector<unsigned long int> n(1000000);
    unsigned long int i = 0;
    scanf("%lu", &n[i]);
 
    while(n[i] != 0)
    {
        ++i;
        scanf("%lu", &n[i]);
    }
 
    i = 0;
 
    while(n[i] != 0)
    {
        printf("f91(%lu) = %lu\n", n[i],f91(n[i]));
        ++i;
    }
    return 0;
}