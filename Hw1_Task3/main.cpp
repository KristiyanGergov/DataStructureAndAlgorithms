#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {

	string first;
	string second;

	getline(cin, first);
	getline(cin, second);

	int lenFirst = first.length();
	int lenSecond = second.length();

	string bigger = lenFirst > lenSecond ? first : second;
	string smaller = lenFirst > lenSecond ? second : first;

	vector<char> result;

	for (int i = 0; i < smaller.length(); i++)
	{
		char current = smaller.at(i);

		int index = bigger.find(current);
		if (index != -1)
		{
			bigger.erase(index, 1);
			result.push_back(current);
		}
	}
	sort(result.begin(), result.end());

	string a(result.begin(), result.end());
	cout << a;
	return 0;
}
