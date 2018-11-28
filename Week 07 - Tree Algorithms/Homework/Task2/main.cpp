#include<iostream> 
#include<climits> 

using namespace std;

// H E A P
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

	int pop();

	int top() { return harr[0]; }

	int getSize();

	virtual void Heapify(int) = 0;
};

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

int Heap::pop()
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
// H E A P

//M A X	  H E A P
class MaxHeap : public Heap
{
public:
	MaxHeap(int);
	void Heapify(int) override;
	void push(int k);
};

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

void MaxHeap::push(int k)
{
	if (heap_size == capacity)
	{
		cout << "\nOverflow: Could not push\n";
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

//M A X	  H E A P
class MinHeap : public Heap
{
public:
	MinHeap(int);
	void Heapify(int) override;
	void push(int k);
};

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

void MinHeap::push(int k)
{
	if (heap_size == capacity)
	{
		cout << "\nOverflow: Could not push\n";
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


//M I N   H E A P

int main()
{
	int n;
	cin >> n;

	MinHeap minHeap = MinHeap(n / 2 + 1);
	MaxHeap maxHeap = MaxHeap(n / 2 + 1);

	double currentMedian = 0;

	for (int i = 0; i < n; i++)
	{
		long current;

		scanf_s("%ld", &current);

		if (current > currentMedian)
			minHeap.push(current);
		else
			maxHeap.push(current);

		int minHeapSize = minHeap.getSize();
		int maxHeapSize = maxHeap.getSize();

		if (minHeapSize + 1 < maxHeapSize)
		{
			minHeap.push(maxHeap.pop());
		}
		else if (maxHeapSize + 1 < minHeapSize)
		{
			maxHeap.push(minHeap.pop());
		}

		minHeapSize = minHeap.getSize();
		maxHeapSize = maxHeap.getSize();

		if (minHeapSize > maxHeapSize)
			currentMedian = minHeap.top();
		else if (maxHeapSize > minHeapSize)
			currentMedian = maxHeap.top();
		else
			currentMedian = ((double)minHeap.top() + maxHeap.top()) / 2;

		printf("%.1f\n", currentMedian);

	}

	return 0;
}