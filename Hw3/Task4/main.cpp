#include <iostream>
#include <math.h>
using namespace std;

int findMaxPriceIndex(int* prices, int length) {
	int maxIndex = 0;

	for (int i = 0; i < length; i++)
		if (prices[i] > prices[maxIndex])
			maxIndex = i;
	return maxIndex;
}

int findMostExpensiveBuild(int* heights, int* prices, int length) {
	int maxPriceIndex = findMaxPriceIndex(prices, length);

	int mostExpensiveBuild = prices[maxPriceIndex];

	for (int i = 0; i < length; i++)
	{
		if (i == maxPriceIndex)
			continue;
		int height = abs(heights[maxPriceIndex] - heights[i]);
		int buildPrice = prices[i] * height;
		if (buildPrice > mostExpensiveBuild)
		{
			mostExpensiveBuild = buildPrice;
			maxPriceIndex = i;
		}
	}
	return maxPriceIndex;
}

int findSum(int* heights, int* prices, int length) {
	int maxIndex = findMostExpensiveBuild(heights, prices, length);

	int sum = 0;

	for (int i = 0; i < length; i++)
	{
		if (i == maxIndex)
			continue;
		int height = abs(heights[maxIndex] - heights[i]);

		sum += height * prices[i];
	}

	return sum;
}

int main() {
	int n;

	cin >> n;

	int* heights = new int[n];
	int* prices = new int[n];

	for (int i = 0; i < n; i++)
	{
		int height;
		cin >> height;
		heights[i] = height;
	}
	for (int i = 0; i < n; i++)
	{
		int price;
		cin >> price;
		prices[i] = price;
	}

	cout << findSum(heights, prices, n);

	return 0;
}