#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

int main() {
	int n;
	cin >> n;

	Node* balls = new Node[n + 1]();
	Node node;
	node.data = 0;
	node.next = nullptr;
	balls[0] = node;

	long sum = 0;
	int* arr = new int[n + 1];
	arr[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		int p, m;
		cin >> p;
		cin >> m;

		if (m != 0)
		{
			node.data = m;
			node.next = &balls[p];
			balls[i] = node;
			arr[i] = arr[p] + m;
			sum += arr[i];
		}
		else
		{
			balls[i] = *balls[p].next;
			arr[i] = arr[p] - balls[p].data;
			sum += arr[i];
		}
	}
	cout << sum;

	return 0;
}