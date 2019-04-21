#include <stdio.h>
#include <stdlib.h>

// 1) Implemente uma struct Nodo para construir uma lista simplesmente encadeada para armazenar números inteiros.
typedef struct
{
  int valor;
  struct Nodo *proximo;
} Nodo;

// Functions to help 
void imprime_lista_inicio(Nodo *p)
{
  int count = 1;
  printf("Nodo %d => %d\n", count, p->valor);
  while (p->proximo)
  {
    p = p->proximo;
    count++;
    printf("Nodo %d => %d\n", count, p->valor);
  }
  printf("\n----------\n\n");
}

Nodo *get_last_pointer_nodo(Nodo *p)
{
  int count = 1;
  Nodo *aux;
  while (p->proximo)
  {
    count++;
    if (p->proximo)
    {
      aux = p;
    }
    p = p->proximo;
  }

  printf("\n----------\n\n");
  return aux;
}

void insert_nodo(Nodo *init, int value, int where)
{
  int i = 0;
  Nodo *aux, *p;

  while (init->proximo)
  {
    if ((i + 1) == where)
    {
      aux = (Nodo *)malloc(sizeof(Nodo));
      p = init->proximo;
      init->proximo = aux;

      aux->valor = value;
      aux->proximo = p;

      init = p->proximo;
    }
    else
    {
      init = init->proximo;
    }

    i++;
  }
}

Nodo *get_nodo_by_value(Nodo *init, int value)
{
  int i = 1;
  Nodo *aux;

  while (i)
  {
    if (init->valor == value)
    {
      aux = init;
      i = 0;
    }
    
    init = init->proximo;
  }

  return aux;
}

void remove_nodo(Nodo *init, Nodo *p)
{
  Nodo *aux;

  while (init->proximo)
  {
    if (init->proximo == p)
    {
      aux = p->proximo;
      init->proximo = aux;

      p = NULL;
      free(p);
    }
    else
    {
      init = init->proximo;
    }
  }
}

int main()
{
  Nodo *nodo_ini;
  Nodo *nodo_fin;
  Nodo *nodo_aux;

  // 2) Faça um programa que insira 3 nodos na lista, com os valores 5, 6 e 7, sendo 5 o primeiro nodo e 7 o último nodo.
  nodo_ini = (Nodo *)malloc(sizeof(Nodo));
  nodo_aux = (Nodo *)malloc(sizeof(Nodo));

  nodo_ini->valor = 5;
  nodo_ini->proximo = nodo_aux;

  nodo_fin = nodo_aux;
  nodo_fin->valor = 6;

  nodo_aux = (Nodo *)malloc(sizeof(Nodo));
  nodo_fin->proximo = nodo_aux;

  nodo_fin = nodo_aux;
  nodo_fin->valor = 7;
  nodo_fin->proximo = NULL;
  // 3) Crie uma função chamada imprime_lista_inicio, que recebe como parâmetro um ponteiro para o início da lista. A função deverá imprimir o campo valor de todos os nodos da lista. Se não conseguir implementar a função, continue desenvolvendo os próximos exercícios.
  imprime_lista_inicio(nodo_ini);

  // 4) Insira um nodo (com valor 4) no início da lista. Chame a função imprime_lista_inicio e verifique o resultado: 4, 5, 6, 7. Se não conseguiu implementar a função, imprima os nodos diretamente (sem chamar a função).
  nodo_aux = (Nodo *)malloc(sizeof(Nodo));
  nodo_aux->valor = 4;
  nodo_aux->proximo = nodo_ini;

  nodo_ini = nodo_aux;

  imprime_lista_inicio(nodo_ini);

  //  5) Insira um nodo (com valor 77) no final da lista. Imprima a lista e verifique o resultado: 4, 5, 6, 7, 77.
  nodo_aux = (Nodo *)malloc(sizeof(Nodo));
  nodo_fin->proximo = nodo_aux;

  nodo_aux->valor = 77;
  nodo_aux->proximo = NULL;

  nodo_fin = nodo_aux;
  imprime_lista_inicio(nodo_ini);
  //  6) Remova o primeiro nodo da lista. Imprima a lista e verifique o resultado: 5, 6, 7, 77.
  nodo_aux = nodo_ini;

  nodo_ini = nodo_ini->proximo;
  nodo_aux = NULL;
  free(nodo_aux);
  imprime_lista_inicio(nodo_ini);

  // 7) Insira um nodo (com valor 33) no início da lista. Imprima a lista e verifique o resultado: 33, 5, 6, 7, 77.
  nodo_aux = (Nodo *)malloc(sizeof(Nodo));
  nodo_aux->valor = 33;
  nodo_aux->proximo = nodo_ini;

  nodo_ini = nodo_aux;
  imprime_lista_inicio(nodo_ini);
  // 8) Remova o último elemento da lista. Imprima a lista e verifique o resultado: 33, 5, 6, 7.
  nodo_aux = get_last_pointer_nodo(nodo_ini);

  nodo_fin = NULL;
  free(nodo_fin);
  nodo_fin = nodo_aux;
  nodo_fin->proximo = NULL;

  imprime_lista_inicio(nodo_ini);

  // 9) Insira um nodo (com valor 88) no final da lista. Imprima a lista e verifique o resultado: 33, 5, 6, 7, 88.
  nodo_aux = (Nodo *)malloc(sizeof(Nodo));
  nodo_fin->proximo = nodo_aux;
  nodo_aux->valor = 88;
  nodo_aux->proximo = NULL;
  imprime_lista_inicio(nodo_ini);

  // 10) Insira um nodo (com valor 55) após o segundo elemento da lista. Imprima a lista e verifique o resultado: 33, 5, 55, 6, 7, 88.
  insert_nodo(nodo_ini, 55, 2);

  imprime_lista_inicio(nodo_ini);

  // 11) Insira um nodo (com valor 66) após o quarto elemento da lista. Imprima a lista e verifique o resultado: 33, 5, 55, 6, 66, 7, 88.

  insert_nodo(nodo_ini, 66, 4);

  imprime_lista_inicio(nodo_ini);

  // 12) Remova o nodo que tem valor 55. Imprima a lista e verifique o resultado: 33, 5, 6, 66, 7, 88.
  nodo_aux = get_nodo_by_value(nodo_ini, 55);

  remove_nodo(nodo_ini, nodo_aux);
  imprime_lista_inicio(nodo_ini);

  return 0;
}