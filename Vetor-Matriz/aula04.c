#include <stdio.h>
#include <stdlib.h>


/*


                                            Aula 4

                                Como alterar o conteúdo de um vetor

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
    
    for (i = 0; i < 10; i++)
        num1[i] *= 3; // num[i] = num[i] * 3;
    

    
    printf("\n\n");

    for (i = 0; i < 10; i++)
        printf("%d ", num1[i]);
    printf("\n\n");
    
    return(0);
}
