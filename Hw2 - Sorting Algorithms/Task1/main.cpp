#include <iostream>
#include <string>
using namespace std;

void sort(string* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		bool flag = false;

		for (int c = 0; c < length - i - 1; c++)
		{
			string current = array[c] + array[c + 1];

			string next = array[c + 1] + array[c];

			if (current.compare(next) < 0)
			{
				swap(array[c], array[c + 1]);
				flag = true;
			}
		}
		if (!flag)
			break;
	}
}

int main() {
	int n;
	cin >> n;

	string* nums = new string[n];
	bool allZeroes = true;
	for (int i = 0; i < n; i++)
	{
		int current;
		cin >> current;
		if (current != 0) {
			allZeroes = false;
		}
		nums[i] = to_string(current);
	}

	sort(nums, n);
	if (!allZeroes)
		for (int i = 0; i < n; i++)
			cout << nums[i];
	else
		cout << 0;

	return 0;
}