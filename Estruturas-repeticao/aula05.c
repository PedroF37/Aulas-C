#include <stdio.h>
#include <stdlib.h>


/*


                                                Aula 5
                                                
                                Estrutura de repetição do {} while (faça enquanto)

*/

int main()
{
    int valor;
    
    do
    {
        printf("Digite um valor maior que zero: ");
        scanf("%d", &valor);
    }
    while (valor <= 0);
    
    printf("Valor digitado foi: %d\n", valor);
}
