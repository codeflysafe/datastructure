#ifndef HEAP
#define HEAP
#include "common.h"

// heap
struct heap;

// Heap
typedef struct heap *Heap;

Heap make_empty(int cap);

void insert(Heap heap, Element e, compare_func cmp);

void delete_min(Heap heap, compare_func cmp);

#endif
