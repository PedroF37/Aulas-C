#include <stdio.h>
#include <stdlib.h>


/*


                                            Aula 9
                            Problema ao lêr caractere com a linguagem C nas funçoes scanf, getchar, getc...
                                    
                   Problema é com relação ao buffer do teclado, que é uma região especial na memória.
                   Cada tecla no teclado representa um caractere. Assim, se o usuário digitar, por exemplo
                   27 anos para a idade e pressionar espaço ou enter, 69.8 para o peso e pressionar espaço ou enter
                   1.72 para a altura e pressionar espaço ou enter e depois f ou m para o sexo e enter, vamos ter algo
                   assim no buffer do teclado:
                   
                   27\n69.8\n1.72\nf\n
                   
                   É o \n entre o 1.72 e a letra f que causa o problema, porque o ENTER (\n) é um caractere e como o scanf
                   procura um caractere depois do float, ele pega o \n e não o f ou m do sexo.
                   
                   scanf: 'Existe alguém no buffer do telado?' Resposta: sim tem o \n e o 27. scanf descarta o \n e pega o 27 porque está á procura de um int
                   scanf: 'Existe mais alguém no buffer?' Resposta: sim tem o \n e o 69.8. scanf descarta o \n e pega o 69.9 porque está á procura de um float
                   scanf: 'Existe mais alguém no buffer?' Resposta: sim tem o \n e o 1.72. scanf descarta o \n e pega o 1.72 porque está á procura de um float.
                   scanf: 'Existe mais alguém no buffer?' Resposta: SIM!! TEM O \n E O f ou m. Como o scanf ESTÁ Á PROCURA DE UM CARACTERE, ELE PEGA O PRIMEIRO
                   QUE APARECE!!! E o primeiro que aparece é o \n. Assim, ele pega o \n e não liga para o f ou m.
                   
                   Para resolver, pudemos colocar um espaço no scanf, antes do %c. Assim: scanf("%d%f%f %c"). Isto diz para o C, desconsiderar o ENTER (\n), espaço
                   e tudo o resto, e pegar o que vem a seguir. Aqui no caso é o caractere f ou m.
                   
                   


*/

int main()
{
    char sexo;
    int idade;
    float peso, altura;
    
    printf("Digite idade, peso, altura e o sexo (f, F, m, M): ");
    scanf("%d%f%f %c", &idade, &peso, &altura, &sexo);
    
    /*
    
      Se tivermos uma situação assim:
      printf("Digite uma letra: ");
      scanf("%c", &a);
      
      printf("Digite outra letra: ");
      scanf("%c", letra &b)
      
      Aqui nós colocamos o espaço antes do %c no segundo scanf. Porque o usuário digita a primeira letra e depois enter
      Então o programa lê a primeira letra e depois le o enter e guarda na segunda variável. Então para impedir que o enter seja guardado
      na segunda variável, nós colocamos o espaço no segundo scanf: scanf(" %c", &b);
      
      Ou pudemos também colocar o getchar() entre a primeira scanf e a segunda scanf. Assim o getchar() vai pegar o enter, ou o scanf(%c) kk assim ele pega e descarta..
    
    
    */
    
    printf("\nIdade: %d\nPeso: %.2f\nAltura: %.2f\nSexo: %c\n", idade, peso, altura, sexo);
    
    
    return(0);
}
