#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
	int value;
	while(scanf("%d", &value) && value != 2002)
		printf("Senha Invalida\n");
	printf("Acesso Permitido\n");
	return 0;
}