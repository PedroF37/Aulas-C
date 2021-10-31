#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*


                                        Aula 9
                                        
                         Comparar duas strings com a função strcmp();

*/

int main()
{
    char palavra1[50] = {"Oi"};
    char palavra2[50] = {"Bom"};
    
    printf("\n\nResultado: %d\n\n", strcmp(palavra1, palavra2));
    
    return(0);
}
