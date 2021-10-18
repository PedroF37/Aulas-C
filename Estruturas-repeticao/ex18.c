#include <stdio.h>
#include <stdlib.h>

/*


                                            Exercicio 18
                                            
                      Foi feita uma pesquisa entre os habitantes de uma região e foram coletados os dados de idade,
                      sexo (M/F) e salário de X pessoas (x deve ser informado pelo usuário). Faça um algoritmo que
                      informe:
                      
                      a) a média de salário do grupo;
                      b) a maior e menor idade do grupo;
                      c) a quantidade de mulheres com salário até R$2000,00

*/

int main()
{
    int x, pessoas, idade, maiorIdade = 0, menorIdade = 200, quantMulher = 0;
    char sexo;
    float salario, mediaSalario, somaSalario = 0;
    
    printf("Informe o número de pessoas que participaram da pesquisa: ");
    scanf("%d", &pessoas);
    
    for (x = 1; x <= pessoas; x++)
    {
        printf("\nInforme o sexo (M/F), idade, e o salário da pessoa #%d: ", x);
        scanf(" %c%d%f", &sexo, &idade, &salario);
        
        // a) Media salarial
        somaSalario += salario;
        
        // b) Maior e menor idade
        if (idade > maiorIdade)
            maiorIdade = idade;
        
        if (idade < menorIdade)
            menorIdade = idade;
        
        // c) Mulheres com salário até 2000.00
        if ((sexo == 'f' || sexo == 'F') && (salario <= 2000.00))
            quantMulher++;
    }
    
    // a) Média salarial
    mediaSalario = somaSalario / pessoas;
    
    
    printf("\nA média salarial do grupo é: R$%.2f\n", mediaSalario);
    printf("\nA maior idade no grupo é: %d, e a menor idade é: %d\n", maiorIdade, menorIdade);
    printf("\nNo grupo tem %d mulheres com o salário até R$2000.00\n", quantMulher);
    
    return(0);
}
