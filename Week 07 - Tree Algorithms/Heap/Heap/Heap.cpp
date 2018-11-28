#include "Heap.h"

Heap::Heap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}

int Heap::getSize()
{
	return this->heap_size;
}

int Heap::extractTop()
{
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}

	int root = harr[0];
	harr[0] = harr[heap_size - 1];
	heap_size--;
	Heapify(0);

	return root;
}