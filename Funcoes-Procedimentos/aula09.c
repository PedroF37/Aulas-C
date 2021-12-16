#include <stdio.h>
#include <stdlib.h>

/*


                                            Aula 9
                                            
                               Funções e procedimentos recursivos
                               Exemplo: imprimir todos os números de n até 0

*/

void imprimir(int x)
{
    if (x == 0)
        printf("%d ", x);
    else
    {
        //printf("%d ", x); - assim vai imprimir em ordem decrescente
        imprimir(x - 1);
        printf("%d ", x); // aqui imprime em ordem crescente
    }
}

int main()
{
    int n;
    
    printf("Digite um valor maior que zero: ");
    scanf("%d", &n);
    
    imprimir(n);
    printf("\n");
    
    
    return(0);
}
