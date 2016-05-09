#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
using namespace std;

int main()
{
	int m, n, min, max;
	while(scanf("%d %d", &m, &n) && (n != 0) && (m != 0))
	{
		min = MIN(m,n);
		max = MAX(m,n);
		for(int i = min; i <= max; ++i)
			printf("%d ", i);
		printf("Sum=%d\n", ((min + max) * (max - min + 1))/2);
	}
	return 0;
}