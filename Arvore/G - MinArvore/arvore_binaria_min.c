#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *left, *right;
};

struct node *createNode(int);
void insert(struct node **, struct node *);
int count(struct node *);
int max(struct node *n);

int main()
{
    struct node *raiz = NULL;
    int value, tamanho;

    scanf("%d", &tamanho);

    while (tamanho--)
    {
        scanf("%d", &value);
        insert(&raiz, createNode(value));
    }

    value = max(raiz);

    printf("%d\n", value);

    // if (raiz != NULL)
    //     printf("%d\n", altura(raiz));
    // else
    //     printf("0\n");

    return 0;
}

struct node *createNode(int novoValor)
{
    struct node *novoNode = (struct node *)malloc(sizeof(struct node));
    novoNode->value = novoValor;

    novoNode->right = NULL;
    novoNode->left = NULL;

    return novoNode;
}

void insert(struct node **n, struct node *novoNode)
{
    if (*n == NULL)
    {
        *n = novoNode;
    }
    else
    {
        if ((*n)->value > novoNodevalueor)
            insert(&(*n)->left, novoNode);
        else if ((*n)->value <= novoNodevalueor)
            insert(&(*n)->right, novoNode);
    }
}

int max(struct node *n)
{
    if (n == NULL)
        return 2147483647;

    int res = n->value;
    int lres = max(n->esquerda);
    int rres = max(n->direita);

    if (lres < res)
        res = lres;
    if (rres < res)
        res = rres;
    return res;

    // if (n->direita == NULL)
    //     return n->value;
    // else
    //     return max(n->direita);
}