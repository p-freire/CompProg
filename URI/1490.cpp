#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
#define MAX_BOARD 110
#define MAX_ROWS_COLS 5010
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int graph[MAX_ROWS_COLS][MAX_ROWS_COLS];
std::vector<int> vertices[MAX_ROWS_COLS];
int matched[MAX_ROWS_COLS];
char board[MAX_BOARD][MAX_BOARD];
char row[MAX_BOARD];
int rows[MAX_BOARD][MAX_BOARD], cols[MAX_BOARD][MAX_BOARD];
int was_visited[MAX_ROWS_COLS];

using namespace std;


/*
    Checks for an existing augmented path
    Input: the vertex from where the search starts
    Output: false if there's no augmented path; true, otherwise
*/
bool is_there_augmented(int v, int max_size)
{
    std::vector<int>::iterator it;
    //for(int i = 0; i < vertices[v].size(); ++i)
    for(it = vertices[v].begin(); it != vertices[v].end(); ++it)
    {
        //if(graph[v][i] != 0 && !was_visited[i])
        if(!was_visited[*it])
        {
            was_visited[*it] = 1;
            if(matched[*it] == -1 || is_there_augmented(matched[*it], max_size))
            {
                matched[*it] = v;
                return true;
            }
        }
    }
    return false;
}

/*
    Finds the maximum matching
    Input: maximum number between number of rows and number of columns
    Output: maximum matching
*/
int max_match(int max_size)
{
    int max_num = 0;
    memset(matched, -1, sizeof(matched));
    for(int i = 0; i < max_size; ++i)
    {
        memset(was_visited, 0, sizeof(was_visited));
        if(is_there_augmented(i, max_size))
            ++max_num;
    }
    return max_num;
}

int main()
{
    int n;
    int num_rows, num_cols;
    while(scanf("%d", &n) != EOF)
    {
        memset(rows, -1, sizeof(rows));
        memset(cols, -1, sizeof(cols));
        num_rows = num_cols = 0;
        /* Get the board */
        for(int i = 0; i < n; ++i)
        {
            scanf("%s", row);
            for(int j = 0; j < n; ++j)
                board[i][j] = row[j];
        }

        /* Associate free rows with free columns */
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(board[i][j] == '.')
                {
                    if(j == 0 || rows[i][j - 1] == -1)
                        rows[i][j] = num_rows++;
                    else
                        rows[i][j] = rows[i][j - 1];

                    if(i == 0 || cols[i - 1][j] == -1)
                        cols[i][j] = num_cols++;
                    else
                        cols[i][j] = cols[i - 1][j];

                    //graph[ rows[i][j] ][ cols[i][j] ] = 1;
                    vertices[rows[i][j]].push_back(cols[i][j]);
                    //cout << "I = " << i << "  J = " << j << endl;
                    //cout << "Num_rows = " << num_rows << "  Num_cols = " << num_cols << endl << endl;
                }
            }
        }
        //cout << "Num rows = " << num_rows << endl;
        printf("%d\n", max_match(num_rows));
        //memset(graph, 0, sizeof(graph));
        for(int i = 0; i < num_rows; ++i)
            vertices[i].clear();
    }

    return 0;
}
