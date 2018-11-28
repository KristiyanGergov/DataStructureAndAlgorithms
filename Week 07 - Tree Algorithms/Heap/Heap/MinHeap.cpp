#include "MinHeap.h"

MinHeap::MinHeap(int cap) : Heap(cap)
{
}

void MinHeap::Heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(harr[i], harr[smallest]);
		Heapify(smallest);
	}
}

void MinHeap::insertKey(int k)
{
	if (heap_size == capacity)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}

	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;

	while (i != 0 && harr[parent(i)] > harr[i])
	{
		swap(harr[i], harr[parent(i)]);
		i = parent(i);
	}
}
