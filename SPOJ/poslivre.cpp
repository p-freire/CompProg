#include <iostream>
#include <algorithm>
#include <string.h>
#define tamMax 510
using namespace std;
 
int matriz[tamMax][tamMax];
 
int main()
{
    int x1, y1, x2, y2, h, w, n;
    int area = 0;
    bool xIguais = false, yIguais = false;
 
    memset(matriz, 0, sizeof(matriz));
 
    scanf("%d %d %d", &w, &h, &n);
 
    while(w > 0 && h > 0)
    {
        area = w*h;
        while(n > 0)
        {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            if(x1 == x2)
                xIguais = true;
            if(y1 == y2)
                yIguais = true;
 
            if(xIguais && yIguais)
            {
                if(matriz[x1][y1] == 0)
                {
                    area--;
                    matriz[x1][y1] = 1;
                }
            }
            else if(xIguais && !yIguais)
            {
                for(int j = min(y1, y2); j <= max(y1, y2); j++)
                {
                    if(matriz[x1][j] == 0)
                    {
                        area--;
                        matriz[x1][j] = 1;
                    }
                }
            }
            else if(!xIguais && yIguais)
            {
                for(int i = min(x1, x2); i <= max(x1, x2); i++)
                {
                    if(matriz[i][y1] == 0)
                    {
                        area--;
                        matriz[i][y1] = 1;
                    }
                }
 
            }
            else
            {
                for(int i = min(x1, x2); i <= max(x1, x2); i++)
                    for(int j = min(y1, y2); j <= max(y1, y2); j++)
                    {
                        if(matriz[i][j] == 0)
                        {
                            area--;
                            matriz[i][j] = 1;
                        }
                    }
            }
            xIguais = yIguais = false;
            n--;
        }
        if(area == 0)
            printf("There is no empty spots.\n");
        else if(area == 1)
            printf("There is one empty spot.\n");
        else
            printf("There are %d empty spots.\n", area);
        area = 0;
        xIguais = yIguais = false;
        memset(matriz, 0, sizeof(matriz));
        scanf("%d %d %d", &w, &h, &n);
    }
    return 0;
}