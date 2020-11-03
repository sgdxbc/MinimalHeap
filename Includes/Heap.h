//

#ifndef NOMALLOC_INCLUDES_HEAP_H
#define NOMALLOC_INCLUDES_HEAP_H

#include <stddef.h>
#include <string.h>

typedef void *Raw;
typedef size_t Size;
typedef struct HeapLayout Heap;

Heap *CreateHeap(Raw raw, Size userSize);

Raw AllocateObject(Heap *heap, Size userSize);

Raw ResizeObject(Heap *heap, Raw object, Size size);

void ReleaseObject(Heap *heap, Raw object);

static Raw AllocateZeroedObjectList(Heap *heap, Size count, Size size)
{
    Raw allocated = AllocateObject(heap, count * size);
    if (allocated)
    {
        memset(allocated, 0x00, count * size);
    }
    return allocated;
}

#endif