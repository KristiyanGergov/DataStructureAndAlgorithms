#include <iostream>
using namespace std;

int findMaxIndex(int* arr, int length) {
	int max = 0;

	for (int i = 0; i < length; i++)
	{
		if (arr[i] > arr[max])
		{
			max = i;
		}
	}
	return max;
}

bool reducåAll(int* arr, int len, int indexNotToReduce) {
	bool allZeroes = true;
	for (int i = 0; i < len; i++)
	{
		if (i != indexNotToReduce && arr[i] > 0)
		{
			allZeroes = false;
			arr[i]--;
		}
	}
	return allZeroes;
}

int main() {

	int n, k;

	cin >> n;
	cin >> k;

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		arr[i] = num;
	}
	int counter = 0;

	while (true)
	{
		int index = findMaxIndex(arr, n);
		arr[index] -= k;

		bool allZeroes = reducåAll(arr, n, index);


		if (allZeroes)
			break;

		counter++;
	}

	cout << counter;

	delete[] arr;
	return 0;
}
