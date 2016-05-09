#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <iostream>

using namespace std;

struct kid
{
    char name[35];
    int token;
};

std::list<kid> circle;
std::list<kid>::iterator it;
std::list<kid>::iterator it2;
int auxToken;

void moveCounterClockwise(int n)
{
    while(n > 0)
    {
        if(it == circle.begin())
        {
            it = circle.end();
            --it;
        }
        else
            --it;
        --n;
    }
}

void moveClockwise(int n)
{
    while(n > 0)
    {
        ++it;
        if(it == circle.end())
            it = circle.begin();
        --n;
    }
}

int main()
{
    int n; // number of kids
    kid aux;
    int circleSize;
    bool firstRound = true;
    while(scanf("%d", &n) && n != 0)
    {
        for(int i = 0; i < n; ++i)
        {
            scanf("%s %d", aux.name, &aux.token);
            circle.push_front(aux);
        }

        it = circle.end();
        --it;
        auxToken = it->token;
        while(circle.size() != 1)
        {
            if(firstRound)
            {
                firstRound = false;
                auxToken % 2 == 0 ? moveClockwise(auxToken % circle.size()) : moveCounterClockwise(auxToken % circle.size());
                auxToken = it->token;
                it = circle.erase(it);
            }
            else
            {
                /*
                    IMPORTANT: the -1 in (auxToken - 1) is due to the fact that when you erase an item from a list the iterator points to the next value.
                    Given that, if we're moving clockwise, this means the iterator is already counting one kid, and that's where the -1 comes from. If
                    we don't take that into account, we'll always count one more kid in the clockwise movement.
                */
                auxToken % 2 == 0 ? moveClockwise((auxToken - 1) % circle.size()) : moveCounterClockwise(auxToken % circle.size());
                auxToken = it->token;
                it = circle.erase(it);
            }
            if(it == circle.end())
                it = circle.begin();
        }
        cout << "Vencedor(a): " << circle.front().name << endl;
        circle.clear();
        firstRound = true;
    }
    return 0;
}
