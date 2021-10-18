#include <stdio.h>
#include <stdlib.h>


/*


                                                Aula 5
                                                
                                  Estrutura de repetição while (enquanto)

*/

int main()
{
    int valor;
    
    printf("Digite um valor maior que zero: ");
    scanf("%d", &valor);
    
    while (valor <= 0)
    {
        printf("Valor inválido!\n");
        printf("Digite um valor maior que zero: ");
        scanf("%d", &valor);
    }
    
    printf("\nO valor digitado foi: %d\n", valor);
    
    return(0);
}
