#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct list
{
    struct node *first;
};

struct list *newList()
{
    struct list *list = (struct list *)malloc(sizeof(struct list));
    if (list != NULL)
    {
        list->first = NULL;
    }
    return list;
}

struct node *newItem(int data)
{
    struct node *cell = (struct node *)malloc(sizeof(struct node));
    if (cell != NULL)
    {
        cell->data = data;
        cell->next = NULL;
    }
    return cell;
}

void insertAtFirst(struct list *list, struct node *new)
{
    struct node *current = list->first;

    new->next = current;
    list->first = new;
}

void printReverseList(struct node *node)
{
    struct node *current = node;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main()
{
    int tamanhoLista, numeroListas, i, j, valorLido;
    struct list *list;

    scanf("%d", &numeroListas);

    for (i = 0; i < numeroListas; i++)
    {
        list = newList();
        scanf("%d", &tamanhoLista);
        if (tamanhoLista != 0)
        {
            for (j = 0; j < tamanhoLista; j++)
            {
                scanf("%d", &valorLido);
                insertAtFirst(list, newItem(valorLido));
            }
        }

        printReverseList(list->first);
    }

    return 0;
}