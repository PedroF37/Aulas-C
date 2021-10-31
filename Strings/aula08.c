#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*


                                        Aula 8
                                        
                         Concatenando duas strings com a função strcat()

*/

int main()
{
    char palavra1[50] = {"Oi."};
    char palavra2[50] = {" Bom dia."};
    
    strcat(palavra1, palavra2);
    
    printf("\n\t%s\n", palavra1);
   

    
    
    return(0);
}
