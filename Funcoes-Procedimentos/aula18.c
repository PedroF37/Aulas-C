#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*


                                                    Aula 18
                                                    
                              Calcular o tempo de execução do algoritmo de FIBONACCI recursivo
                              e iterativo.

*/

long long int fiboR(int n)
{
    if (n == 1)
        return(0);
    else
    {
        if (n == 2)
            return(1);
        else
            return(fiboR(n - 1) + fiboR(n - 2));
    }
}

long long int fiboI(int n)    // 3
{
    long long int a = 0, b = 1, c;
    int i = 2;
    
    if (n == 1)
        return(a);
    else
    {
        if (n == 2)
            return(b);
        else
        {
            while (i < n)
            {
                c = a + b;
                a = b;
                b = c;
                i++;
            }
            
            return(c);
        }
    }
}

int main()
{
    int n = 50;
    time_t tIni, tFim;
    
    tIni = time(NULL);
    printf("Fibonacci iterativo: %lld\n", fiboI(n));
    tFim = time(NULL);
    printf("\tTempo em segundos: %f\n\n", difftime(tFim, tIni));
    
    tIni = time(NULL);
    printf("Fibonacci recursivo: %lld\n", fiboR(n));
    tFim = time(NULL);
    printf("\tTempo em segundos: %f\n\n", difftime(tFim, tIni));
    
    return(0);
}
