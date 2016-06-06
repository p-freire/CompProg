/*
	Idea: calculate the square root of N and calculate
	the arithmetic progression sums in the intervals
	[N/(i+1) + 1, N/i], 1 <= i <= sqrt(N).
	Then, calculate the rest of the remainders from
	i = 1 to i = N/(sqrt(N) + 1).
	Finally, get the greatest common divider using Euclid 
	algorithm and simplify the fraction.
*/

#include <cmath>
#include <iostream>
#include <stdio.h>

typedef long long lli;
using namespace std;

lli solve(lli x) 
{
	lli ret = 0;
	int d = (int)(sqrt(x));
	for (int i = 1; i <= d; i++)
    {
		int l = x / (i + 1) + 1, r = x / i;
		lli a1, an, n;
        if(l != r)
        {
            a1 = x % l;
            an = x % r;
            n = (r - l) + 1;
            ret += (a1 + an) * n / 2;
        }
        else
            ret += x % l;
	}

	for (int i = 1; i <= x / (d + 1); i++)
        ret += x % i;

	return ret;
}

lli gcd(lli a, lli b)
{
    lli r;
    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() 
{
	lli n, divi, ans, den;
	while(scanf("%lld", &n) != EOF)
    {
        den = n * n;
        ans = solve(n);
        divi = gcd(den, ans);
        printf("%lld/%lld\n", ans / divi, den / divi);
    }
    return 0;
}
