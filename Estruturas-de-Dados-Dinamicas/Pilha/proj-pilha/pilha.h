#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct no
{
    int valor;
    struct no *proximo;
}
No;

No* empilhar(No *pilha, int num);

No* desempilhar(No **pilha);

void imprimir(No *pilha);


#endif  // PILHA_H_INCLUDED