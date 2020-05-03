#include <stdio.h>
#include <stdlib.h>

float mediana(int array[], int size);
void invert(int *a, int *b);
void bubble(int vector[], int size);

int main()
{
    int size, i;
    int array[10000];

    scanf("%d\n", &size);

    for (i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    bubble(array, size);

    printf("%.2f\n", mediana(array, size));
}

void bubble(int vector[], int size)
{
    int i, j, troca = 0;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                invert(&vector[j], &vector[j + 1]);
            }
        }
    }
}

void invert(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

float mediana(int array[], int size)
{
    float med = 0;
    if (size % 2 == 0)
    {
        float aux = (array[(size / 2) - 1] + array[size / 2]);
        med = aux / 2;
    }
    else
    {
        med = array[(size / 2)];
    }

    return med;
}