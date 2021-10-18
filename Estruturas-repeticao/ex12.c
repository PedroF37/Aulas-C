#include <stdio.h>
#include <stdlib.h>


/*


                                            Exercicio 12
                                            
                         Para uma turma de 45 alunos, construa um algoritmo que determine:
                         a) A idade média dos alunos com menos de 1.70m de altura;
                         b) A altura média dos alunos com mais de 20 anos.


*/

int main()
{
    int x, idade, alturaBaixa = 0, contIdade = 0, idadeMaior = 0;
    float idadeMedia, alturaMedia, altura, contAltura = 0;
    
    for (x = 1; x <= 45; x++)
    {
        printf("Digite a idade e altura em metros do aluno #%d: ", x);
        scanf("%d%f", &idade, &altura);
        
        // Problema a -> idade média
        if (altura < 1.70)
        {
            contIdade += idade;
            alturaBaixa += 1;
            
        }
        
        // Probema b -> altura média
        if (idade > 20)
        {
            contAltura += altura;
            idadeMaior += 1;
        }
    }
    
    idadeMedia = (float)contIdade / alturaBaixa;
    alturaMedia = contAltura / idadeMaior;
    
    printf("\nA idade média dos alunos com menos de 1.70m de altura é: %.2f\n", idadeMedia);
    printf("\nA altura média dos alunos com mais de 20 anos é: %.2f\n", alturaMedia);
    
    
    return(0);
}
