#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
        int t, num_years;
        long int pa, pb;
        double g1, g2;
        scanf("%d", &t);
        while(t--)
        {
                scanf("%ld %ld %lf %lf", &pa, &pb, &g1, &g2);
                num_years = 0;
                g1 /= 100.0;
                g2 /= 100.0;
                while(pa <= pb && num_years <= 100)
                {
                        pa += ((double)pa * g1);
                        pb += ((double)pb * g2);
                        ++num_years;
                }
                if(num_years > 100)
                        printf("Mais de 1 seculo.\n");
                else
                        printf("%d anos.\n", num_years);
        }
        return 0;
}
