#include <stdio.h>
#include <stdlib.h>


/*


                                            Exercicio 5
                                            
                             Faça um programa que leia as notas referentes às duas avaliações de um aluno.
                             Calcule e imprima a média semestral. Faça com que o programa só aceite notas válidas
                             (uma nota válida deve pertencer entre o intervalo de 0 a 10), Cada nota deve ser validada
                             separadamente.

*/

int main()
{
    float nota1, nota2, media;
    
    //Nota1:
    
    do
    {
        printf("Digite a primeira nota (0 - 10): ");
        scanf("%f", &nota1);
    }
    while (nota1 < 0.0 || nota1 > 10.0);
    
    // Nota2:
    do
    {
        printf("\nDigite a segunda nota (0 - 10): ");
        scanf("%f", &nota2);
    }
    while (nota2 < 0.0 || nota2 > 10.0);
    
    media = (nota1 + nota2) / 2;
    
    printf("\nA média semestral é: %.2f\n", media);
    
    
    
    return(0);
}
