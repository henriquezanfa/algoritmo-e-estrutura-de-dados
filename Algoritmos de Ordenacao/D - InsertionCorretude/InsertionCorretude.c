#include <stdio.h>
#include <stdlib.h>

void insertionSort(int vector[], int size);
void print(int vector[], int from, int to);

int main()
{
    int size, i;
    int vector[10000];

    scanf("%d\n", &size);

    for (i = 0; i < size; i++)
    {
        scanf(" %d", &vector[i]);
    }

    insertionSort(vector, size);
}

void insertionSort(int vector[], int size)
{
    int i, j, aux;

    for (i = 1; i < size; i++)
    {
        aux = vector[i];

        printf("Sublista Ordenada: ");
        print(vector, 0, i);

        printf("Sublista Desordenada: ");
        print(vector, i, size);

        for (j = i; (j > 0) && (aux < vector[j - 1]); j--)
        {
            vector[j] = vector[j - 1];
        }
        vector[j] = aux;
    }

    printf("Sublista Ordenada: ");
    print(vector, 0, size);

    printf("Sublista Desordenada:\n");
}

void print(int vector[], int from, int to)
{
    int i;
    for (i = from; i < to; i++)
    {
        printf("%d%s", vector[i], i < to - 1 ? " " : "\n");
    }
}