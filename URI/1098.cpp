#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std; 

int main()
{
	double i, j, k;
	for(i = 0.0; i <= 2.0; i += 0.2)
	{
		k = 1.0 + i;
		for(int j = 0; j < 3; ++j)
		{
			cout << "I=" << i << " J=" << k << endl;
			k += 1.0;
		}
	}
	return 0;
}