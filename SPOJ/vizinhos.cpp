#include <iostream>
#include <algorithm>
#define tamMax 5000
using namespace std;
 
struct vertice
{
    int grau;
    int indice;
};
vertice v[tamMax];
 
int compareVertice(const void *a, const void *b)
{
    struct vertice *ia = (struct vertice *)a;
    struct vertice *ib = (struct vertice *)b;
    return(ia->grau - ib->grau);
}
 
int compareIndiceVertice(const void *a, const void *b)
{
    struct vertice *ia = (struct vertice *)a;
    struct vertice *ib = (struct vertice *)b;
    return(ia->indice - ib->indice);
}
 
int main()
{
    char linha[tamMax];
    char s[tamMax];
    int n, p, aux = 0, indice = 0;
 
    scanf("%d", &n);
//    gets(s);
//    n = atoi(s);
    while(n--)
    {
//        gets(s);
//        p = atoi(s);
        scanf("%d", &p);
        for(int k = 0; k < p; k++)
        {
            getchar();
            scanf("%[^\n]", linha);
//            gets(linha);
            int i = 0;
            while(linha[i] != '\0')
            {
                if((int)linha[i] < 48){
                    aux++;
                }
                i++;
            }
            v[indice].grau = aux;
            v[indice].indice = indice + 1;
            indice++;
            aux = 0;
        }
 
        qsort(v, p, sizeof(struct vertice), compareVertice);
 
        aux = v[0].grau;
        int i = 1;
 
        while(v[i].grau == aux)
        {
            i++;
        }
 
        //qsort(v, i, sizeof(struct vertice), compareIndiceVertice);
 
        printf("%d", v[0].indice);
        for(int j = 1; j < i; j++)
            printf(" %d", v[j].indice);
 
        aux = 0;
        indice = 0;
        printf("\n");
    }
 
    return 0;
}