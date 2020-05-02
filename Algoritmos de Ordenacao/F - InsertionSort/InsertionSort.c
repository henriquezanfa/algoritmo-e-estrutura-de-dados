#include <stdio.h>
#include <stdlib.h>

void insertionSort(int array[], int size);
void print(int array[], int size);

int main()
{
    int size, i, trocas = 0;
    int array[10000];

    scanf("%d\n", &size);

    for (i = 0; i < size; i++)
    {
        scanf(" %d", &array[i]);
    }

    insertionSort(array, size);
}

void insertionSort(int array[], int size)
{
    for (int step = 1; step < size; step++)
    {
        int key = array[step];
        int j = step - 1;

        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }

        array[j + 1] = key;

        print(array, size);
    }
}

void print(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d%s", array[i], i < size - 1 ? " " : "\n");
    }
}