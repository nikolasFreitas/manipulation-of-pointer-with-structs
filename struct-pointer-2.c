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

    if (pp_ini->valor)
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
    if ((*pp_ini)->valor)
    {
        Nodo *pp_aux = (Nodo *)malloc(sizeof(Nodo));
        pp_aux->valor = valor;
        pp_aux->proximo = *pp_ini;
        *pp_ini = pp_aux;
    }
    else
    {
        (*pp_ini)->valor = valor;
    }
};

// 9) Implemente uma função para inserir um nodo no final da lista:
void insere_fim(Nodo **pp_fim, int valor)
{
    if ((*pp_fim)->valor)
    {
        Nodo *pp_aux = (Nodo *)malloc(sizeof(Nodo));
        pp_aux->valor = valor;
        pp_aux->proximo = NULL;

        (*pp_fim)->proximo = pp_aux;
        *pp_fim = pp_aux;
    }
    else
    {
        (*pp_fim)->valor = valor;
    }
}

void remove_primeiro(Nodo **pp_ini, Nodo **pp_fim)
{
    if (*pp_ini != *pp_fim)
    {
        Nodo *pp_aux = (Nodo *)malloc(sizeof(Nodo));
        pp_aux = (*pp_ini)->proximo;

        *pp_ini = NULL;
        free(*pp_ini);

        *pp_ini = pp_aux;
    }
    else
    {
        (*pp_ini)->proximo = NULL;
        (*pp_fim)->valor = NULL;
    }
};

// 15) Implemente uma função para remover o último nodo da lista.
void remove_ultimo(Nodo **pp_ini, Nodo **pp_fim)
{
    Nodo *pp_aux = (Nodo *)malloc(sizeof(Nodo));

    if (*pp_fim != *pp_ini)
    {
        pp_aux = *pp_ini;
        while (pp_aux->proximo)
        {
            if (pp_aux->proximo == *pp_fim)
            {
                break;
            }
            pp_aux = pp_aux->proximo;
        }

        pp_aux->proximo = NULL;
        *pp_fim = NULL;
        free(*pp_fim);

        *pp_fim = pp_aux;
    }
    else
    {
        (*pp_fim)->valor = NULL;
        (*pp_fim)->proximo = NULL;
    }
};

// ---------------- || --------------
int main(int argc, char const *argv[])
{
    Nodo *nodo_ini, *nodo_fim;

    nodo_ini = (Nodo *)malloc(sizeof(Nodo));
    nodo_fim = (Nodo *)malloc(sizeof(Nodo));
    nodo_ini->valor = NULL;
    nodo_ini->proximo = NULL;

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

    // 11) Insira um nodo com valor 7 no final da lista e chame a função imprime_lista_inicio().
    insere_fim(&nodo_fim, 7);
    imprime_lista_inicio(nodo_ini);

    // 13) Remova o primeiro nodo da lista e imprima a lista.
    remove_primeiro(&nodo_ini, &nodo_fim);
    imprime_lista_inicio(nodo_ini);

    // 14) Remova o primeiro nodo da lista e imprima a lista.
    remove_primeiro(&nodo_ini, &nodo_fim);
    imprime_lista_inicio(nodo_ini);

    // 16) Remova o último nodo da lista e imprima a lista.
    remove_ultimo(&nodo_ini, &nodo_fim);
    imprime_lista_inicio(nodo_ini);

    // 17) Remova o último nodo da lista e imprima a lista.
    remove_ultimo(&nodo_ini, &nodo_fim);
    imprime_lista_inicio(nodo_ini);

    // 18) Remova o último nodo da lista e imprima a lista.
    remove_ultimo(&nodo_ini, &nodo_fim);
    imprime_lista_inicio(nodo_ini);

    // 19) Insira um nodo com valor 33 no início da lista e imprima a lista.
    insere_inicio(&nodo_ini, 33);
    imprime_lista_inicio(nodo_ini);

    // 20) Remova o primeiro elemento da lista.
    remove_ultimo(&nodo_ini, &nodo_fim);
    imprime_lista_inicio(nodo_ini);

    // 21) Insira um nodo com valor 44 no início da lista e imprima a lista.
    insere_inicio(&nodo_ini, 44);
    imprime_lista_inicio(nodo_ini);

    // 22) Remova o último elemento da lista.
    remove_primeiro(&nodo_ini, &nodo_fim);
    imprime_lista_inicio(nodo_ini);

    // 23) Insira um nodo com valor 55 no final da lista e imprima a lista.
    insere_fim(&nodo_fim, 55);
    imprime_lista_inicio(nodo_ini);

    // 24) Remova o primeiro elemento da lista.
    remove_primeiro(&nodo_ini, &nodo_fim);
    imprime_lista_inicio(nodo_ini);

    // 25) Insira um nodo com valor 66 no final da lista e imprima a lista.
    insere_fim(&nodo_fim, 55);
    imprime_lista_inicio(nodo_ini);

    // 26) Remova o último elemento da lista.
    remove_ultimo(&nodo_ini, &nodo_fim);
    imprime_lista_inicio(nodo_ini);

    // 27) Tente remover novamente o primeiro elemento da lista.
    remove_primeiro(&nodo_ini, &nodo_fim);
    imprime_lista_inicio(nodo_ini);

    // 28) Tente remover novamente o último elemento da lista.
    remove_ultimo(&nodo_ini, &nodo_fim);
    imprime_lista_inicio(nodo_ini);
    return 0;
}
