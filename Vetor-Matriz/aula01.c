#include <stdio.h>
#include <stdlib.h>



/*


                                                    Aula 1
                                                    
                                   Como criar um vetor (Array unidimensional)
                                   
                                   Vetor -> homogéneo (armazena elementos do mesmo tipo)

*/

int main()
{
    int numeros[10];
    int numeros2[] = {1, 5, 9, 15, 43};     // aqui o vetor tem o tamanho de 5, porque atribuimos 5 valores a ele.
    int numeros3[5] = {4, 7, 5};    // fornecemos apenas 3 valores, mas o tamanho do vetor é 5. Número 4 fica no indice 0, 7 no indice 1, 5 no indice 2
                                    // e os outros dois índices que não tem valor, o computador preenche com zero (0).
    
    int numeros4[5] = {1, 2, 3, 4, 5, 6};       // o sexto número é perdido, porque o vetor tem tamanho de 5 posições e passamos 6 posições.
    
    int numeros5[5] = {0};  // vai preencher o vetor com zero. Ele pega o 0 e coloca na posição zero e as outras posições coloca zero também.
    
    // caractere:
    char letras[100];       // armazena até 100 letras
    
    char vogais[5] = {'a', 'e', 'i', 'o', 'u'};
    
    float notas[3] = {7.5, 8.3, 9.5};
    
    
    
    return(0);
}
