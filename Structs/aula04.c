#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*


                                                    Aula 04

                                        De quanta memória precisa uma struct?

*/

typedef struct
{
    int dia, mes, ano;
}
Nascimento;

typedef struct
{
    //Nascimento data;
    int idade;
    char sexo;
    char nome[100];
}
Pessoa;

int main()
{
    int x;
    Pessoa pessoa;
    Nascimento Nasc;
    
    printf("%lu\n", sizeof(pessoa));
    
    printf("Digite seu nome: ");
    fgets(pessoa.nome, 100, stdin);
    
    printf("Digite sua idade: ");
    scanf("%d", &pessoa.idade);
    
    printf("Digite seu sexo (m/f): ");
    scanf(" %c", &pessoa.sexo);
    
    //printf("Digite sua data de nascimento no formato dd mm aaaa: ");
    //scanf("%d%d%d", &pessoa.data.dia, &pessoa.data.mes, &pessoa.data.ano);
    
    printf("\nNome: ");
    for (x = 0; pessoa.nome[x] != '\0'; x++)
        printf("%c", pessoa.nome[x]);
    printf("Idade: %d\nSexo: %c\n", pessoa.idade, pessoa.sexo);
    //printf("Data de Nascimento: %d/%d/%d\n", pessoa.data.dia, pessoa.data.mes, pessoa.data.ano);
    
    return(0);
}
