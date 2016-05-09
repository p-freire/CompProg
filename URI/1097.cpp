#include <stdio.h>
#include <stdlib.h>

int main()
{
	int j = 7;
	for(int i = 1; i <= 9; i += 2)
	{	
		for(int k = j; k >= j - 2; --k)
			printf("I=%d J=%d\n", i, k);
		j += 2;
	}
	return 0;
}