#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

struct list
{
    struct node *first;
};

//display the list
void printList(struct list list)
{
    struct node *current = list.first;
    //start from the beginning
    while (current != NULL)
    {
        printf("%d%s", current->data, current->next == NULL ? "\n" : " ");
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

    //start from the first link
    struct node *current = list->first;

    //if list is empty
    if (list->first == NULL)
    {
        return NULL;
    }

    //navigate through list
    while (current->data != data)
    {

        //if it is last node
        if (current->next == NULL)
        {
            return NULL;
        }
        else
        {
            //go to next link
            current = current->next;
        }
    }

    //if data found, return the current Link
    return current;
}
void insert(struct list *list, struct node *new)
{
    struct node *prev = NULL, *current = list->first;

    if (find(list, new->data) != NULL)
        return;

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

//delete a link with given key
struct node *delete (struct list *list, int data)
{

    //start from the first link
    struct node *current = list->first;
    struct node *previous = NULL;

    //if list is empty
    if (current == NULL)
    {
        return NULL;
    }

    //navigate through list
    while (current->data != data)
    {

        //if it is last node
        if (current->next == NULL)
        {
            return NULL;
        }
        else
        {
            //store reference to current link
            previous = current;
            //move to next link
            current = current->next;
        }
    }

    //found a match, update the link
    if (current == list->first)
    {
        //change first to point to next link
        list->first = list->first->next;
    }
    else
    {
        //bypass the current link
        previous->next = current->next;
    }

    return current;
}

void contains(struct list *list, int data)
{
    if (find(list, data) != NULL)
    {
        printf("SIM\n");
    }
    else
    {
        printf("NAO\n");
    }
}

int main()
{
    char command;
    int value;
    struct list *list = newList();

    // insert(list, newItem(3));
    // insert(list, newItem(4));
    // insert(list, newItem(2));
    // printList(*list);
    // delete (*list, 3);
    // printList(*list);
    // contains(*list, 5);
    // contains(*list, 4);

    while (scanf("\n%c", &command) != EOF)
    {
        // printf("NOVO COMANDO: %c ", command);
        if (command == 'I' || command == 'R' || command == 'B')
        {
            scanf("%d", &value);
            // printf("VALOR: %d", value);
        }
        // printf("\n");

        if (command == 'I')
        {
            insert(list, newItem(value));
        }
        else if (command == 'R')
        {
            delete (list, value);
        }
        else if (command == 'B')
        {
            contains(list, value);
        }
        else if (command == 'L')
        {
            printList(*list);
        }
    }

    return 0;
}