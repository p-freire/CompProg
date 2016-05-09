#include <iostream>
#include <string.h>
#define maxSaida 2000001
using namespace std;
 
char entrada[maxSaida];
char resultado[maxSaida];
 
int main()
{
    int contaRepeticoes = 1;
    int contaCasas = 0;
    int temp = 0;
    int i = 0;
    int j = 0;
    int n, instancia;
 
    for(int i = 0; i < maxSaida; i++)
    {
        resultado[i] = '\0';
        entrada[i] = '\0';
    }
 
    scanf("%d", &instancia);
 
    while(instancia > 0)
    {
        scanf("%s", entrada);
        scanf("%d", &n);
        printf("%s\n", entrada);
        while(n > 0)
        {
            while(entrada[i] != '\0')
            {
                //Conta repetiÃ§Ãµes
                while(entrada[i] == entrada[i+1])
                {
                    contaRepeticoes++;
                    i++;
                }
 
                //Conta quantas casas do vetor deverÃ£o ser "reservadas" para a contagem de repetiÃ§Ãµes (i.e., 0-9 => 1 casa; 10-99 => duas casas; 100-999 => trÃªs casas ...)
                temp = contaRepeticoes;
                while(temp > 0)
                {
                    contaCasas++;
                    temp = temp / 10;
                }
 
                j += contaCasas;
                contaCasas = 1;
 
                //Insere no vetor a quantidade de repetiÃ§Ãµes encontradas para o nÃºmero sendo analisado
                //Note que os valores sÃ£o colocados de trÃ¡s pra frente, para tratar o caso em que hÃ¡ mais de dez repetiÃ§Ãµes, logo, mais de uma posiÃ§Ã£o serÃ¡ necessÃ¡ria
                while(contaRepeticoes > 0)
                {
                    resultado[j - contaCasas] = (contaRepeticoes % 10) + 48;
                    contaRepeticoes = contaRepeticoes / 10;
                    contaCasas++;
                }
 
                resultado[j] = entrada[i];
                contaRepeticoes = 1;
                contaCasas = 0;
                j++;
                i++;
            }
            i = j = 0;
            strcpy(entrada, resultado); //Copia a string para a entrada para dar continuidade na sequÃªncia
            printf("%s\n", entrada); //Exibe o resultado
            n--;
        }
 
        for(int i = 0; i < maxSaida; i++)
        {
            resultado[i] = '\0';
            entrada[i] = '\0';
        }
        instancia--;
    }
 
    return 0;
}