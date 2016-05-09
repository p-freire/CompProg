#include <iostream>
using namespace std;
 
//int compare (const void *a, const void *b)
//{
//    if(*(int*)a < 0 && *(int*)b < 0){
//        //return (*(int*)a + *(int*)b);
//        if(*(int*)a > *(int*)b)
//            return -1;
//        else if (*(int*)a < *(int*)b)
//            return 1;
//        else
//            return 0;
//    }
//    else
//        return (*(int*)a - *(int*)b);
//}
 
int main()
{
    int tamanho, soma;
    int *vetor;
    int instancia = 1;
    bool achou;
//    cin>>tamanho;
//    vetor = new int[tamanho];
//
//    for(int i = 0; i < tamanho; i++){
//        cout<<"Valor "<<i<<endl;
//        cin>>vetor[i];
//    }
//
//    qsort(vetor, tamanho, sizeof(int), compare); //ordena
//
//    for(int i = 0; i < tamanho; i++)
//        printf("%d ", vetor[i]);
//
//    delete []vetor;
 
    while(scanf("%d", &tamanho) != EOF)
    {
        vetor = new int[tamanho];
 
        for(int i = 0; i < tamanho; i++)
            cin>>vetor[i]; //lÃª os valores
 
        //qsort(vetor, tamanho, sizeof(int), compare); //ordena
 
        soma = vetor[0];
        achou = false;
 
        for(int i = 1; i < tamanho; i++)
        {
            if(soma == vetor[i])
            {
                printf("Instancia %d\n%d\n\n", instancia, vetor[i]);
                ++instancia;
                achou = true;
                break;
            }
            else
                soma += vetor[i];
        }
 
        if(tamanho == 1)
        {
            printf("Instancia %d\n%d\n\n", instancia, vetor[0]);
            ++instancia;
            achou = true;
        }
        else if(!achou)
        {
            printf("Instancia %d\nnao achei\n\n", instancia);
            ++instancia;
        }
         delete []vetor;
    }
 
    return 0;
}