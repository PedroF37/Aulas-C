#include <stdio.h>
#include <stdlib.h>

/*


                                        Aula 21
                                Operador de incremento ++ e decremento --

*/

int main()
{
    int contador = 10;
    
    printf("Valor: %d\n", contador++);  // mostra 10. A variável contador é incrementada depois de ser usada na impressão
    printf("Valor: %d\n", ++contador);  // mostra 12. A variável contador agora é incrementada antes de ser usada na impressão
    
    /*
     Pode ser feito o incremento de várias formas:
     
     contador++;
     contador += 1;
     contador = contador + 1;
     
     O decremento é igual:
     
     contador--;
     contador -= 1;
     contador = contador - 1;
    
    
    */
    
    
    return(0);
}
