#include <iostream>
#include <string.h>
 
using namespace std;
 
int main()
{
    char tel[31];
    //char num[31];
 
    while(scanf("%s", tel) != EOF)
    {
        for(int i = 0; i < strlen(tel); i++)
        {
            if(tel[i] == 'A' || tel[i] == 'B' || tel[i] == 'C')
                printf("2");
            else if(tel[i] == 'D' || tel[i] == 'E' || tel[i] == 'F')
                printf("3");
            else if(tel[i] == 'G' || tel[i] == 'H' || tel[i] == 'I')
                printf("4");
            else if(tel[i] == 'J' || tel[i] == 'K' || tel[i] == 'L')
                printf("5");
            else if(tel[i] == 'M' || tel[i] == 'N' || tel[i] == 'O')
                printf("6");
            else if(tel[i] == 'P' || tel[i] == 'Q' || tel[i] == 'R'|| tel[i] == 'S')
                printf("7");
            else if(tel[i] == 'T' || tel[i] == 'U' || tel[i] == 'V')
                printf("8");
            else if(tel[i] == 'W' || tel[i] == 'X' || tel[i] == 'Y' || tel[i] == 'Z')
                printf("9");
            else if(tel[i] == '1')
                printf("1");
            else if(tel[i] == '0')
                printf("0");
            else if(tel[i] == '-')
                printf("-");
        }
        printf("\n");
        gets(tel);
    }
    return 0;
}