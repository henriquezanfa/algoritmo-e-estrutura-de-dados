#include <stdio.h>
#include <stdlib.h>

void invert(int *a, int *b);
void selectionSort(int vector[], int size, int *trocas);
void print(int vector[], int size);

int main()
{
    int size, i, trocas = 0;
    int vector[10000];

    scanf("%d\n", &size);

    for (i = 0; i < size; i++)
    {
        scanf(" %d", &vector[i]);
    }

    print(vector, size);
    selectionSort(vector, size, &trocas);
    print(vector, size);

    printf("%d\n", trocas);
}

void selectionSort(int vector[], int size, int *trocas)
{
    int i, j, min = 0, troca = 0;

    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (vector[j] < vector[min])
            {
                min = j;
                troca++;
            }
        }
        // if (vector[min] < vector[i])
        // {
            invert(&vector[min], &vector[i]);
            print(vector, size);
        // }
    }
    *trocas = troca;
}

void invert(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void print(int vector[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d%s", vector[i], i < size - 1 ? " " : "\n");
    }
}