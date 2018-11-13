#include <vector>
#include <iostream>
#include <string>
using namespace std;


void sort(int numbers[], int count)
{
	for (int i = 0; i < count - 1; i++)
	{
		int currentMin = numbers[i];
		int currentMinIndex = i;

		for (int j = i + 1; j < count; j++)
		{
			if (currentMin < numbers[j])
			{
				currentMin = numbers[j];
				currentMinIndex = j;
			}
		}

		if (currentMinIndex != i) {
			numbers[currentMinIndex] = numbers[i];
			numbers[i] = currentMin;

		}
	}
}

int main() {
	string input;
	getline(cin, input);

	int count[26] = { 0 };

	for (int i = 0; i < input.size(); i++)
	{
		count[input[i] - 'a']++;
	}

	sort(count, 26);

	int last = count[0];

	for (int i = 1; i < 26; i++)
	{
		if (count[i] == 0)
			continue;
		if (last == 0)
		{
			last = count[i];
			continue;
		}
		if (last - count[i] < 1)
			last = count[i] - last;
		else if (last - count[i] == 1)
			last = count[i] - (last - 1);
		else
			last -= count[i];
	}

	if (last > 1) cout << "No";
	else cout << "Yes";

	return 0;
}