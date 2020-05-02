#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct list
{
    struct node *first, *last;
};

void printListStartToEnd(struct list *list)
{
    struct node *current = list->first;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void printListEndToStart(struct list *list)
{
    struct node *current = list->last;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

//find a link with given key
struct node *find(struct list *list, int data)
{
    struct node *current = list->first;

    if (list->first == NULL)
        return NULL;

    while (current->data != data)
    {
        if (current->next == NULL)
            return NULL;
        else
            current = current->next;
    }

    return current;
}

struct list *newList()
{
    struct list *list = (struct list *)malloc(sizeof(struct list));

    list->first = NULL;
    list->last = NULL;

    return list;
}

struct node *newItem(int data)
{
    struct node *cell = (struct node *)malloc(sizeof(struct node));
    if (cell != NULL)
    {
        cell->data = data;
        cell->next = NULL;
        cell->prev = NULL;
    }
    return cell;
}

void insert(struct list *list, struct node *new)
{
    struct node *prev = NULL, *current = list->first;

    if (current == NULL)
    {
        list->first = new;
        list->last = new;
        return;
    }

    while (current != NULL && current->data < new->data)
    {
        prev = current;
        current = current->next;
    }

    if (prev == NULL)
    {
        list->first = new;
        new->next = current;
        current->prev = new;
    }
    else if (current == NULL)
    {
        prev->next = new;
        new->prev = prev;
        list->last = new;
    }
    else
    {
        prev->next = new;
        new->prev = prev;
        current->prev = new;
        new->next = current;
    }
}

void delete (struct list *list, int data)
{
    struct node *current = list->first;

    if (current == NULL)
        return;

    while (current != NULL && current->data != data)
        current = current->next;

    if (current != NULL)
    {
        if (current->prev == NULL)
            list->first = current->next;
        else
            current->prev->next = current->next;

        if (current->next == NULL)
            list->last = current->prev;
        else
            current->next->prev = current->prev;
    }

    free(current);
}

int main()
{
    char command;
    int value;
    struct list *list = newList();

    while (scanf("\n%c", &command) != EOF)
    {
        if (command == 'I' || command == 'E')
            scanf("%d", &value);
        if (command == 'I')
        {
            if (find(list, value) == NULL)
                insert(list, newItem(value));
        }

        else if (command == 'E')
            delete (list, value);
        else if (command == 'M')
            printListStartToEnd(list);
        else if (command == 'R')
            printListEndToStart(list);
    }

    return 0;
}