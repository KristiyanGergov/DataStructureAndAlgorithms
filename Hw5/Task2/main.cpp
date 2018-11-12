#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

const char* white = "white";
const char* green = "green";
const char* blue = "blue";

int main() {
	int n;

	cin >> n;

	stack<long> whiteStones;

	char* stone = new char[5];

	for (int i = 0; i < n; i++)
	{
		int k;

		cin >> stone;
		cin >> k;

		if (strcmp(stone, white) == 0)
		{
			whiteStones.push(k);
		}
		else if (strcmp(stone, green) == 0) {
			long sum = 0;

			for (long i = 0; i < k; i++)
			{
				sum += whiteStones.top();
				whiteStones.pop();
			}
			whiteStones.push(sum);
		}
		else if (strcmp(stone, blue) == 0) {
			long max = 0;

			for (long i = 0; i < k; i++)
			{
				if (max < whiteStones.top())
					max = whiteStones.top();
				whiteStones.pop();
			}

			whiteStones.push(max);
		}
	}

	stack<long> res;
	while (!whiteStones.empty()) 
	{
		res.push(whiteStones.top());
		whiteStones.pop();
	}

	while (!res.empty())
	{
		cout << res.top() << " ";
		res.pop();
	}

	return 0;
}