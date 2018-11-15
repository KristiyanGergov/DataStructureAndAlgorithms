#include <iostream>

using namespace std;

long _mergeSort(long arr[], long temp[], long left, long right);
long merge(long arr[], long temp[], long left, long mid, long right);

long mergeSort(long arr[], long array_size)
{
	long* temp = (long*)malloc(sizeof(long) * array_size);
	return _mergeSort(arr, temp, 0, array_size - 1);
}

long _mergeSort(long arr[], long temp[], long left, long right)
{
	long mid, inv_count = 0;
	if (right > left) {
		mid = (right + left) / 2;

		inv_count = _mergeSort(arr, temp, left, mid);
		inv_count += _mergeSort(arr, temp, mid + 1, right);


		inv_count += merge(arr, temp, left, mid + 1, right);
	}
	return inv_count;
}

long merge(long arr[], long temp[], long left, long mid, long right)
{
	long i, j, k;
	long inv_count = 0;

	i = left; 
	j = mid; 
	k = left; 
	while ((i <= mid - 1) && (j <= right)) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];

			inv_count = inv_count + (mid - i);
		}
	}

	while (i <= mid - 1)
		temp[k++] = arr[i++];

	while (j <= right)
		temp[k++] = arr[j++];

	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}


int main() {
	long q, n;

	cin >> q;

	for (long i = 0; i < q; i++)
	{
		cin >> n;
		long* arr = new long[n];

		for (long j = 0; j < n; j++)
		{
			long num;
			cin >> num;
			arr[j] = num;
		}

		long count = mergeSort(arr, n);

		cout << count << endl;
		delete[] arr;
	}


	return 0;
}