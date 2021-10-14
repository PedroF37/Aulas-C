#include <stdio.h>
#include <stdlib.h>

/*


                                    Exercicio 10
                                    
                       Faça um programa que, dados três valores a, b e c, verifique se eles podem ser os
                       comprimentos de um triângulo. Caso positivo, seu programa deve informar também se
                       o triângulo é equilátero, isósceles ou escaleno. Caso contrário, seu programa deve escrever
                       a mensagem "Não formam um triângulo".
                       
                       Condição de existência ->  cada um dos lados, tem que ser menor que a soma dos outros dois. OU, basta 
                                                  o lado maior ser menor que a soma dos outros dois.
                       
                       Qual tipo?
                       
                       equilátero -> três lados iguais
                       isósceles -> dois lados iguais. Não é dois lados iguais e um diferente, é somente dois lados iguais!! (eqilátero é equilátero e isosceles..)
                       escaleno -> três lados diferentes
                       
                       Logo o certo é:
                       
                       se todos os lados forem iguais:
                            equilátero
                       se dois lados forem iguais:
                            isosceles
                       se os três lados forem diferntes:
                            escaleno

*/

int main()
{
   int a, b, c;
    
    printf("Digite três valores inteiros para vêr se podem formar um triângulo: ");
    scanf("%d%d%d", &a, &b, &c);
    
    if ((a < b + c) && (b < a + c) && (c < a + b))
    {
        printf("\nFormam um triângulo.\n");
        
        if (a == b && b == c)
            printf("\nÉ um triângulo equilátero.\n");
        
        else if (a == b || a == c || b == c) 
            printf("\nÉ um triângulo isosceles\n");
        else
            printf("\nÉ um triângulo escaleno.\n");
    }
    else
        printf("\nNão formam um triângulo.\n");
    
    return(0);
}
