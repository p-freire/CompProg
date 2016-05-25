/*
	Idea; use projectile motion to tell if a given projectile
	will fall under a certain interval.
	References: 
	[1] https://br.answers.yahoo.com/question/index?qid=20080121134609AAmAM9e
	[2] https://en.wikipedia.org/wiki/Projectile_motion
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	double gravity = 9.80665, pi = 3.14159;
	double h, ho, alpha, v, voy, vx, rad, t_up, t_down, t_total, reach;
	int p1, p2, n;
	
	while(scanf("%lf", &ho) != EOF)
	{
		scanf("%d %d %d", &p1, &p2, &n);

		for(int i = 0; i < n; ++i)
		{
			scanf("%lf %lf", &alpha, &v);
			rad = (alpha * pi) / 180.0;
			voy = v * sin(rad);
			vx = v * cos(rad);
			
			h = ((voy * voy) + 2.0 * gravity * ho) / (2.0 * gravity);
			t_up = voy / gravity;
			t_down = sqrt((2 * h) / gravity);
			t_total = t_up + t_down;
			
			reach = vx * t_total;
			printf("%.5lf ", reach);
			printf(reach >= p1 && reach <= p2 ? "-> DUCK\n" : "-> NUCK\n");
		}
	}

	return 0;
}