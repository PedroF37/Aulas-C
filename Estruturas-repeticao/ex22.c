#include <stdio.h>
#include <stdlib.h>


/*


                                                    Exericio 22
                                                    
                                   Chico tem 1.50 metros e cresce 2 centímetros por ano, enquanto Zé tem 1.10
                                   metros e cresce 3 centímetros por ano. Construa um programa que calcule e
                                   imprima quantos anos serão necessários para que Zé seja maior do que Chico.

*/

int main()
{
    int anos = 0;
    float chico = 1.5, ze = 1.1;
    
    
    while (ze <= chico)
    {
        ze += 0.03;
        chico += 0.02;
        anos++;
        printf("Chico: %.2f\tZé: %.2f\tAno: %d\n", chico, ze, anos);
        
    }
    
    printf("\nSerão necessários %d anos para que Zé seja mais alto do que Chico.\n", anos);
    
    return(0);
}
