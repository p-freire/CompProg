/*
	Idea: read the numbers of cards as a set (ignoring repeated cards).
	Let A and B be the sets from both girls. So we perform the operations
		1) counterA = A - B
		2) counterB = B - A
	and return the lesser of counters
*/

#include <stdio.h>
#include <iostream>
#include <set>
using namespace std;

set<int> a, b;

int max_trade(set<int> a, set<int> b)
{
	int counterA, counterB;
	counterA = counterB = 0;

	for(set<int>::iterator it = a.begin(); it != a.end(); ++it)
	{
		if(b.find(*it) == b.end())
			++counterA;
	}

	for(set<int>::iterator it = b.begin(); it != b.end(); ++it)
	{
		if(a.find(*it) == a.end())
			++counterB;
	}
	return counterA < counterB ? counterA : counterB;
}

int main(int argc, char **argv)
{
	int nA, nB, card, max_cards;
	
	while(scanf("%d %d", &nA, &nB) && (nA || nB))
	{
		for(int i = 0; i < nA; ++i)
		{
			scanf("%d", &card);
			a.insert(card);
		}

		for(int i = 0; i < nB; ++i)
		{
			scanf("%d", &card);
			b.insert(card);
		}

		printf("%d\n", max_cards = max_trade(a, b));
		a.clear();
		b.clear();
	}

	return 0;
}