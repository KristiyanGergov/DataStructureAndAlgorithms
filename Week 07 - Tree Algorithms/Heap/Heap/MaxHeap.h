#pragma once
#include "Heap.h"

class MaxHeap : public Heap
{
public:
	MaxHeap(int);
	void Heapify(int) override;
	void insertKey(int k);
};