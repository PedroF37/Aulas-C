#include <stdio.h>
#include <stdlib.h>


/*


                                            Aula 8
                                    Lêr sexo, idade, peso e altura


*/

int main()
{
    char sexo;
    int idade;
    float peso, altura;
    
    printf("Digite sexo (f, F, m, M), idade, peso e altura: ");
    scanf("%c %d %f %f", &sexo, &idade, &peso, &altura);
    
    printf("\nSexo: %c\nIdade: %d\nPeso: %.2f\nAltura: %.2f\n", sexo, idade, peso, altura);
    
    
    return(0);
}
