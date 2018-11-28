#include "MaxHeap.h"
#include "MinHeap.h"

int main() {

	MaxHeap maxHeap = MaxHeap(4);

	maxHeap.insertKey(1);
	maxHeap.insertKey(2);
	maxHeap.insertKey(3);
	maxHeap.insertKey(4);
	maxHeap.insertKey(5);

	MinHeap minHeap = MinHeap(4);
	minHeap.insertKey(4);
	minHeap.insertKey(3);
	minHeap.insertKey(2);
	minHeap.insertKey(1);

	int a = 5;

	return 0;
}