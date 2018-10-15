#include <iostream>
using namespace std;


int main() {
	int q, n;

	cin >> q;

	for (int i = 0; i < q; i++)
	{
		cin >> n;
		int* arr = new int[n];
		int count = 0;

		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;
			arr[j] = num;

			for (int k = 0; k < j; k++)
			{
				if (arr[k] > arr[j])
				{
					count++;
				}
			}
		}
		cout << count << endl;
		delete[] arr;

	}

	return 0;
}