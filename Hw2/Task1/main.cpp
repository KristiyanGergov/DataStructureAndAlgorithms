#include <iostream>
#include <string>
using namespace std;

bool checkNum(string first, string next) {

	int smallerLength = first.size() < next.size() ? first.size() : next.size();
	bool firstSmaller = first.size() < next.size() ? true : false;

	for (int i = 0; i < smallerLength; i++)
	{
		char currentDigit = first[i];
		char nextDigit = next[i];

		if (currentDigit < nextDigit)
			return true;
		else if (currentDigit > nextDigit)
			return false;
		else
		{
			if (i + 1 < smallerLength)
				continue;

			if (firstSmaller)
			{
				if (first.size() > next.size() / 2)
				{
					int index = 0;
					for (int k = first.size(); k < next.size(); k++)
					{
						char f = first[index++];
						char n = next[k];

						if (f < n)
							return true;
						else if (f > n)
							return false;
					}
				}

				return checkNum(first, next.substr(smallerLength, next.size() - smallerLength));
			}
			else
			{
				if (next.size() > first.size() / 2)
				{
					int index = 0;
					for (int k = next.size(); k < first.size(); k++)
					{
					
						char f = first[k];
						char n = next[index++];

						if (f < n)
							return true;
						else if (f > n)
							return false;
					}
				}

				return checkNum(first.substr(smallerLength, first.size() - smallerLength), next);
			}
		}
	}
	return true;
}

void sort(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		bool flag = false;

		for (int c = 0; c < length - i - 1; c++)
		{
			string current = to_string(array[c]);

			string next = to_string(array[c + 1]);

			if (current[0] < next[0])
			{
				swap(array[c], array[c + 1]);
				flag = true;
			}
			else if (current[0] == next[0]) {

				bool currentSmaller = checkNum(current, next);

				if (currentSmaller)
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

	int* nums = new int[n];

	for (int i = 0; i < n; i++)
	{
		int current;
		cin >> current;
		nums[i] = current;
	}

	sort(nums, n);

	for (int i = 0; i < n; i++)
		cout << nums[i];

	return 0;
}