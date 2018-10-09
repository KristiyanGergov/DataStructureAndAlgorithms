#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int result = 0;
	vector<int> stocks;
	int n, k, stock;
	cin >> n;
	cin >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> stock;
		stocks.push_back(stock);
	}

	sort(stocks.begin(), stocks.end());

	int count = 1;
	for (int i = stocks.size() - 1; i >= 0; i--)
	{
		if (count == k)
		{
			count = 1;
			continue;
		}
		result += stocks.at(i);
		count++;
	}
	cout << result;
	return 0;
}
