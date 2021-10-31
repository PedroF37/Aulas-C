#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*


                                        Aula 13
                                        
                        Como dividir uma string com a função strtok()
                        
                        ptr =  strtok(string-para-dividir, caractere-para-usar-para-dividir)
                        
                        Exemplo:
                        
                        char palavra[50] = {"Bom dia Zé Ruela"}
                        char *ptr;
                        
                        ptr = strtok(palavra, " ") -> dividimos usando o espaço..
                        
                        Podemos usar mais que um caractere para dividir:
                        
                        char palavra[50] = {"Bom!dia. Zé Ruela"}
                        
                        ptr = strtok(palavra, "!. ") -> divide usando estes caracteres. Quando encontrar a exclamação, divide, quando encontrar o ponto (.) divide e quando encontrar o espaço, divide. kk

*/

int main()
{
    char palavra[50] = {"Bom dia simpatia!"};
    char *ptr;
    
    ptr = strtok(palavra, " ");
    
    while (ptr)
    {
        printf("token: %s\n", ptr);
        ptr = strtok(NULL, " ");    // Isto diz para a função que é para continuar de onde parou, e não do inicio (dizem os entendidos..).
                                    // Se não, se usasse-mos ptr = strtok(palavra, " "), a função ia começar de novo na palavra Bom e ia ficar em loop
                                    // infinito (dizem os entendidos...!!);
    }
    
    
    return(0);
}
