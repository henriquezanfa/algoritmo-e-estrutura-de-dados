#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *left, *right;
};

struct node *createNode(int);
void insert(struct node **, struct node *);
void showInOrder(struct node *);
int count(struct node *);

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

    showInOrder(root);

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
        if ((*n)->value == newNode->value)
            return;
        if ((*n)->value >= newNode->value)
            insert(&(*n)->left, newNode);
        else
            insert(&(*n)->right, newNode);
    }
}

void showInOrder(struct node *n)
{
    if (n == NULL)
        return;

    if (n->left != NULL)
        showInOrder(n->left);

    if (n->right == NULL && n->left == NULL)
        printf("%d\n", n->value);

    if (n->right != NULL)
        showInOrder(n->right);
}
