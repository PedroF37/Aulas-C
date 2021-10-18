#include <stdio.h>
#include <stdlib.h>


/*


                                        Exercicio 14
                                        
                        Faça um programa que calcule a média de salários de uma empresa, pedindo ao usuário
                        a quantidade de funcionários e o salário de cada funcionário. Ao final, o programa deve
                        imprimir a média dos salários informados, o salário mais alto e o salário mais baixo.

*/

int main()
{
    int x, funcionarios;
    float salario, media, totalSalarios = 0 , maisAlto = 0, maisBaixo = 9999.99;
    

    printf("Quantos funcionários tem na empresa: ");
    scanf("%d", &funcionarios);
        
    
    for (x = 1; x <= funcionarios; x++)
    {
        printf("Digite o salário do funcionário #%d: ", x);
        scanf("%f", &salario);
        
        if (salario > maisAlto)
            maisAlto = salario;
        
        if (salario < maisBaixo)
            maisBaixo = salario;
        
        totalSalarios += salario;
    
    }
    
    media = totalSalarios / funcionarios;
    
    printf("A média salarial na empresa é de: R$%.2f\n", media);
    printf("O salário mais alto é: R$%.2f\n", maisAlto);
    printf("O salário mais baixo é: R$%.2f\n", maisBaixo);
    
    return(0);
}
