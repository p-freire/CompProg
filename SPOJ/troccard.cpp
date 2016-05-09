#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <list>
 
using namespace std;
 
list<int> aliceCards;
list<int> bettyCards;
list<int>::iterator aliceIterator;
list<int>::iterator bettyIterator;
 
int main()
{
    int a, b; // number of Alice's cards, number of Betty's cards
    int maxNumOfExchanges;
    int aux;
    while(scanf("%d %d", &a, &b) && a != 0 && b != 0)
    {
        scanf("%d", &aux);
        aliceCards.push_back(aux);
        for(int i = 1; i < a; ++i)
        {
            scanf("%d", &aux);
            if(aux != aliceCards.back())
                aliceCards.push_back(aux);
        }
 
        scanf("%d", &aux);
        bettyCards.push_back(aux);
        for(int i = 1; i < b; ++i)
        {
            scanf("%d", &aux);
            if(aux != bettyCards.back())
                bettyCards.push_back(aux);
        }
 
        aliceIterator = aliceCards.begin();
        bettyIterator = bettyCards.begin();
        while(aliceIterator != aliceCards.end() || bettyIterator != bettyCards.end())
        {
            if(*aliceIterator == *bettyIterator)
            {
                aliceIterator = aliceCards.erase(aliceIterator);
                bettyIterator = bettyCards.erase(bettyIterator);
            }
            else if(*aliceIterator < *bettyIterator)
                ++aliceIterator;
            else if( *bettyIterator < *aliceIterator)
                ++bettyIterator;
        }
 
        aliceCards.size() > bettyCards.size() ? maxNumOfExchanges = bettyCards.size() : maxNumOfExchanges = aliceCards.size();
 
        cout << maxNumOfExchanges << endl;
        aliceCards.clear();
        bettyCards.clear();
 
    }
    return 0;
}