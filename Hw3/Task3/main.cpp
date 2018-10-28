#include <iostream>
using namespace std;

bool reduceAll(int* arr, int len, int k, int index) {
	bool allZeroes = true;
	int driyersLeft = index;

	for (int i = 0; i < len; i++)
	{

		if (arr[i] - index > 0)
		{
			int count = 1;
			bool flag = false;
			while (driyersLeft > 0)
			{
				driyersLeft--;
				if (arr[i] - k * count - (index - count) > 0)
				{
					count++;
				}
				else
				{
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				allZeroes = false;
				break;
			}
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


	int index = 1;
	bool allZeroes = false;

	while (!allZeroes)
	{
		bool flag = false;
		allZeroes = reduceAll(arr, n, k, index);

		if (allZeroes)
			break;

		index *= 2;
	}

	while (allZeroes && index > 0) {
		allZeroes = reduceAll(arr, n, k, index);
		index--;
	}

	cout << index + 2;

	delete[] arr;
	return 0;
}