/*
	Idea: read all remaining b_i numbers.
	Given b_i, calculate all possibilities of
	abs(b_i - b_j), for j = 0 .. b and mark it as
	1 in an aux array.
	Iterate through this array from 0 to n (inclusive)
	and check if there is a number that wasn't marked.
	It it wasn't, then it's impossible. Otherwise, it's 
	possible.
	Time complexity: O(n^2)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100
int main()
{
	int n, b, i, j, v1[MAX], v2[MAX];
	while(scanf("%d %d", &n, &b) && n || b)
	{
		memset(v1, 0, sizeof(v1));
		memset(v2, 0, sizeof(v2));

		for(i = 0; i < b; ++i)
			scanf("%d", &v1[i]);

		for(i = 0; i < b; ++i)
			for(j = 0; j < b; ++j)
				v2[abs(v1[i] - v1[j])] = 1;

		i = 0;
		while(i <= n && v2[i] == 1)
			++i;
		printf(i > n ? "Y\n": "N\n");

	}
	return 0;
}