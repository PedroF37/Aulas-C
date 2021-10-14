#include <stdio.h>
#include <stdlib.h>

/*


                                                Aula 8
                                                
                                       Operador lógico de negação  !
                                       
                                       TABELA VERDADE:  x    !x
                                                        v     f
                                                        f     v

*/

int main()
{
     int a = 10;
    
    printf("\nDigite um valor qualquer: ");
    scanf("%d", &a);
    
    printf("Operador ternário:\n");
    !(a < 0) ? printf("\n\tValor negativo!\n") :     // se não colocar os parênteses, estamos a negar apenas a variável a e não a expressão toda.
        a > 0 ? printf("\n\tValor positivo!\n") : printf("\n\tValor igual a zero!\n");
    

        printf("\n\nif/else\n");
    if (!(a < 0))     // negamos o resultado da expressão e não do 'a'
        printf("\n\tValor negativo!\n");
    else
    {
        if (a > 0)
            printf("\n\tValor positivo!\n");
        else
            printf("\n\tValor igual a zero!\n");
    }
    
    printf("\nContinuação do programa...\n");

    
    
    return(0);
}
