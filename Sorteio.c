// Script recebe uma aposta do usuario, ele escolhendo uma quantidade de numeros de 1 a 20
// Em seguida recebe os numeros que o usuario deseja aposta
// Com a funçao rand() faz um sorteio de 20 numeros
// Apos o sorteio compara os numeros apostados com os numero sorteados e exibe o resultado

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ler_aposta (int *aposta,int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("Aposta %d: ",i+1);
        scanf("%d",&aposta[i]);
    }
}


void sorteia_valores (int *sorteio,int n)
{

    srand(time(NULL));
    int i=0,igual;;
    do
    {
        sorteio[i] = rand()%100;
        igual = 0;
        for (int j = 0; j < i; j++)
        {
            if (sorteio[i] == sorteio[j])
            {
                igual = 1;
            }
            
        }
        if (igual == 0)
        {
            i++;
        }
        
    } while (i<20);

}


int compara_aposta (int *aposta, int *sorteio,int *val_certos,int na, int ns)
{
    int cont=0;
    for (int i = 0; i < na; i++)
    {
        for (int j = 0 ; j < ns; j++)
        {
            if (aposta[i]==sorteio[j])
            {
                val_certos[cont] = aposta[i];
                cont = cont + 1; 

            }
            
        }
        
    }
    return (cont);
}



int main()
{
    int quant;
    printf("Quantidade de numeros que deseja apostar | [1-20]: ");
    scanf("%d",&quant);

    int *num_escolhidos;

    num_escolhidos = (int*)malloc(quant * sizeof(int));
    ler_aposta(num_escolhidos,quant);

    int *sorteio;

    sorteio = (int *)malloc(20*sizeof(int));
    sorteia_valores(sorteio,20);

    printf("\nNumeros soteados: ");
    for (int i = 0; i < 20; i++)
    {
        printf("%d ",sorteio[i]);
    }
    printf("\n");

    int *acertos; 
    int  n = 20,quantidade; 
    acertos = (int*)malloc(quant * sizeof(int));
    quantidade = compara_aposta(num_escolhidos,sorteio,acertos,quant,n);

 
    printf("\nQuantidade de numeros acertados: %d\n",quantidade);


    if (quantidade != 0)
    {
        printf("Numero acertados: ");
        for (int i = 0; i < quantidade; i++)
        {
            printf("%d ",acertos[i]);
        }        
    }
    else
        printf("Voce nao acertou nenhum numero.");


    return 0;
}
