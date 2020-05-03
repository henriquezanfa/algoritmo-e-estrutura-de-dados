#include <stdio.h>
#include <stdlib.h>

void marcianoSort(int array[], int size);
int marcianoToDecimal(int a);
int equivalenteMarciano(int a);
int getDecimal(int a, int decimalPlace);

int main()
{
    int size, i;
    int *array;

    scanf("%d\n", &size);

    array = (int *)malloc(sizeof(int) * size);

    for (i = 0; i < size; i++)
        scanf(" %d", &array[i]);

    marcianoSort(array, size);

    for (i = 0; i < size; i++)
        printf("%d%c", array[i], i == size - 1 ? '\n' : ' ');

    return 0;
}

void marcianoSort(int array[], int size)
{
    int i, j, min = 0;

    for (i = 1; i < size; i++)
    {
        min = array[i];
        j = i - 1;

        while (j >= 0 && marcianoToDecimal(min) < marcianoToDecimal(array[j]))
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = min;
    }
}

int marcianoToDecimal(int a)
{
    int decimalPlace = 1, multiplicador = 1, resultado = 0, aux;

    while (a * 10 > multiplicador)
    {
        aux = equivalenteMarciano(getDecimal(a, decimalPlace));
        resultado += aux * multiplicador;

        decimalPlace++;
        multiplicador *= 10;
    }

    return resultado;
}

int equivalenteMarciano(int a)
{
    int arrayMarciano[10] = {0, 5, 6, 4, 8, 9, 7, 3, 1, 2};
    int i;
    for (i = 0; i < 10; i++)
        if (arrayMarciano[i] == a)
            return i;
}

int getDecimal(int a, int decimalPlace)
{
    int modulo = 1, divisor = 1;

    for (int i = 0; i < decimalPlace; i++)
        modulo *= 10;

    for (int i = 1; i < decimalPlace; i++)
        divisor *= 10;

    return (a % modulo) / divisor;
}