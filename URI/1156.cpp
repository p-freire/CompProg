#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
       double result = 1.0;
       unsigned long long int pow2 = 2;
       for(int i = 3; i <= 39; i += 2)
       {
              result += (double)i/(double)pow2;
              pow2 = pow2 << 1;
       }
       printf("%.2lf\n", result);
       return 0;
}
