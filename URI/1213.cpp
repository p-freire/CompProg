/*
	Idea: use modulo operation to make the number fit in a long long int.
	The rules are:
		(a + b) % m = ((a % m) + (b % m)) % m
		(a * b) % m = ((a % m) * (b % m)) % m
		(a - b) % m = ((a % m) - (b % m)) % m
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef long long int lli;

int main()
{
	int n;
	
	while(scanf("%d", &n) != EOF)
	{
		lli multiple = 11, i = 2;
		while(multiple % n != 0)
		{	
			multiple = ((((10 % n) * (multiple % n)) % n) + (1 % n)) % n;
			++i;
		}
		printf("%lld\n", i);
	}

	return 0;
}