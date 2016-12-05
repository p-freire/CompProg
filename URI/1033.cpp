/*
	Idea: use matrix A = {{1, 1}, {1, 0}} to calculate Fibonacci in O(log n) time.
	The first matrix element (i.e. A[0][0]) times 2 minus 1 is the number of
	recursive calls for the nth Fibonacci number.
	Pay attention to the modular arithmetic!
*/


#include <stdio.h>
#include <vector>

std::vector<int> matMul(std::vector<int> a, std::vector<int> b, int n, int m, int mod)
{
	std::vector<int> tmp(n * m, 0);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			for(int k = 0; k < m; ++k)
				tmp[i * m + j] += (a[i * m + k] * b[j + k * n]) % mod;
	return tmp;
}


std::vector<int> matPow(std::vector<int> mat, int expo, int n, int m, int mod)
{
	if(expo == 1) // base case
		return mat;
	else if(expo & 1) // if odd
		return matMul(mat, matPow(mat, expo - 1, n, m, mod), n, m, mod);
	else
	{
		std::vector<int> aux = matPow(mat, expo / 2, m, n, mod);
		return matMul(aux, aux, n, m, mod);
	}
}


int main()
{
	std::vector<int> v, ans;
	unsigned long long int n;
	int b, case_num = 1;


	v.resize(4);
	v[0] = 1; v[1] = 1; v[2] = 1; v[3] = 0;
	
	while(scanf("%lli %d", &n, &b) && (n || b))
	{
		if(n < 2)
			printf("Case %d: %lli %d %d\n", case_num++, n, b, 1 % b);
		else
		{
			ans = matPow(v, n, 2, 2, b);
			printf("Case %d: %lli %d %d\n", case_num++, n, b, (ans[0] * 2 - 1) % b);
		}
	}

	return 0;
}
