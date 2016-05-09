#include <stdio.h>
#include <stdlib.h>

int main()
{	
	int n;
	double a, b;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%lf %lf", &a, &b);
		if(b != 0)
			printf("%.1lf\n", (double)(a / b));
		else
			printf("divisao impossivel\n");
	
	}

	return 0;

}