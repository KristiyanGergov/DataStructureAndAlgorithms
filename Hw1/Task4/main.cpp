#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;


int main() {
	int n, k, sock;
	cin >> n;
	cin >> k;

	multimap<int, string> result;

	int permutations = (n * (n - 1)) / 2;

	vector<int> socks;

	for (int i = 0; i < n; i++)
	{
		cin >> sock;
		socks.push_back(sock);
	}
	sort(socks.begin(), socks.end());

	int count = socks.size() - 1;
	int index = 1;
	for (int i = 0; i < socks.size() - 1; i++)
	{
		int current = socks.at(i);
		for (int j = index; j <= count; j++)
		{
			int diff = socks.at(j) - current;
			string res = to_string(current) + " " + to_string(socks.at(j));
			result.insert(pair<int, string>(diff, res));
			int a = 5;
		}
		index++;
	}


	int test = 1;
	for (map<int, string>::iterator i = result.begin(); i != result.end(); i++)
	{
		if (test == k)
		{
			cout << i->second;
			break;
		}
		test++;
	}

	return 0;
}