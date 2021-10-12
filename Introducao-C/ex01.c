#include <stdio.h>
#include <stdlib.h>


/*


                                                Exercicio 1

                Elabore um algoritmo que receba, por meio do teclado, dois valores, um para a variável "a" e um
                para a variável "b". Em seguida, faça os passos que julgar necessário para que no final, a  variável
                "a" possua o valor que inicialmente estava em "b" e a variável "b" possua o valor que inicialmente
                estava em "a". Traduza seu algoritmo para a linguagem C e exiba os valores na tela. 
                
                temp = a;
                a = b;
                b = temp;

*/

int main()
{
    int a, b, temp;
    
    printf("Digite dois valores inteiros: ");
    scanf("%d%d", &a, &b);
    printf("\nValores iniciais: %d, %d\n", a, b);
    
    temp = a;
    a = b;
    b = temp;
    
    printf("\nValores depois de serem trocados: %d, %d\n", a, b);
    
    
    return(0);
}
