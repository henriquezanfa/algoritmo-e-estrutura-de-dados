#include <stdio.h>
#include <stdlib.h>

int *merge(int *arr1, int q1, int *arr2, int q2);
void print(int *arr, int size);

int main()
{
    int q1, q2;
    int *arr1, *arr2, *result;

    scanf("%d%d", &q1, &q2);

    arr1 = (int *)malloc(q1 * sizeof(int));
    arr2 = (int *)malloc(q2 * sizeof(int));

    for (int i = 0; i < q1; i++)
        scanf("%d", &arr1[i]);

    for (int i = 0; i < q2; i++)
        scanf("%d", &arr2[i]);

    result = merge(arr1, q1, arr2, q2);
    print(result, q1 + q2);

    return 0;
}

int *merge(int *arr1, int q1, int *arr2, int q2)
{
    int i, j, k;
    int *result = (int *)malloc((q1 + q2) * sizeof(int));

    i = 0;
    j = 0;
    k = 0;

    while (i < q1 && j < q2)
    {
        if (arr1[i] <= arr2[j])
        {
            result[k] = arr1[i];
            i++;
        }
        else
        {
            result[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < q1)
    {
        result[k] = arr1[i];
        i++;
        k++;
    }

    while (j < q2)
    {
        result[k] = arr2[j];
        j++;
        k++;
    }

    return result;
}

void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d\n", arr[i]);
}