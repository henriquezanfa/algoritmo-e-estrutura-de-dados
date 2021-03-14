#include <string.h>

struct node
{
    int value;
    struct node *left, *right;
};

struct node *createNode(int);
void insert(struct node **, struct node *);
int getHeight(struct node *);

int main()
{
    struct node *root = NULL;
    int value, size, i;

    scanf("%d", &size);

    for (i = 0; i < size; i++)
    {
        scanf("%d", &value);
        insert(&root, createNode(value));
    }

    printf("%d\n", getHeight(root));

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

void insert(struct node **n, struct node *novoNode)
{
    if (*n == NULL)
        *n = novoNode;
    else
    {
        if ((*n)->value > novoNode->value)
            insert(&(*n)->left, novoNode);
        else if ((*n)->value < novoNode->value)
            insert(&(*n)->right, novoNode);
    }
}

int getHeight(struct node *node)
{
    if (node == NULL || (node->right == NULL && node->left == NULL))
        return 0;

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    if (leftHeight > rightHeight)
        return (leftHeight + 1);
    else
        return (rightHeight + 1);
}