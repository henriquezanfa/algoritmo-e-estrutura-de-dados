#include <stdio.h>
#include <stdlib.h>

struct Lista
{
    int *items;              // ponteiro pros itens que a lista contem
    int quantidade, tamanho; // quantidade = #itens inseridos.
                             // tamanho = #itens máximo que a lista pode receber
};

void iniciaLista(struct Lista *lista, int tamanho)
{
    lista->items = (int *)malloc(tamanho * sizeof(int));
    lista->tamanho = tamanho;
    lista->quantidade = 0;
}

void incluir(struct Lista *lista, int valor)
{
    int i, j, posicaoPraInserir = 0;

    if (lista->quantidade != 0) // se a lista não estiver vazia
    {
        for (i = 0; i < lista->quantidade; i++)
        {
            if (valor == lista->items[i])
            {
                return;
            }
            if (valor < lista->items[i]) // achou a posição pra inserir
            {
                for (j = lista->quantidade; j > i; j--)
                {
                    // move todos os itens maiores do que o valor a ser inserido
                    // uma casa pra frente
                    lista->items[j] = lista->items[j - 1];
                }
                break;
            }
            posicaoPraInserir++;
        }
    }

    lista->items[posicaoPraInserir] = valor;
    lista->quantidade++;
}

void remover(struct Lista *lista, int valor)
{
    int i, j, posicaoParaRemover = 0;

    if (lista->quantidade != 0) // se a lista não estiver vazia
    {
        for (i = 0; i < lista->quantidade; i++)
        {
            if (valor == lista->items[i]) // achou a posição pra remover
            {
                for (j = i; j < lista->quantidade; j++)
                {
                    lista->items[j] = lista->items[j + 1];
                }
                lista->quantidade--;
                lista->items[lista->quantidade] = ((void *)0);
                break;
            }
        }
    }
}

void buscar(struct Lista *lista, int valor)
{
    int i;
    if (lista->quantidade != 0)
    {
        for (i = 0; i < lista->quantidade; i++)
        {
            if (valor == lista->items[i])
            {
                printf("SIM\n");
                return;
            }
        }
    }

    printf("NAO\n");
}

void printLista(struct Lista *lista)
{
    int i;
    if (lista->quantidade != 0)
    {
        for (i = 0; i < lista->quantidade - 1; i++)
        {
            printf("%d ", lista->items[i]);
        }
        printf("%d\n", lista->items[i]);
    }
}

int main()
{
    char comando;
    int valor, n, i;

    scanf("%d\n", &n);

    struct Lista lista;
    iniciaLista(&lista, n);

    while (scanf("\n%c", &comando) != EOF)
    {

        if (comando == 'I' || comando == 'R' || comando == 'B')
            scanf("%d", &valor);

        if (comando == 'I')
        {
            incluir(&lista, valor);
        }
        else if (comando == 'R')
        {
            remover(&lista, valor);
        }
        else if (comando == 'B')
        {
            buscar(&lista, valor);
        }
        else if (comando == 'M')
        {
            printLista(&lista);
        }
    }

    return 0;
}