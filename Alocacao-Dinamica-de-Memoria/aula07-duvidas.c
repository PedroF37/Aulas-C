#include <stdio.h>
#include <stdlib.h>


/*

                     Foram digitadas 3 linhas, onde cada uma das linhas contém o nome e a nota de um aluno.
                     Escreva um programa que leia essas informações e monte uma tabela onde a primeira
                     coluna é o nome e a segunda coluna é a nota.

*/

int main()
{
    char nomes[3][30];
    float notas[3];
    int i;
    
    for (i = 0; i < 3; i++)
    {
        printf("Digite o nome e a nota do estudante: ");
        scanf("%s%f", nomes[i], &notas[i]);     // na videoaula o professor usou: scanf("%s%f", &nomes[i], &notas[i]); e funcionou perfeito
                                                // mas no meu computador fazendo desse jeito deu um aviso (warning): 
                                                // warning: format specifies type 'char *' but the argument has type 'char (*)[30]' [-Wformat]
                                                // scanf("%s%f", &nomes[i], &notas[i]);
                                                // so não dá mensagem de aviso usando nomes[i] ao invés de &nomes[i];
    }
    
    for (i = 0; i < 3; i++)
        printf("%s\t%.2f\n", nomes[i], notas[i]);
    
    return(0);
}