#include <stdio.h>
#include <stdlib.h>


/*


                                            Aula 9
                                            
                                      Operador lógico e (&&)
                                      TABELA VERDADE:   a    b    a && b
                                                        V    V      V
                                                        V    F      F
                                                        F    V      F
                                                        F    F      F

*/

int main()
{
    int idade;
    char sexo;
    
    printf("Digite seu sexo (f ou m) e sua idade: ");
    scanf("%c %d", &sexo, &idade);
    
    /*
    if (sexo == 'm')
    {
        if (idade  == 18)
            printf("Alistamento obrigatório!\n");
        else
            printf("Dispensado!\n");
    }
    else
        printf("Dispensada!\n");
    */
    
    if (sexo == 'm' && idade == 18)
        printf("Alistamento obrigatório!\n");
    else
        printf("Dispensado!\n");
    
    return(0);
}
