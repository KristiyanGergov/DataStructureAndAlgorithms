#include <iostream>
using namespace std;

int main() {

	int n;

	cin >> n;

	int addend = 2;

	int size = n;
	int top = n;
	int bot = 1;

	while (size > 1)
	{
		if (size % 2 == 0)
		{
			top -= addend / 2;
		}
		else 
		{
			bot = bot += addend;
		}

		addend *= 2;
		size /= 2;
	}

	cout << top;

	return 0;
}