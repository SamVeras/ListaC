#include <stdio.h>
#include <stdlib.h>

struct item
{
    int valor;
    struct item *proximo;
};

void InicializarLista(struct item **l)
{
    // atribuir 0 para a lista
    *l = NULL;
};

void InserirNaLista(struct item **l, int v)
{
    if (*l == 0)
    {
        *l = malloc(sizeof(struct item));
        (*l)->valor = v;
        (*l)->proximo = 0;
    } else {
        struct item *aux = malloc(sizeof(struct item));
        aux->valor = v;
        aux->proximo = *l;
        *l = aux;
    };
};

void DestruirLista(struct item *l)
{
    free(l);
};

void ListaImprimir(struct item *p)
{
    while (p != 0)
    {
        // Imprimir dados
        printf("Valor = %d\n", p->valor);
        printf("Proximo = %p\n", p->proximo);
        // Avançar para o próximo nó
        p = p->proximo;
    };
};

int main()
{
    printf("Bla.\n");

    struct item *lista;
    InicializarLista(&lista);
    printf("endereço da lista = %p\n", lista);

    InserirNaLista(&lista, 1);
    InserirNaLista(&lista, 2);
    InserirNaLista(&lista, 3);

    ListaImprimir(lista);
    DestruirLista(lista);

    return 0;
}
