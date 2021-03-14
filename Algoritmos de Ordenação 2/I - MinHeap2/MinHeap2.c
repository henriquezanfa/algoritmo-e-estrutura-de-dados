#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 2147483647

struct MinHeap
{
    int *itens, size, maxSize;
};

struct MinHeap *init(int n);
void heapify(struct MinHeap *, int);
void insert(struct MinHeap *, int);
void delete (struct MinHeap *, int);
void print(struct MinHeap *);
void swap(int *a, int *b);

int main()
{
    int n, op, value;
    struct MinHeap *heap;

    scanf("%d\n", &n);
    heap = init(n);

    while (n--)
    {
        scanf("%d", &op);

        if (op == 1)
        {
            scanf("%d", &value);
            insert(heap, value);
        }
        else if (op == 2)
        {
            scanf("%d", &value);
            delete (heap, value);
        }
        else
            printf("%d\n", heap->itens[0]);
    }

    return 0;
}

struct MinHeap *init(int n)
{
    struct MinHeap *heap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    heap->itens = (int *)malloc(n * sizeof(int));
    heap->size = 0;
    heap->maxSize = n;

    return heap;
}

void heapify(struct MinHeap *heap, int i)
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

void insert(struct MinHeap *heap, int novoValor)
{
    heap->itens[heap->size] = novoValor;
    heap->size++;

    for (int i = (heap->size / 2) - 1; i >= 0; i--)
        heapify(heap, i);
}

void delete (struct MinHeap *heap, int value)
{
    int remove = 0;
    for (int i = 0; i < heap->size && !remove; i++)
    {
        if (heap->itens[i] == value)
        {
            heap->itens[i] = INT_MAX;
            remove = 1;
        }
    }

    for (int i = (heap->size / 2) - 1; i >= 0; i--)
        heapify(heap, i);

    heap->size--;
}

void print(struct MinHeap *heap)
{
    for (int i = 0; i < heap->size; i++)
    {
        printf("%d%c", heap->itens[i], i == heap->size - 1 ? '\n' : ' ');
    }
}