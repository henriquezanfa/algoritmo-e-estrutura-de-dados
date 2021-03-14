#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char value;
    struct node *left, *right;
};

struct node *createNode(char);
void insert(struct node **, struct node *);
int delete (struct node **, char);
struct node *deleteNode(struct node **);
void showPreOrder(struct node *);
void showInOrder(struct node *);
void showPostOrder(struct node *);

int main()
{
    struct node *root = NULL;
    char *command, value;

    command = (char *)malloc(sizeof(char) * 15);

    while (scanf("%s", command) != EOF)
    {
        if (strcmp("insert", command) == 0)
        {
            scanf(" %c", &value);
            insert(&root, createNode(value));
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
        else if (strcmp("delete", command) == 0)
        {
            scanf(" %c", &value);
            delete (&root, value);
        }
    }

    return 0;
}

struct node *createNode(char value)
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
    {
        *n = newNode;
    }
    else
    {
        if ((*n)->value <= newNode->value)
            insert(&(*n)->left, newNode);
        else
            insert(&(*n)->right, newNode);
    }
}

int delete (struct node **n, char value)
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
    struct node *node1, *node2;

    if ((*n)->left == NULL)
    {
        node2 = (*n)->right;
        free(*n);
    }
    else
    {
        node1 = *n;
        node2 = (*n)->left;

        while (node2->right != NULL)
        {
            node1 = node2;
            node2 = node2->right;
        }

        if (node1 != *n)
        {
            node1->right = node2->left;
            node2->left = (*n)->left;
        }

        node2->right = (*n)->right;
        free(*n);
    }

    return node2;
}

void showPreOrder(struct node *n)
{
    if (n == NULL)
        return;

    printf("%c ", n->value);

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

    printf("%c ", n->value);

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

    printf("%c ", n->value);
}