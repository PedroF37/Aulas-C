#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

                             Aula 09:
                             
                             Faça uma função que recebe um nome e devolve o nome invertido.
                             
                             Muito
                             otiuM


*/

/*
void inverter(char frase[])
{
    int i, j, temp;
    
    j = strlen(frase);
    j--;
    
    for (i = 0; i < j; i++)
    {
        temp = frase[i];
        frase[i] = frase[j];
        frase[j] = temp;
        j--;
    }
}
*/
char *inverter(char frase[])
{
    int i, fim, tam = strlen(frase);
    
    char *novo = malloc((tam + 1) * sizeof(char));
    
    fim = tam - 1;
    for (i = 0; i < tam; i++)
    {
        novo[fim] = frase[i];
        fim--;
    }
    novo[i] = '\0';
    return(novo);
}


int main()
{
    char frase[25] = {"Muito bem feito!"};
    char *p;
    
    printf("Frase antes da inversão:\n%s\n\n", frase);
    //inverter(frase);
    
    p = inverter(frase);
    printf("Frase depois da inversão:\n%s\n\n", p);
    
    return(0);
}