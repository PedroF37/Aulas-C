#include <stdio.h>
#include <stdlib.h>


/*

                            Aula 07: É possivel ponteiro para struct?

*/

typedef struct
{
    int dia, mes, ano;
}
Data;

void imprimirData(Data *x)
{
    printf("%d/%d/%d\n", x->dia, x->mes, x->ano);
}


int main()
{
    Data data;
    Data *p;
    
    p = &data;
    
    printf("Data: %p\tp: %p\n", &data, p);
    
    data.dia = 29;
    data.mes = 2;
    data.ano = 2021;
    
    imprimirData(p);
    
    printf("%d/%d/%d\n", data.dia, data.mes, data.ano);
    

    return(0);
}