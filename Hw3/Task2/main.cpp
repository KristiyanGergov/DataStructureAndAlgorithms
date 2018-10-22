#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findIndex(int* arr, int start, int end, int num) {

	if (start <= end)
	{
		int mid = start + (end - start) / 2;

		if (arr[mid] == num)
			return mid;

		if (arr[mid] > num)
			return findIndex(arr, start, mid, num);

		if (arr[mid] < num)
			return findIndex(arr, mid + 1, end, num);
	}

	return -1;
}

int main() {
	int n;
	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		int curr;
		cin >> curr;
		arr[i] = curr;
	}

	int q;
	cin >> q;

	for (int i = 0; i < q; i++)
	{
		int num;
		cin >> num;

		int index = findIndex(arr, 0, n - 1, num);

		if (index == -1)
		{
			cout << "-1 -1" << endl;
			continue;
		}

		int first = index + 1;
		int last = index + 1;

		for (int i = index; i < n; i++)
		{
			if (arr[index] == arr[i] && i == n - 1)
			{
				last = i + 1;
				break;
			}
			if (arr[index] != arr[i])
			{
				last = i;
				break;
			}
		}

		for (int i = index; i >= 0; i--)
		{
			if (arr[index] == arr[i] && i == 0)
			{
				first = i + 1;
				break;
			}
			if (arr[index] != arr[i])
			{
				first = i + 2;
				break;
			}
		}

		cout << first << " " << last << endl;
	}

	delete[] arr;
	return 0;
}