#include <stdio.h>
#include <stdlib.h>

struct node
{
    int valor;
    struct node *filhoDaEsquerda, *filhoDaDireita;
     
};

void cria_node(struct node *, int);
void insere(struct node *, int);
void exclui(struct node *, int);
void showPreOrder(struct node *);
void showInOrder(struct node *);
void showPostOrder(struct node *);

int main()
{
    struct node *raiz = NULL;

    insere(raiz, 8);
    printf("MAIN: %d \n", raiz->valor);
    insere(raiz, 5);
    insere(raiz, 6);
    insere(raiz, 7);

    showInOrder(raiz);
    showPreOrder(raiz);
    showPostOrder(raiz);

    return 0;
}

void cria_node(struct node *n, int valor)
{
    n = (struct node *)malloc(sizeof(struct node));
    n->valor = valor;

    n->filhoDaEsquerda = NULL;
    n->filhoDaDireita = NULL;

    printf("%d\n ", n->valor);
}

void insere(struct node *n, int novoValor)
{
    if (n == NULL)
    {
        printf("PRIMEIRO IF \n");
        cria_node(n, novoValor);
        printf("%d\n", n->valor);
    }
    else if (n->valor <= novoValor)
    {
        insere(n->filhoDaDireita, novoValor);
        printf("SEGUNDO \n");
    }
    else
    {
        insere(n->filhoDaEsquerda, novoValor);
        printf("TERCEIRO\n");
    }
}

void exclui(struct node *n, int valor)
{
    if (n != NULL)
    {
        struct node *anterior = NULL;
        struct node *atual = n;

        while (atual != NULL)
        {
            if (atual->valor == valor)
            {
            }
        }
    }
}

void showPreOrder(struct node *n)
{
    if (n == NULL)
        return;

    printf("%d ", n->valor);

    if (n->filhoDaEsquerda != NULL)
        showPreOrder(n->filhoDaEsquerda);

    if (n->filhoDaDireita != NULL)
        showPreOrder(n->filhoDaDireita);
}
void showInOrder(struct node *n)
{
    if (n == NULL)
        return;

    if (n->filhoDaEsquerda != NULL)
        showInOrder(n->filhoDaEsquerda);

    printf("%d ", n->valor);

    if (n->filhoDaDireita != NULL)
        showInOrder(n->filhoDaDireita);
}

void showPostOrder(struct node *n)
{
    if (n == NULL)
        return;

    if (n->filhoDaEsquerda != NULL)
        showPostOrder(n->filhoDaEsquerda);
    if (n->filhoDaDireita != NULL)
        showPostOrder(n->filhoDaDireita);

    printf("%d ", n->valor);
}