#include <stdio.h>
#include <stdlib.h>


/*


                                        Exercicio 13
                                        
                       Faça um programa que peça ao usuário um número inteiro maior que 1
                       e diga se o número informado é primo ou não.
                       
                       Número primo -> divisivel por 1 e ele mesmo.
                       Número 2 é o único número primo par
                       
*/

int main()
{
    int x, num, divisivel = 0;
    
    do
    {
        printf("Digite um valor inteiro maior do que 1: ");
        scanf("%d", &num);
    }
    while (num <= 1);
    
    for (x = 2; x < num / 2; x += 3)
    {
        if (num % x == 0)
            divisivel += 1;
    }
    
    /*
    
     Número primo é divisivél por ele mesmo e por 1 apenas.
     Tirando o 2, todos os números primos são ímpares.
     A conta aqui é se divisivel for maior que 0, porque todos os números, sendo primos ou não
     são já divisiveis por 1 e por eles mesmos , ou seja, eu começo o loop em 2 porque todo o numero é divisivel por 1.
     Da mesma forma o loop dura enquanto num for menor que ele mesmo dividido por 2 (metade), e não menor ou igual, porque todo o número é divisivel por ele mesmo,
     e se até á metade do número não tiver divisor, depois da metade já não vai ter. Assim faz metade do loop.
     Então, dentro do loop, qualquer número que seja divisivel por outro número, na verdade está sendo divisivel por esse numero, mais por 1 e por ele mesmo.
     Logo se divisivel for maior que zero, o número não é primo.
    
    */
    if (divisivel > 0)
        printf("\nNão é primo\n");
    else
        printf("\nÉ primo\n");
    
    return(0);
}
