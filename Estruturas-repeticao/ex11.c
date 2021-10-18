#include <stdio.h>
#include <stdlib.h>


/*


                                        Exercicio 11
                                        
                          Um determinado material radioativo perde metade de sua massa a cada 50 segundos.
                          Dada a sua massa inicial, em gramas, faça um programa que determine o tempo necessário
                          para que essa massa se torne menor do que 0.05 gramas.
                          
                          massaInicial = 100 gramas
                          
                          tempo = 50 > massa 50 gramas
                          tempo = 100 > massa 25 gramas
                          tempo = 150 > massa 12.5 gramas

*/

int main()
{
    int tempo = 0;
    float massa;
    
    printf("Digite a massa inicial do material: ");
    scanf("%f", &massa);
    
    while (massa >= 0.05)
    {
        tempo += 50;
        massa = massa / 2;
    }
    
    printf("\nO tempo necessário a massa ser menor do que 0.05 gramas, é %d segundos\n", tempo);
    
}
