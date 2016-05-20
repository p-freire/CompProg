#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#define EPS 0.000001
using namespace std;

int main()
{
    double hypotenuse, runawayTime, policeTime;
    int d, vf, vg; // initial distance between the fugitive and the police, runaway boat speed, police boat speed

    while(scanf("%d %d %d", &d, &vf, &vg) != EOF)
    {
        hypotenuse = sqrt(double(d*d) + 144.0); // 12^2 = 144
        runawayTime = 12.0/double(vf);
        policeTime = hypotenuse/double(vg);

        if(runawayTime > policeTime || fabs(runawayTime - policeTime) < EPS)
            printf("S\n");
        else
            printf("N\n");

        // runawayTime >= policeTime ? printf("S\n") : printf("N\n");
    }

    return 0;
}
