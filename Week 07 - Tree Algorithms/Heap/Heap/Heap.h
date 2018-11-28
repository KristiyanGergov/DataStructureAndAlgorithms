#pragma once
#include <iostream>

using namespace std;

class Heap
{

protected:
	int *harr;
	int capacity;
	int heap_size;

	int parent(int i) { return (i - 1) / 2; }

	int left(int i) { return (2 * i + 1); }

	int right(int i) { return (2 * i + 2); }

public:

	Heap(int capacity);

	int extractTop();

	int top() { return harr[0]; }

	int getSize();

	virtual void Heapify(int) = 0;

};