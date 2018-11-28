#pragma once

#include "Heap.h"

class MinHeap : public Heap
{
public:
	MinHeap(int);
	void Heapify(int) override;
	void insertKey(int k);
};