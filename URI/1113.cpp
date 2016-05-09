#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

bool is_decreasing(int a, int b)
{
	return(a > b);
}

int main()
{
	int a, b;
	while(scanf("%d %d", &a, &b) && (a != b))
	{
			printf(is_decreasing(a,b) ? "Decrescente\n" : "Crescente\n");
	}
	return 0;
}