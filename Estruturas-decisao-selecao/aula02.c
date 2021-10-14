#include <stdio.h>
#include <stdlib.h>


/*


                                        Aula 2
                                        
                                    Decisão simples


*/

int main()
{
    int a = 10;
    
    printf("Digite um valor qualquer: ");
    scanf("%d", &a);
    
    if (a < 0)
    {
        printf("\n\tValor negativo.\n");    // Se só tiver uma instrução, como aqui, podemos usar o if sem as chaves {}
    }
    
    printf("\nContinuação do programa...\n");
    
    return(0);
}
