#include <stdio.h>
#include <stdlib.h>

/*


                                        Exercicio 5
                                        
                       Faça um programa que receba a temperatura média de cada mês do ano, armazenando-as em um
                       vetor. Ao final, mostre a maior e a menor temperatura do ano e em que mês ocorreram (mostrar
                       o mês por extenso: janeiro, fevereiro...). Desconsidere empates.
                       

*/

int main()
{
    int i, mesMaior, mesMenor;
    float temperatura, temperaturas[12], maior, menor;
    
    for (i = 0; i < 12; i++)
    {
        printf("Digite a temperatura média do mês #%d: ", i + 1);
        scanf("%f", &temperatura);
        
        temperaturas[i] = temperatura;
    }
    
    maior = temperaturas[0];
    menor = temperaturas[0];
    
    for (i = 0; i < 12; i++)
    {
        if (temperaturas[i] > maior)
        {
            maior = temperaturas[i];
            mesMaior = i;
        }
        if (temperaturas[i] < menor)
        {
            menor = temperaturas[i];
            mesMenor = i;
        }
    }
    
    /*
    for (i = 0; i < 12; i++)
    {
        if (maior == temperaturas[i])
            mesMaior = i;
        if (menor == temperaturas[i])
            mesMenor = i;
    }
    */
    
    printf("A maior temperatura média foi %.2f e ocorreu no mês ", maior);
    
    switch (mesMaior)
    {
        case 0:
            printf("Janeiro\n");
            break;
        case 1:
            printf("Fevereiro\n");
            break;
        case 2:
            printf("Março\n");
            break;
        case 3:
            printf("Abril\n");
            break;
        case 4:
            printf("Maio\n");
            break;
        case 5:
            printf("Junho\n");
            break;
        case 6:
            printf("Julho\n");
            break;
        case 7:
            printf("Agosto\n");
            break;
        case 8:
            printf("Setembro\n");
            break;
        case 9:
            printf("Outubro\n");
            break;
        case 10:
            printf("Novembro");
            break;
        case 11:
            printf("Dezembro\n");
            break;
            
    }
    
    printf("\nA menor temperatura média foi %.2f e ocorreu no mês ", menor);

    switch (mesMenor)
    {
        case 0:
            printf("Janeiro\n");
            break;
        case 1:
            printf("Fevereiro\n");
            break;
        case 2:
            printf("Março\n");
            break;
        case 3:
            printf("Abril\n");
            break;
        case 4:
            printf("Maio\n");
            break;
        case 5:
            printf("Junho\n");
            break;
        case 6:
            printf("Julho\n");
            break;
        case 7:
            printf("Agosto\n");
            break;
        case 8:
            printf("Setembro\n");
            break;
        case 9:
            printf("Outubro\n");
            break;
        case 10:
            printf("Novembro");
            break;
        case 11:
            printf("Dezembro\n");
            break;
    }
    

    return(0);
}
