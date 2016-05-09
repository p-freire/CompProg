#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define max 101
using namespace std;
 
int matrizAdj[max][max];
int conv[max];
bool deuErro = false;
int instancia = 1;
 
void DF(int v, int &tam)
{
	for(int i = 0; i < tam; i++)
	{
		if(matrizAdj[v][i] == 1)
		{
			if(conv[i] == -1 && conv[v] == -1){
				conv[i] = 0;
				conv[v] = 1;
				DF(i, tam);		
			}
			else if(conv[i] == -1 && conv[v] != -1){
				conv[i] = (conv[v] + 1) % 2;
				DF(i, tam);
			}
			else if(conv[v] == -1 && conv[i] != -1){
				conv[v] = (conv[i] + 1) % 2;
			}
			else
			{
				if(i != v && conv[i] == conv[v]){				
					deuErro = true;
					return;
				}
			}
		}
	}
}
 
 
int main()
{
	int n = 0, m = 0, pessoa1 = 0, pessoa2 = 0;
	
	for(int i = 0; i < max; i++)
		for(int j = 0; j < max; j++)
			matrizAdj[i][j] = 0;
 
	for(int i = 0; i < max; i++)
		conv[i] = -1;	
 
	while(scanf("%d %d", &n, &m) != EOF)
	{
		while(m > 0)
		{
			scanf("%d %d", &pessoa1, &pessoa2);
			pessoa1--; pessoa2--;
			if(pessoa1 != pessoa2)
				matrizAdj[pessoa1][pessoa2] = 1;
			m--;
		}
 
		for(int i = 0; i < n; i++)
			if(conv[i] == -1)		
				DF(i, n);
 
 
		if(deuErro)
			printf("Instancia %d\nnao\n\n", instancia);
		else
			printf("Instancia %d\nsim\n\n", instancia);	
		
		deuErro = false;
 
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				matrizAdj[i][j] = 0;
 
		for(int i = 0; i < max; i++)
		{
			conv[i] = -1;
		}
		
		instancia++;
	}
	return 0;
} 