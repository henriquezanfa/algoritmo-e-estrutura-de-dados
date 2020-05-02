#include <stdio.h>
#include <stdlib.h>

void insertionSort(int array[], int size, int *trocas);

int main()
{
    int size, i, trocas = 0;
    int array[10000];

    scanf("%d\n", &size);

    for (i = 0; i < size; i++)
    {
        scanf(" %d", &array[i]);
    }

    insertionSort(array, size, &trocas);

    printf("%d\n", trocas);
}

void insertionSort(int array[], int size, int *trocas)
{
    int aux = 0;
    for (int step = 1; step < size; step++)
    {
        int key = array[step];
        int j = step - 1;

        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
            aux++;
        }

        array[j + 1] = key;
    }
    *trocas = aux;
}