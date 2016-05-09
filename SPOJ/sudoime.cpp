#include <iostream>
 
using namespace std;
 
int main()
{
    int multLinha = 1;
    int multColuna = 1;
    int multMatrizMenor = 1;
    int somaLinha = 0;
    int somaColuna = 0;
    int somaMatrizMenor = 0;
    int sudoku[9][9];
    int i, j, k, l, instancia, n;
    instancia = 1;
    bool erro = false;
 
//    FILE *arquivo =fopen("teste.txt", "r");
//    assert(arquivo != NULL);
//    fscanf(arquivo, "%d", &n);
 
    scanf("%d", &n);
 
//    while(scanf("%d", &n) != EOF)
//    {
        while(n > 0)
        {
            for(i = 0; i < 9; i++)
            {
                for(j = 0; j < 9; j++)
                {
                   cin>>sudoku[i][j];//fscanf(arquivo, "%d", &sudoku[i][j]);
                    if(sudoku[i][j] < 1 || sudoku[i][j] > 9)
                    {
                        erro = true;
                        printf("Instancia %d\nNAO\n\n", instancia);
                        break;
                    }
                }
                if(erro)
                    break;
            }
 
            if(!erro)
            {
                for(i = 0; i < 9; i++)
                {
                    for(j = 0; j < 9; j++)
                    {
                        multLinha *= sudoku[i][j];
                        multColuna *= sudoku[j][i];
                        somaLinha += sudoku[i][j];
                        somaColuna += sudoku[j][i];
                    }
                    if(multLinha != 362880 || multColuna != 362880 || somaLinha != 45 || somaColuna != 45)
                    {
                        erro = true;
                        printf("Instancia %d\nNAO\n\n", instancia);
                        break;
                    }
                    multLinha = 1;
                    multColuna = 1;
                    somaLinha = 0;
                    somaColuna = 0;
                }
 
                if(!erro)
                {
                    for(i = 0; i < 9; i += 3)
                    {
                        for(j = 0; j < 9; j += 3)
                        {
                            for(k = i; k < i+3; k++)
                            {
                                for(l = j; l < j+3; l++)
                                {
                                    multMatrizMenor *= sudoku[k][l];
                                    somaMatrizMenor += sudoku[k][l];
                                }
                            }
                            if(multMatrizMenor != 362880 || somaMatrizMenor != 45)
                            {
                                erro = true;
                                printf("Instancia %d\nNAO\n\n", instancia);
                                break;
                            }
                            multMatrizMenor = 1;
                            somaMatrizMenor = 0;
                        }
                        if(erro)
                            break;
                    }
                }
            }
 
            if(!erro)
                printf("Instancia %d\nSIM\n\n", instancia);
            instancia++;
            erro = false;
            n--;
            somaColuna = somaLinha = somaMatrizMenor = 0;
            multColuna = multLinha = multMatrizMenor = 1;
        }
//        instancia = 1;
//    }
    //fclose(arquivo);
    return 0;
}