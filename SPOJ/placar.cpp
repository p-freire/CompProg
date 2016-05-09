#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
 
struct aluno
{
    char nome[21];
    int qtdeProbRes;
};
 
struct nomes
{
    char nome[21];
};
 
int compare (const void *a, const void *b)
{
    //return strcmp( *(char*)a->nome, *(char*)b->nome );
    struct nomes *ia = (struct nomes *)a;
    struct nomes *ib = (struct nomes *)b;
    return strcmp(ia->nome, ib->nome);
}
 
int main()
{
    int instancia = 1;
    while(!feof(stdin))
    {
        int qtdeInst;
        bool deuProblema = false;
        cin>>qtdeInst;
 
        if(feof(stdin)) break;
 
        if(qtdeInst > 0 && qtdeInst <= 100)
        {
            aluno vetor[qtdeInst];
 
            for (int i = 0; i < qtdeInst; i++)
            {
                cin>>vetor[i].nome>>vetor[i].qtdeProbRes;
                if(vetor[i].qtdeProbRes < 0 || vetor[i].qtdeProbRes > 10)
                    deuProblema = true;
            }
 
            if(!deuProblema)
            {
                int i, j, key;
                char temp[21];
                for (j = 1; j < qtdeInst; j++)
                {
                    key = vetor[j].qtdeProbRes;
                    strcpy(temp, vetor[j].nome);
                    i = j - 1;
                    while (i >= 0 && vetor[i].qtdeProbRes > key)
                    {
                        vetor[i+1].qtdeProbRes = vetor[i].qtdeProbRes;
                        strcpy(vetor[i+1].nome, vetor[i].nome);//vetor[i+1].nome = vetor[i].nome;
                        i = i -1;
                    }
                    vetor[i+1].qtdeProbRes = key;
                    strcpy(vetor[i+1].nome, temp);//vetor[i + 1].nome = *temp;
                }
 
                i = 0;
                int contador = 0;
                char final[21];
 
                while(vetor[i].qtdeProbRes == vetor[i+1].qtdeProbRes && (i < qtdeInst - 1))
                {
                    i++;
                }
                contador = i + 1;
 
                nomes reprovados[contador];
                for(int i = 0; i < contador; i++)
                    strcpy(reprovados[i].nome, vetor[i].nome);
 
                size_t tamanhoDoStruct = sizeof(reprovados)/sizeof(struct nomes);
 
                qsort(reprovados, tamanhoDoStruct, sizeof(struct nomes), compare);
 
                cout<<"Instancia "<<instancia<<endl<<reprovados[contador-1].nome<<endl<<endl;
                //instancia++;
            }
            instancia++;
        }
    }
 
    return 0;
}