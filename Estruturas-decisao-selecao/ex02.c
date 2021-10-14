#include <stdio.h>
#include <stdlib.h>


/*


                                                Exercicio 2
                                                
                       Escreva um programa em C que lê 5 números inteiros, um por vez. Conte quantos destes valores
                       são negativos e quantos são positivos. Ao final, imprima na tela a quantidade de números negativos
                       e positivos.

*/

int main()
{
    int num1, num2, num3, num4, num5, positivo = 0, negativo = 0;
    
    printf("Digite o primeiro valor inteiro: ");
    scanf("%d", &num1);
    
    (num1 < 0) ? negativo++ : positivo++;
    
    printf("Digite o segundo valor inteiro: ");
    scanf("%d", &num2);
    
    (num2 < 0) ? negativo++ : positivo++;
    
    printf("Digite o terceiro valor inteiro: ");
    scanf("%d", &num3);
    
    (num3 < 0) ? negativo++ : positivo++;
    
    printf("Digite o quarto valor inteiro: ");
    scanf("%d", &num4);
    
    (num4 < 0) ? negativo++ : positivo++;
    
    printf("Digite o quinto valor positivo: ");
    scanf("%d", &num5);
    
    (num5 < 0) ? negativo++ : positivo++;
    
    printf("\nDos cinco valores digitados, %d são positivos e %d são negativos.\n", positivo, negativo);
    
    /*
     
     Podia ter feito apenas:
     
     int num, positivo = 0, negativo = 0; e depois usava sempre a variável num
     Porque o valor não interessa, só interessa se é positivo ou negativo...
     
     printf("Digite o primeiro valor: ");
     scanf("%d", &num);
     
     (num < 0) ? negativo++ : positivo++;
     
     printf("Digite o segundo valor: ");
     scanf("%d", &num);
     
     (num < 0) ? negativo++ : positivo++;
     
     etc etc....
     
     */
    
    
    return(0);
}
