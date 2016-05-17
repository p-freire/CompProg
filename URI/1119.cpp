/*
	This implementation is a mere simulation of the input.
	No closed formulas. No pruning. Pure and simple simulation.
	The most annoying thing here is the way the output must be
	formatted. Other than that, it is a straightforward problem.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 30

int main()
{
	int n, m, k, i, r, pos_r, l, pos_l, people_counter;
	int people[MAX_SIZE];
	while(scanf("%d %d %d", &n, &m, &k) && (n || m || k))
	{
		for(i = 0; i < n; ++i)
			people[i] = i + 1;

		int counter;
		people_counter = n;
		pos_r = 0;
		pos_l = n - 1;
		while(people_counter > 0)
		{
			counter = 0;
			while(counter < m)
			{
				if(people[pos_r] != -1)
					++counter;
				if(counter != m)
					pos_r = (pos_r + 1) % n;
			}
			r = people[pos_r];
			
			counter = 0;
			while(counter < k)
			{
				if(people[pos_l] != -1)
					++counter;
				if(counter != k)
					pos_l = (pos_l - 1 >= 0) ? pos_l - 1 : n - 1;
			}
			l = people[pos_l];
			
			if(r == l)
			{
				printf(r <= 9 ? "  %d" : " %d", r);
				--people_counter;
			}
			else
			{
				printf(r <= 9 ? "  %d" : " %d", r);
				printf(l <= 9 ? "  %d" : " %d", l);
				people_counter -= 2;
			}

			people[pos_l] = people[pos_r] = -1;
			if(people_counter > 0)
				printf(",");
		}
		printf("\n");
	}
	return 0;
}
