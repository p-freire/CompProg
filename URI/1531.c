#include <stdio.h>
#include <math.h>
#include <string.h>
unsigned long long int f[20000000];
unsigned long long int fibonacci(unsigned long long int n, unsigned long long int mod)
{
	if(n <= 2)
		return 1;
	else
	{
		unsigned long long int fib[2][2] = {{1, 1}, {1, 0}}, ans[2][2] = {{1, 0}, {0, 1}}, tmp[2][2] = {{0, 0}, {0, 0}};
		int i, j, k;
		while(n)
		{
			if(n & 1) // if n is odd
			{
				memset(tmp, 0, sizeof(tmp));
				for(i = 0; i < 2; ++i)
					for(j = 0; j < 2; ++j)
					{
						for(k = 0; k < 2; ++k)
							tmp[i][j] += ans[i][k] * fib[k][j];
						tmp[i][j] %= mod;
					}

				for(i = 0; i < 2; ++i)
					for(j = 0; j < 2; ++j)
						ans[i][j] = tmp[i][j];
			}
			memset(tmp, 0, sizeof(tmp));
			for(i = 0; i < 2; ++i)
					for(j = 0; j < 2; ++j)
					{
						for(k = 0; k < 2; ++k)
							tmp[i][j] += fib[i][k] * fib[k][j];
						tmp[i][j] %= mod;
					}
			
			for(i = 0; i < 2; ++i)
					for(j = 0; j < 2; ++j)
						fib[i][j] = tmp[i][j];
			n /= 2;
		}
		return(ans[0][1]);
	}
}


unsigned long long int pisano(unsigned long long int m)
{
	unsigned long long int tam_ciclo, prim, seg, ter;
	prim = seg = 1;
	tam_ciclo = 1;
	int prim_num = 0, seg_num = 0;
	while(prim_num == 0 || seg_num == 0)
    {
        ter = ((prim % m) + (seg % m)) % m;
        if(ter == 1)
            if(prim_num == 0)
                prim_num = 1;
            else
                seg_num = 1;
        prim = seg % m;
        seg = ter;
        ++tam_ciclo;
    }
    return tam_ciclo;
}

int main(int argc, char **argv)
{
	unsigned long long int n, m, ciclo_m, ciclo_m_m, parcial, final;
	while(scanf("%lld %lld", &n, &m) != EOF)
	{
	    //ciclo_m = pisano(m);
	    //ciclo_m_m = pisano(ciclo_m);
	    f[1] = f[2] = 1;
	    ciclo_m = 3;
	    f[ciclo_m] = (f[1] + f[2]) % m;
	    
	    while(f[ciclo_m] != 1 || f[ciclo_m - 1] != 1)
	    {
	    	++ciclo_m;
	    	f[ciclo_m] = (f[ciclo_m - 1] + f[ciclo_m - 2]) % m;
	    }
	    
	    ciclo_m -= 2;
	    f[0] = f[ciclo_m];

	    parcial = fibonacci(n, ciclo_m);
	    final = f[parcial];
	    printf("%lld\n", final);
	}
	return 0;
}
