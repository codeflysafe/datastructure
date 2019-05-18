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
    while ((p * 2 + 1) < heap->size)
    {
        int left = p * 2 + 1;
        if (left + 1 < heap->size && (cmp(heap->elements[left + 1], heap->elements[left]) < 0))
        {
            left++;
        }
        if (cmp(heap->elements[left], heap->elements[p]) < 0)
        {
            swap(heap->elements[left], heap->elements[p]);
            p = left;
        }
        else
        {
            break;
        }
    }
    return;
}
