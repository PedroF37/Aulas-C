#include <stdio.h>
#include <stdlib.h>

/*


                                                                 Aula 10

                                               Como construir o tipo eletrônico com typedef struct?

*/

typedef struct
{
    char tipo[100];
    char marca[50];
    char modelo[25];
    char energia;
    char descricao[500];
    int quantidade;
    int codigo;
}
Eletronico;

void imprimirEletronico(Eletronico e)
{
    printf("\tTipo: %s", e.tipo);
    printf("\tMarca: %s", e.marca);
    printf("\tModelo: %s", e.modelo);
    printf("\tEnergia: %c\n\tQuantidade: %d\n", e.energia, e.quantidade);
    printf("\tDescrição: %s", e.descricao);
    printf("\tCodigo: %d\n", e.codigo);
}

Eletronico lerEletronico()
{
    Eletronico e;
    
    printf("Digite o tipo: ");
    fgets(e.tipo, 100, stdin);
    
    printf("Marca: ");
    fgets(e.marca, 50, stdin);
    
    printf("Modelo: ");
    fgets(e.modelo, 25, stdin);
    
    printf("Eficiencia energetica: ");
    scanf("%c", &e.energia);
    getchar();
    
    printf("Descrição: ");
    fgets(e.descricao, 500, stdin);
    
    printf("Quantidade e codigo: ");
    scanf("%d%d", &e.quantidade, &e.codigo);
    
    return(e);
}

int main()
{
    Eletronico eletronico;
    
    eletronico = lerEletronico();
    imprimirEletronico(eletronico);
    
    return(0);
}
