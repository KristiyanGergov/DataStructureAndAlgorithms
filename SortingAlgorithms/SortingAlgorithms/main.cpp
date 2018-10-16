#include <iostream>
#include <algorithm>

using namespace std;

void print(int* arr, int len) {
	cout << "[";

	for (int i = 0; i < len; i++)
	{
		if (i == len - 1)
		{
			cout << " " << arr[i] << " ]" << endl;
			break;
		}
		cout << " " << arr[i] << ",";
	}
}

// Bubble
void bubbleSort(int* arr, int len) {
	for (int i = 0; i < len; i++)
	{
		bool flag = false;
		for (int j = 0; j < len - i - 1; j++)
		{
			int current = arr[j];
			int next = arr[j + 1];
			if (current > next)
			{
				swap(arr[j], arr[j + 1]);
				flag = true;
			}
		}
		if (!flag)
			break;
	}
}
// Bubble

//Selection
void selectionSort(int* arr, int len) {

	for (int i = 0; i < len; i++)
	{
		int minIndex = i;

		for (int j = i + 1; j < len; j++)
		{
			int current = arr[j];
			int min = arr[minIndex];

			if (current < min)
				minIndex = j;
		}
		swap(arr[minIndex], arr[i]);
	}
}
//Selection

//Insertion
void insertionSort(int* arr, int len) {

	for (int i = 1; i < len; i++)
	{
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
//Insertion

//Merge
void merge(int* arr, int l, int m, int r) {
	
	int i, j, k;

	int n1 = m - l + 1;
	int n2 = r - m;

	int* L = new int[n1];
	int* R = new int[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;


	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}

	delete[] L;
	delete[] R;
}

void mergeSort(int arr[], int l, int r) {

	if (l < r)
	{
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}
//Merge

int main() {

	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	mergeSort(arr, 0, 5);

	print(arr, 6);

	return 0;
}