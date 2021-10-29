#include <stdio.h>
#include <stdlib.h>


/*


                                            Aula 3

                                Como preencher um vetor por meio do teclado

*/

int main()
{
    int i;
    int num1[10];
    
    for (i = 0; i < 10; i++)
    {
        printf("Digite o elemento da posição #%d: ", i + 1);
        scanf("%d", &num1[i]);
    }
    
    printf("\n\n");
    for (i = 0; i < 10; i++)
        printf("%d ", num1[i]);
    printf("\n\n");
    
    return(0);
}
