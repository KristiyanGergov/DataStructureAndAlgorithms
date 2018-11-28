#include "MaxHeap.h"

MaxHeap::MaxHeap(int cap) : Heap(cap)
{
}

void MaxHeap::Heapify(int i)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;
	if (l < heap_size && harr[l] > harr[i])
		largest = l;
	if (r < heap_size && harr[r] > harr[largest])
		largest = r;
	if (largest != i)
	{
		swap(harr[i], harr[largest]);
		Heapify(largest);
	}
}

void MaxHeap::insertKey(int k)
{
	if (heap_size == capacity)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}

	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;

	while (i != 0 && harr[parent(i)] < harr[i])
	{
		swap(harr[i], harr[parent(i)]);
		i = parent(i);
	}
}
