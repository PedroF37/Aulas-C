#include <stdio.h>
#include <stdlib.h>


/*


                                            Aula 10
                                            
                                       Operador lógico ou (||)
                                       
                                       TABELA VERDADE:    a    b    a || b
                                                          V    V      V
                                                          V    F      V
                                                          F    V      V
                                                          F    F      F

*/

int main()
{
    int idade;
    
    printf("Digite sua idade: ");
    scanf("%d", &idade);
   
    /*
    if (idade <= 5)
        printf("Tem direito a grutuidade!\n");
    else
    {
        if (idade >= 60)
            printf("Tem direito a gratuidade!\n");
        else
            printf("Não tem direito a gratuidade!\n");
    }
    */
    
    if (idade <= 5 || idade >= 60)
        printf("Tem direito a gratuidade!\n");
    else
        printf("Não tem direito a gratuidade!\n");
    
    
    return(0);
}
