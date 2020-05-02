#include <stdio.h>
#include <stdlib.h>

struct list
{
    int *data;
    int maxSize, first, last;
};

struct list *newList(int maxSize)
{
    struct list *list = (struct list *)malloc(sizeof(struct list));

    list->data = (int *)malloc(sizeof(int) * maxSize);
    list->first = 0;
    list->last = 0;
    list->maxSize = maxSize;

    return list;
}

void insert(struct list *list, int val)
{

    int newLast = (list->last + 1) % list->maxSize;
    if (newLast != list->first)
    {
        list->data[list->last] = val;
        list->last = newLast;
    }
}

int delete (struct list *list)
{

    int removed = -1;

    if (list->last != list->first)
    {
        removed = list->data[list->first];
        list->first = (list->first + 1) % list->maxSize;
    }

    return removed;
}

int main()
{
    char command;
    int size, value, removed;
    struct list *list;

    scanf("%d", &size);

    list = newList(size);
    while (scanf("\n%c", &command) != EOF)
    {
        if (command == 'E')
        {
            scanf(" %d", &value);
            insert(list, value);
        }
        else if (command == 'D')
        {
            removed = delete (list);
            if (removed != -1)
                printf("%d\n", removed);
        }
    }

    return 0;
}