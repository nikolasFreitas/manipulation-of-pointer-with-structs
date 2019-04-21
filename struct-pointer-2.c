#include <stdio.h>
#include <stdlib.h>
// FUNCTIONS
typedef struct
{
    int valor;
    struct Nodo *proximo;
} Nodo;

// 3) Implemente uma função para imprimir a lista.
void imprime_lista_inicio(Nodo *pp_ini)
{
    int count = 1;

    if (pp_ini->proximo)
    {
        printf("Imprimindo o valor das listas\n");
        printf("Ini=>");
        do
        {
            printf(" %d ", pp_ini->valor);
            pp_ini = pp_ini->proximo;
        } while (pp_ini);

        printf("<=fim\n");
    }
    else
    {
        printf("Lista está vazia \n");
    }

    printf("---------------- || -------------- \n\n");
}

// 5) Implemente uma função para inserir um nodo no início da lista:
void insere_inicio(Nodo **pp_ini, int valor)
{
    Nodo *pp_aux = (Nodo *)malloc(sizeof(Nodo));

    pp_aux->valor = valor;
    pp_aux->proximo = *pp_ini;

    *pp_ini = pp_aux;
};

// 9) Implemente uma função para inserir um nodo no final da lista:
void insere_fim(Nodo **pp_fim, int valor)
{
    Nodo *pp_aux = (Nodo *)malloc(sizeof(Nodo));
    pp_aux->valor = valor;
    pp_aux->proximo = NULL;

    (*pp_fim)->proximo = pp_aux;
    *pp_fim = pp_aux;
};

// ---------------- || --------------
int main(int argc, char const *argv[])
{
    Nodo *nodo_ini, *nodo_fim;

    nodo_ini = (Nodo *)malloc(sizeof(Nodo));
    nodo_ini->valor = 1;
    nodo_ini->proximo = NULL;

    nodo_fim = (Nodo *)malloc(sizeof(Nodo));
    nodo_fim = nodo_ini;

    imprime_lista_inicio(nodo_ini);

    // 6) Insira um nodo com valor 2 no início da lista e chame a função imprime_lista_inicio().
    insere_inicio(&nodo_ini, 2);
    imprime_lista_inicio(nodo_ini);

    // 7) Insira um nodo com valor 3 no início da lista e chame a função imprime_lista_inicio().
    insere_inicio(&nodo_ini, 3);
    imprime_lista_inicio(nodo_ini);

    // 8) Insira um nodo com valor 4 no início da lista e chame a função imprime_lista_inicio().
    insere_inicio(&nodo_ini, 4);
    imprime_lista_inicio(nodo_ini);

    // 10) Insira um nodo com valor 6 no final da lista e chame a função imprime_lista_inicio().
    insere_fim(&nodo_fim, 6);
    imprime_lista_inicio(nodo_ini);

    return 0;
}
