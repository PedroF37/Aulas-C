#include <stdio.h>
#include <stdlib.h>

/*


                                                Aula 11
                                                
                              Fazer uma função que calcula o enésimo termo da sequência de fibonacci

*/

int fibonacci(int termo)
{
    if (termo == 1)
        return(0);
    else if (termo == 2)
        return(1);
    else
        return(fibonacci(termo - 1) + fibonacci(termo - 2));
}

int main()
{
    int termo;
    
    printf("Digite um valor maior do que zero: ");
    scanf("%d", &termo);
    
    printf("O %dº termo da sequência de fibonacci é %d.\n", termo, fibonacci(termo));
    
    return(0);
}
