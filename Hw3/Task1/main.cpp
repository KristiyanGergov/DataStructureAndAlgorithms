#include <iostream>
using namespace std;

int findDays(int* arr, int length, int t) {

	while (true)
	{
		for (int i = 0; i < length; i++)
		{
			
		}
	}
}


int main() {
	int t;

	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		int* arr = new int[n];

		for (int i = 0; i < n; i++)
			arr[i] = i + 1;

		cout << findDays(arr, i, t);

		delete[] arr;
	}

	return 0;
}