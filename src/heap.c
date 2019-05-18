#include <stdlib.h>
#include "./include/heap.h"

struct heap
{
    Element *elements;
    int cap;
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
    return heap;
};


