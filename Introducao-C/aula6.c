#include <stdio.h>
#include <stdlib.h>


/*
 
                                            Aula 6

                              Lendo caracteres com função getchar(), getc() e fgetc()
                              
                              getchar() pega um caractere do buffer do teclado e retorna o carcatere.
                              Para usar, podemos retornar para variável: letra = getchar()
                              
                              Função getc() é igual á getchar(), com a diferença que podemos usar a função getc()
                              para lêr de outros locais para além do teclado, como por exemplo de um arquivo.
                              Por isso, na função getc(), temos que passar um parâmetro dizendo de onde ela vai lêr o caractere:
                              
                              letra = getc(stdin) -> lê da entrada padrão.
                              
                              fgetc() -> file get char: letra = fgetc(stdin) ou letra fgetc(arquivo)

*/

int main()
{
    char letra;
    
    printf("Digite uma letra: ");
    letra = getchar();
    
    printf("A letra digitada foi: %c\n", letra);
    
    return(0);
}
