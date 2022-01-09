#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*


                                                    Aula 01

                                Como criar novos tipos de dados em C com typedef struct

*/

typedef struct
{
    int idade;
    char sexo;
    char nome[100];
}
Pessoa;

struct Pessoa2
{
    int idade;
    char sexo;
    char nome[100];
};

int main()
{
    Pessoa pessoa1;
    struct Pessoa2 pessoa2;
    
    pessoa1.idade = 35;
    pessoa1.sexo = 'f';
    strcpy(pessoa1.nome, "Maria Madalena");
    
    pessoa2.idade = 87;
    pessoa2.sexo = 'm';
    strcpy(pessoa2.nome, "Jacinto Rego");
    
    printf("Nome: %s\nIdade: %d\nSexo: %c\n\n", pessoa1.nome, pessoa1.idade, pessoa1.sexo);
    printf("Nome: %s\nIdade: %d\nSexo: %c\n", pessoa2.nome, pessoa2.idade, pessoa2.sexo);
    
    return(0);
}
