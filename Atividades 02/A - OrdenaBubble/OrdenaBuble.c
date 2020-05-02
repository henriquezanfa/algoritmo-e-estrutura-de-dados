#include <stdio.h>
#include <stdlib.h>

void invert(int *a, int *b);
void bubble(int vector[], int size, int *trocas);
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
    bubble(vector, size, &trocas);
    print(vector, size);

    printf("Trocas: %d\n", trocas);
}

void bubble(int vector[], int size, int *trocas)
{
    int i, j, troca = 0;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                invert(&vector[j], &vector[j + 1]);
                troca++;
                print(vector, size);
            }
        }
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