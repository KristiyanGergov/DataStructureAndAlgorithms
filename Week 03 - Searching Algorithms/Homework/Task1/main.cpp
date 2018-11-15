#include <iostream>
#include <math.h>
using namespace std;

int* populateArr(int len) {
	int* arr = new int[len];
	for (int i = 0; i < len; i++)
		arr[i] = i + 1;
	return arr;
}

void findDays(int* arr, int l, int r, int & count) {
	if (l <= r)
	{
		if (arr[r] == 2 || arr[r] == 3)
		{
			count += 2;
			return;
		}

		int m = ceil((r + 1 + l) / 2.0);

		int midNum = arr[m - 1];

		for (int i = m; i <= r; i++)
		{
			arr[i] -= midNum;
		}
		count++;

		findDays(arr, m, r, count);
	}
}

int main() {
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		int * arr = populateArr(n);

		int val = 0;

		findDays(arr, 0, n - 1, val);

		cout << val << endl;

		delete[] arr;
	}

	return 0;
}