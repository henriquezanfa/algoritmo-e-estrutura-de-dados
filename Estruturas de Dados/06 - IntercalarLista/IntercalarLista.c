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

void printList(struct list list)
{
    struct node *current = list.first;
    while (current != NULL)
    {
        printf("%d%c", current->data, current->next == NULL ? '\n' : ' ');
        current = current->next;
    }
}

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
//find a link with given key
struct node *find(struct list *list, int data)
{
    struct node *current = list->first;

    if (list->first == NULL)
    {
        return NULL;
    }

    while (current->data != data)
    {
        if (current->next == NULL)
        {
            return NULL;
        }
        else
        {
            current = current->next;
        }
    }

    return current;
}
void insert(struct list *list, struct node *new)
{
    struct node *prev = NULL, *current = list->first;

    while (current != NULL && current->data < new->data)
    {
        prev = current;
        current = current->next;
    }

    if (prev != NULL)
    {
        prev->next = new;
    }
    else
    {
        list->first = new;
    }

    new->next = current;
}

struct list *mergeLists(struct list *list1, struct list *list2)
{
    struct list *mergedLists = newList();
    struct node *current = list1->first;

    while (current != NULL)
    {
        insert(mergedLists, newItem(current->data));
        current = current->next;
    }

    current = list2->first;

    while (current != NULL)
    {
        insert(mergedLists, newItem(current->data));
        current = current->next;
    }

    return mergedLists;
}

int main()
{
    char command;
    int tamanhoLista1, tamanhoLista2, numeroListas, i, j, valorLido;
    struct list *list1, *list2, *mergedLists;

    scanf("%d", &numeroListas);

    for (i = 0; i < numeroListas; i++)
    {
        list1 = newList();
        list2 = newList();

        scanf("%d", &tamanhoLista1);
        if (tamanhoLista1 != 0)
        {
            for (j = 0; j < tamanhoLista1; j++)
            {
                scanf("%d", &valorLido);
                if (find(list1, valorLido) == NULL)
                    insert(list1, newItem(valorLido));
            }
        }

        scanf("%d", &tamanhoLista2);
        if (tamanhoLista2 != 0)
        {
            for (j = 0; j < tamanhoLista2; j++)
            {
                scanf("%d", &valorLido);
                if (find(list2, valorLido) == NULL)
                    insert(list2, newItem(valorLido));
            }
        }

        mergedLists = mergeLists(list1, list2);

        printList(*mergedLists);
    }

    return 0;
}