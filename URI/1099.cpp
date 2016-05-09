#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
using namespace std;

int main()
{
	int n, sum, x, y, max, min;
	sum = 0;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d", &x, &y);
		max = MAX(x,y);
		min = MIN(x,y);
		for(int i = min + 1; i < max; ++i)
			if(i % 2 == 1)
				sum += i;
		printf("%d\n", sum);
		sum = 0;
	}
	return 0;
}