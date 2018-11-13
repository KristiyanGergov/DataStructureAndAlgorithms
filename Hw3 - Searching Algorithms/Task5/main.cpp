#include <vector>
#include <iostream>
using namespace std;

int findLess(int* values, int* weights, int n, int diff) {

	for (int i = 0; i < n; i++)
	{
		int value = values[i];
		int weight = weights[i];

		int currDiff = value / weight;

		if (currDiff > diff)
		{
			return i;
		}
	}
	return -1;
}

double getSum(int* values, int* weights, int n) {
	double sumValue = 0;
	double sumWeight = 0;

	for (int i = 0; i < n; i++)
	{
		sumValue += values[i];
		sumWeight += weights[i];
	}

	return sumValue / sumWeight;
}


int main() {

	int n, k;

	cin >> n;
	cin >> k;

	int* values = new int[k];
	int* weights = new int[k];

	int index = 0;

	for (int i = 0; i < n; i++)
	{
		double value, weight;

		cin >> value;
		cin >> weight;

		double diff = value / weight;

		if (index <= k) {
			index++;
		}
		else {
			index = findLess(values, weights, n, diff);
		}

		values[index] = value;
		weights[index] = weight;
	}

	cout << getSum(values, weights, n);


	return 0;
}