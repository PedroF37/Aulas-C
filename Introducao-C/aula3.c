#include <stdio.h>
#include <stdlib.h>


/*
 * 
 *                              Aula 3
 * 
 *                       Lendo números inteiros
 * 
 */

int main()
{
    int numero, numero2; // criei uma variável para guardar um valor do tipo inteiro.
    
    numero = 50;    // atribuição -> atribuir um valor a uma variável.
    
    printf("Digite um valor inteiro: ");
    scanf("%d", &numero);   // o número 50, perdeu-se.
    
    printf("Digite um segundo valor inteiro: ");
    scanf("%d", &numero2);
    
    printf("\n\nPrimeiro valor: %d\nSegundo valor: %d\n\n", numero, numero2);
    
    return(0);
}
