#include<iostream> 
#include<climits> 
#include<queue>

using namespace std;

int main()
{
	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> minHeap;
	priority_queue<int, vector<int>, less<int>> maxHeap;

	double currentMedian = 0;

	for (int i = 0; i < n; i++)
	{
		long current;

		scanf_s("%ld", &current);

		if (current > currentMedian)
			minHeap.push(current);
		else
			maxHeap.push(current);

		int minHeapSize = minHeap.size();
		int maxHeapSize = maxHeap.size();

		if (minHeapSize + 1 < maxHeapSize)
		{
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		}
		else if (maxHeapSize + 1 < minHeapSize)
		{
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}

		minHeapSize = minHeap.size();
		maxHeapSize = maxHeap.size();

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