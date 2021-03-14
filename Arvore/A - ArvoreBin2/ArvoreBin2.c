#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int value;
    struct node *left, *right;
};

struct node *createNode(int);
void insert(struct node **, struct node *);
int delete(struct node **, int);
struct node *deleteNode(struct node **);
void showPreOrder(struct node *);
void showInOrder(struct node *);
void showPostOrder(struct node *);

int main()
{
    struct node *root = NULL;
    char *command;
    int value;

    command = (char *)malloc(sizeof(char) * 10);

    while (scanf("%s", command) != EOF)
    {
        if (strcmp("insert", command) == 0)
        {
            scanf("%d", &value);
            insert(&root, createNode(value));
        }
        else if (strcmp("delete", command) == 0)
        {
            scanf("%d", &value);
            if (delete(&root, value))
                printf("%d\n", value);
        }
        else if (strcmp("pre-order", command) == 0)
        {
            showPreOrder(root);
            if (root != NULL)
                printf("\n");
        }

        else if (strcmp("in-order", command) == 0)
        {
            showInOrder(root);
            if (root != NULL)
                printf("\n");
        }

        else if (strcmp("post-order", command) == 0)
        {
            showPostOrder(root);
            if (root != NULL)
                printf("\n");
        }
    }

    return 0;
}

struct node *createNode(int newValue)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = newValue;

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
        if ((*n)->value <= newNode->value)
            insert(&(*n)->left, newNode);
        else
            insert(&(*n)->right, newNode);
    }
}

int delete(struct node **n, int value)
{
    if (*n == NULL)
        return 0;
    else
    {
        struct node *prev = NULL;
        struct node *current = *n;

        while (current != NULL)
        {
            if (current->value == value)
            {
                if (current == *n)
                    *n = deleteNode(&current);
                else if (prev->left == current)
                    prev->left = deleteNode(&current);
                else
                    prev->right = deleteNode(&current);

                return 1;
            }

            prev = current;
            if (value <= current->value)
                current = current->right;
            else
                current = current->left;
        }
    }

    return 0;
}

struct node *deleteNode(struct node **n)
{
    struct node *n1, *n2;
    
    if ((*n)->left == NULL)
    {
        n2 = (*n)->right;
        free(*n);
    }
    else
    {
        n1 = *n;
        n2 = (*n)->left;

        while (n2->right != NULL)
        {
            n1 = n2;
            n2 = n2->right;
        }

        if (n1 != *n)
        {
            n1->right = n2->left;
            n2->left = (*n)->left;
        }

        n2->right = (*n)->right;
        free(*n);
    }

    return n2;
}

void showPreOrder(struct node *n)
{
    if (n == NULL)
        return;

    printf("%d ", n->value);

    if (n->right != NULL)
        showPreOrder(n->right);

    if (n->left != NULL)
        showPreOrder(n->left);
}

void showInOrder(struct node *n)
{
    if (n == NULL)
        return;

    if (n->right != NULL)
        showInOrder(n->right);
        
    printf("%d ", n->value);

    if (n->left != NULL)
        showInOrder(n->left);
}

void showPostOrder(struct node *n)
{
    if (n == NULL)
        return;

    if (n->right != NULL)
        showPostOrder(n->right);
    if (n->left != NULL)
        showPostOrder(n->left);

    printf("%d ", n->value);
}