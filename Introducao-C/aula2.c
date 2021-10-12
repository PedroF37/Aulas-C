#include <stdio.h>
#include <stdlib.h>


/*
 * Aula 2: Alternativa ao system("pause") | system("sleep")
 * 
 * system("pause") | ("sleep") é recurso do sistema. O system("sleep")
 * vai funcionar no windows mas não no linux e o ("sleep") vai funcionar
 * no linux mas não no windows. Para ser portável podemos usar apenas
 * o getchar(), que vai ficar á espera do usuário precionar o enter.
*/

int main()
{
    
    printf("Pressione qualquer tecla para finalizar.");
    getchar();
    
    return(0);
}
