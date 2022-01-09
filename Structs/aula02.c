#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*


                                                    Aula 02

                                Como criar uma struct com dados lidos do teclado

*/

typedef struct
{
    int idade;
    char sexo;
    char nome[100];
}
Pessoa;

int main()
{
    int x;
    Pessoa pessoa;
    
    printf("Digite seu nome: ");
    fgets(pessoa.nome, 100, stdin);
    
    printf("Digite sua idade: ");
    scanf("%d", &pessoa.idade);
    
    printf("Digite seu sexo (m/f): ");
    scanf(" %c", &pessoa.sexo);
    
    printf("\nNome: ");
    for (x = 0; pessoa.nome[x] != '\0'; x++)
        printf("%c", pessoa.nome[x]);
    printf("Idade: %d\nSexo: %c\n", pessoa.idade, pessoa.sexo);
    
    return(0);
}
