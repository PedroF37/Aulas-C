#include <stdio.h>
#include <stdlib.h>


/*


                                                    Exercicio 26
                                                    
                             Escreva um programa para lêr as notas da primeira e da segunda avaliação de um aluno.
                             Calcule e imprima a média semestral. O programa deverá aceitar apenas notas válidas no
                             intervalo [0, 10]. Cada nota deve ser validada separadamente. Ao final, deve ser impressa
                             a mensagem "novo calculo? (1-sim 2-não)", solicitando ao usuário que informe um código (1 ou 2)
                             indicando se ele deseja ou não executar o programa novamente. Se for informadoo código 1, deve ser
                             repetida a execução de todo o programa para permitir um novo cálculo, se for informado o código 2
                             o programa deve ser encerrado.

*/

int main()
{
    int escolha;
    float nota1, nota2, media;
    
    do
    {
        do
        {
            printf("Digite a primeira nota [0 - 10]: ");
            scanf("%f", &nota1);
        }
        while (nota1 < 0 || nota1 > 10);
        
        do
        {
            printf("Digite a segunda nota [0 - 10]: ");
            scanf("%f", &nota2);
        }
        while (nota2 < 0 || nota2 > 10);
        
        media = (nota1 + nota2) / 2;
        printf("\nA média semastral é de: %.2f\n", media);

        printf("\nNovo calculo?\n1 - sim\n2 - não\n");
        scanf("%d", &escolha);
        
    }
    while (escolha != 2);
    
    
    
    
    return(0);
}
