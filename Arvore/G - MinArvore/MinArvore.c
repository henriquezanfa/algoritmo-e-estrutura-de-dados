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
int minValue(struct node *n);

int main()
{
    struct node *root = NULL;
    int value, size;

    scanf("%d", &size);

    while (size--)
    {
        scanf("%d", &value);
        insert(&root, createNode(value));
    }

    value = minValue(root);

    printf("%d\n", value);

    return 0;
}

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = value;

    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}

void insert(struct node **n, struct node *newNode)
{
    if (*n == NULL)
        *n = newNode;
    else
    {
        if ((*n)->value > newNode->value)
            insert(&(*n)->left, newNode);
        else if ((*n)->value <= newNode->value)
            insert(&(*n)->right, newNode);
    }
}

int minValue(struct node *n)
{
    if (n == NULL)
        return 9999999999;

    int res = n->value;
    int lres = minValue(n->left);
    int rres = minValue(n->right);

    if (lres < res)
        res = lres;
    if (rres < res)
        res = rres;
    return res;
}