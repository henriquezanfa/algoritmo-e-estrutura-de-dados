#include <stdio.h>
#include <stdlib.h>

char isOrdered(int array[], int size);

int main()
{
    int size, i;
    int array[10000];

    while (scanf("\n%d", &size) != EOF)
    {
        for (i = 0; i < size; i++)
        {
            scanf(" %d", &array[i]);
        }

        printf("%c\n", isOrdered(array, size));
    }
}

char isOrdered(int array[], int size)
{
    char ordered = 'S';
    int i;

    for (i = 0; i < size - 1; i++)
    {
        if (array[i + 1] > array[i])
            ordered = 'N';
    }

    return ordered;
}