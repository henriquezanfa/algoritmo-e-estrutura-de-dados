#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size, *arr, value, aux = 0;

    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &value);

    for (int i = 0; i < size; i++)
        if (arr[i] < value)
            aux++;

    printf("%d\n", aux);

    return 0;
}