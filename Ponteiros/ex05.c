#include <stdio.h>
#include <stdlib.h>

/*

                               Exercicio 5:
                               
                               Implemente a função strcpy (char *destino, char *origem) usando ponteiros

*/


char Strcpy(char *dest, char *orig)
{
    int i = 0;
    
    while (*(orig + i) != '\0')
    {
        *(dest + i) = *(orig + i);
        i++;
    }
    
    *(dest + i) = '\0';
    return(*dest);
}


int main()
{
    char origem[25] = {"Bom dia."}, destino[25];
    
    Strcpy(destino, origem);
    printf("Destino: %s\n", destino);
    
    return(0);
}