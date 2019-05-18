#include <stdlib.h>
#include "./include/heap.h"

struct heap
{
    Element *elements;
    int cap;
    int size;
};

Heap make_empty(int cap)
{
    if (cap <= 0 || cap > MAXIMUM_CAPACITY)
    {
        cap = DEFAULT_HEAP_SIZE;
    }
    Element *elements = (Element *)malloc(cap * sizeof(Element));
    Heap heap = (Heap)malloc(sizeof(Heap));
    heap->elements = elements;
    heap->cap = cap;
    heap->size = 0;
    return heap;
};

void insert(Heap heap, Element e, compare_func cmp)
{
    if (heap->size >= heap->cap)
    {
        return;
    }
    heap->elements[heap->size] = e;
    //  调整
    int p = heap->size;
    while (p > 0)
    {
        Element parent = heap->elements[(p - 1) / 2];
        if (cmp(e, parent) < 0)
        {
            swap(e, parent);
            p = (p - 1) / 2;
        }
        else
        {
            break;
        }
    }
    heap->size++;
    return;
}

void delete_min(Heap heap, compare_func cmp)
{
    if (heap->size == 0)
    {
        return;
    }
    heap->elements[0] = heap->elements[heap->size - 1];

    int p = 0;
    heap->size--;
    while (p < heap->size)
    {
        int right = 2 * p + 2;
        int left = right - 1;
        if (right < heap->size)
        {
            int temp = cmp(heap->elements[right], heap->elements[left]) < 0 ? right : left;
            p = cmp(heap->elements[p], heap->elements[temp]) < 0 ? p : temp;
        }
        else if (left < heap->size)
        {
            p = cmp(heap->elements[p], heap->elements[left]) < 0 ? p : left;
        }
        else
        {
            break;
        }
    }
    return;
}
