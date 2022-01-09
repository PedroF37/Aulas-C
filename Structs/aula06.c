#include <stdio.h>
#include <stdlib.h>

/*


                                                    Aula 06

                                 Como criar um procedimento que recebe uma struct como parâmetro

*/

typedef struct
{
    int dia, mes, ano;
}
DataNas;

typedef struct
{
    DataNas dataNas;
    int idade;
    char sexo;
    char nome[100];
}
Pessoa;

void imprimirPessoa(Pessoa p)
{
    printf("\n\tNome: %s", p.nome);
    printf("\tIdade: %d\n", p.idade);
    printf("\tSexo: %c\n", p.sexo);
    printf("\tData de Nascimento: %d/%d/%d\n\n", p.dataNas.dia, p.dataNas.mes, p.dataNas.ano);
}

int main()
{
    Pessoa pessoa;
    
    printf("Digite seu nome: ");
    fgets(pessoa.nome, 100, stdin);
    
    printf("Digite sua idade: ");
    scanf("%d", &pessoa.idade);
    getchar();
    
    printf("Digite f ou m para o sexo: ");
    scanf("%c", &pessoa.sexo);
    
    printf("Digite sua data de nascimento no formato dd mm aaaa: ");
    scanf("%d%d%d", &pessoa.dataNas.dia, &pessoa.dataNas.mes, &pessoa.dataNas.ano);
    
    imprimirPessoa(pessoa);
    
    return(0);
}
