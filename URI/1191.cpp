#include <assert.h> //para monitorar os limites
#include <string.h> //memset
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define tamMax 60
using namespace std;

char preOrdem[tamMax], emOrdem[tamMax];
int mapaIndices[52];

/*
    Pré-ordem -> raiz, sub-árvore da esquerda, sub-árvore da direita
    Em-ordem -> sub-árvore da esquerda, raiz, sub-árvore da direita
    Pós-ordem -> sub-árvore da esquerda, sub-árvore da direita, raiz
*/

struct  node
{
    char vertice;
    bool jaFoiVisitado;
    struct node *esq;
    struct node *dir;
};

void mapeiaIndices(char *emOrdem, int tamanho)
{
    for(int i = 0; i < tamanho; i++)
    {
//        assert(0 <= (int)emOrdem[i]-65 && (int)emOrdem[i]-65 <= tamanho);
        mapaIndices[(int)emOrdem[i]-65] = i;
    }
}

node *constroiArvore(char *preOrdem, char *emOrdem, int tamanho, int offset)
{
    assert(tamanho >= 0);
    if(tamanho == 0)
        return NULL;
    char raiz = preOrdem[0];
    int i = mapaIndices[(int)raiz - 65] - offset;
    //cout<<"Raiz = "<<raiz<<endl<<"i = "<<i<<endl<<"Tamanho = "<<tamanho<<endl<<"Tamanho - i - 1 = "<<tamanho-i-1<<endl<<endl;
    node *root = new node;
    root->vertice = raiz;
    root->esq = constroiArvore(preOrdem + 1, emOrdem, i, offset);
    root->dir = constroiArvore(preOrdem + i + 1, emOrdem + i + 1, tamanho - i - 1, offset + i + 1);
    return root;

}

void posOrdem(node *r)
{
    if(!r) return;
    posOrdem(r->esq);
    posOrdem(r->dir);
    printf("%c", r->vertice);
}

void printPreOrdem(node *r)
{
    if(!r) return;
    printf("%c", r->vertice);
    printPreOrdem(r->esq);
    printPreOrdem(r->dir);
}

void printEmOrdem(node *r)
{
    if(!r) return;
    printEmOrdem(r->esq);
    printf("%c", r->vertice);
    printEmOrdem(r->dir);
}

int main()
{
    int n;
    memset(preOrdem, '\0', sizeof(preOrdem));
    memset(emOrdem, '\0', sizeof(emOrdem));
    memset(mapaIndices, 0, sizeof(mapaIndices));
    while(scanf("%s %s", preOrdem, emOrdem) != EOF)
    {
        n = strlen(preOrdem);
        //scanf("%d %s %s", &n, preOrdem, emOrdem);
        mapeiaIndices(emOrdem, n);
        node *raiz = constroiArvore(preOrdem, emOrdem, n, 0);
        posOrdem(raiz);
        printf("\n");
        memset(mapaIndices, 0, sizeof(mapaIndices));
    }
    return 0;
}
