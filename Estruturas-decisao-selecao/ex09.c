#include <stdio.h>
#include <stdlib.h>

/*


                                            Exercicio 9
                                            
                           Um usuário deseja um programa onde possa escolher  que tipo de média deseja calcular a partir
                           de três notas. Faça um programa que leia as notas e o tipo da média escolhida pelo usuário e
                           calcule e apresente a média:
                           Opções:
                           
                           * 'a' - Aritmética
                           * 'p' - Ponderada (pesos: 3, 3, 4)

*/

int main()
{
    char escolha;
    float nota1, nota2, nota3, media;
    
    printf("Digite as três notas: ");
    scanf("%f%f%f", &nota1, &nota2, &nota3);
    
    printf("a) - Média aritmética\np) - Média Ponderada\n");
    scanf(" %c", &escolha);     // como leio o caractere no fim, tenho que por o espaço antes do " %c", para descartar o "\n" depois da ultima nota.
                                // nota1\nnota2\nnota3\n - > o espaço vai ignorar este último \n e o programa coloca enão o caractere (a ou p) em &escolha.
    switch (escolha)
    {
        case 'a':
        case 'A':
            media = (nota1 + nota2 + nota3) / 3;
            printf("\nA média aritmética deu: %.2f\n", media);
            break;
        case 'p':
        case 'P':
            media = (nota1 * 3) + (nota2 * 3) + (nota3 * 4) / 10;
            printf("\nMédia ponderada deu: %.2f\n", media);
            break;
        default:
            printf("\nOpção inválida!\n");
    }
    
   return(0);
}
