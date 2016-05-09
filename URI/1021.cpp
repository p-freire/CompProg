#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define NUM_COINS 5
#define NUM_BILLS 7

using namespace std;

int main()
{
	int bills[] = {100, 50, 20, 10, 5, 2, 1};
	int coins[] = {50, 25, 10, 5, 1};
	int num_coins[NUM_COINS], num_bills[NUM_BILLS];
	double value;
	int int_value, cents;

	scanf("%lf", &value);
	int_value = (int)value;
	cents = (value - int_value) * 100;

	for(int i = 0; i < NUM_BILLS; ++i)
	{
		num_bills[i] = int_value / bills[i];
		int_value = int_value % bills[i];
	}

	for(int i = 0; i < NUM_COINS; ++i)
	{
		num_coins[i] = cents / coins[i];
		cents = cents % coins[i];
	}

	printf("NOTAS:\n");
	for(int i = 0; i < NUM_BILLS - 1; ++i)
		printf("%d nota(s) de R$ %d.00\n", num_bills[i], bills[i]);

	printf("MOEDAS:\n");
	printf("%d moeda(s) de R$ %d.00\n", num_bills[NUM_BILLS - 1], bills[NUM_BILLS - 1]);
	for(int i = 0; i < NUM_COINS; ++i)
		printf("%d moeda(s) de R$ %.2lf\n", num_coins[i], (double)coins[i]/100.0);

	return 0;
}