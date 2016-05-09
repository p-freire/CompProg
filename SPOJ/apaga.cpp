#include <stdio.h>
#include <stdlib.h>
#include <deque>
#include <iostream>
#define MAX 100100
 
char number[MAX];
std::deque<char> finalNumber;
std::deque<char>::iterator it;
 
int main()
{
    int n, d, numberSize;
    while(1)
    {
        scanf("%d %d", &n, &d);
        if(n == 0)
            break;
        numberSize = n - d;
        scanf("%s", number);
        for(int i = 0; i < n; ++i)
        {
            while(!finalNumber.empty() && number[i] > finalNumber.back() && d > 0)
            {
                finalNumber.pop_back();
                --d;
            }
            if(finalNumber.size() < numberSize)
                finalNumber.push_back(number[i]);
        }
        for(it = finalNumber.begin(); it != finalNumber.end(); ++it)
            std::cout << *it;
        std::cout << std::endl;
        finalNumber.clear();
    }
    return 0;
}
 