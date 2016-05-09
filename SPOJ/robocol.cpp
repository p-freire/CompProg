#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#define ARENA_SIZE 110
#define MAX_INST 50010
using namespace std;
 
char arena[ARENA_SIZE][ARENA_SIZE];
char row[ARENA_SIZE];
char robotInstructions[MAX_INST];
char robotOrientation;
int robotPosition_x;
int robotPosition_y;
int numOfStickers;
int n, m, s; // number of arena rows, number of arena columns, number of instructions
 
/*
    NOTE: in this program, the robot coordinates (X,Y) are calculated taking into account the rows and columns, which
          is the opposite from the X-Y axis. I mean, in this case X is the equivalent to Y and Y is the equivalent to X.
*/
 
void moveNorth(int &r_x, int &r_y)
{
    if(r_x - 1 >= 0 && arena[r_x - 1][r_y] != '#')
        --r_x;
}
 
void moveSouth(int &r_x, int &r_y)
{
    if(r_x + 1 <= n - 1  && arena[r_x + 1][r_y] != '#')
        ++r_x;
}
 
void moveEast(int &r_x, int &r_y)
{
    if(r_y + 1 <= m - 1  && arena[r_x][r_y + 1] != '#')
        ++r_y;
}
 
void moveWest(int &r_x, int &r_y)
{
    if(r_y - 1 >= 0  && arena[r_x][r_y - 1] != '#')
        --r_y;
}
 
 
void moveRobot(char c, int &r_x, int &r_y)
{
    switch(c)
    {
    case('N'):
        moveNorth(r_x, r_y);
        break;
    case('S'):
        moveSouth(r_x, r_y);
        break;
    case('L'):
        moveEast(r_x, r_y);
        break;
    case('O'):
        moveWest(r_x, r_y);
        break;
    }
}
 
void spinRobot(char c)
{
    if(c == 'D')
    {
        switch(robotOrientation)
        {
        case('N'):
            robotOrientation = 'L';
            break;
        case('L'):
            robotOrientation = 'S';
            break;
        case('S'):
            robotOrientation = 'O';
            break;
        case('O'):
            robotOrientation = 'N';
            break;
        }
    }
    else
    {
        switch(robotOrientation)
        {
        case('N'):
            robotOrientation = 'O';
            break;
        case('L'):
            robotOrientation = 'N';
            break;
        case('S'):
            robotOrientation = 'L';
            break;
        case('O'):
            robotOrientation = 'S';
            break;
        }
    }
}
 
int main()
{
    while(scanf("%d %d %d", &n, &m, &s) && n > 0)
    {
        memset(arena, '\0', sizeof(arena));
        memset(row, '\0', sizeof(row));
        numOfStickers = 0;
        for(int i = 0; i < n; ++i)
        {
            scanf("%s", row);
            for(int j = 0; j < m; ++j)
            {
                arena[i][j] = row[j];
                if(arena[i][j] == 'N' || arena[i][j] == 'S' || arena[i][j] == 'L' || arena[i][j] == 'O')
                {
                    robotOrientation = arena[i][j];
                    robotPosition_x = i;
                    robotPosition_y = j;
                }
            }
        }
        scanf("%s", robotInstructions);
        for(int i = 0; robotInstructions[i] != '\0'; ++i)
        {
            if(robotInstructions[i] == 'F')
            {
                moveRobot(robotOrientation, robotPosition_x, robotPosition_y);
                if(arena[robotPosition_x][robotPosition_y] == '*')
                {
                    ++numOfStickers;
                    arena[robotPosition_x][robotPosition_y] = '.';
                }
            }
            else
                spinRobot(robotInstructions[i]);
        }
        printf("%d\n", numOfStickers);
    }
    return 0;
}