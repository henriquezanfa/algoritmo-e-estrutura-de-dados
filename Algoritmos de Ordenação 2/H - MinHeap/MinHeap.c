#include <stdio.h>
#include <stdlib.h>

struct maxHeap
{
    int *itens, size;
};

struct maxHeap *init(int n);
void heapify(struct maxHeap *, int);
void print(int *, int);
void swap(int *a, int *b);

int main()
{
    int size;
    struct maxHeap *heap;
    scanf("%d\n", &size);

    do
    {
        heap = init(size);
        for (int i = 0; i < size; i++)
            scanf("%d", &heap->itens[i]);

        for (int i = (heap->size / 2) - 1; i >= 0; i--)
            heapify(heap, i);

        print(heap->itens, heap->size);

        scanf("%d", &size);

    } while (size);

    return 0;
}

struct maxHeap *init(int n)
{
    struct maxHeap *heap = (struct maxHeap *)malloc(sizeof(struct maxHeap));
    heap->itens = (int *)malloc(n * sizeof(int));
    heap->size = n;

    return heap;
}

void heapify(struct maxHeap *heap, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int n = heap->size;

    if (left < n && heap->itens[left] <= heap->itens[largest])
        largest = left;

    if (right < n && heap->itens[right] <= heap->itens[largest])
        largest = right;

    if (largest != i)
    {
        swap(&heap->itens[i], &heap->itens[largest]);
        heapify(heap, largest);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print(int *vetor, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", vetor[i], i == n - 1 ? '\n' : ' ');
    }
}