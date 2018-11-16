#include <iostream>
#include <cmath>
using namespace std;

bool checkNum(long num) {

	while (num / 10 != 0) {

		int current = num % 10;
		int next = (num / 10) % 10;

		if (abs(num % 10 - (num / 10) % 10) != 2)
			return false;
		num = num / 10;
	}
	return true;
}

int main() {
	long n;

	cin >> n;

	for (long i = 1; i <= n; i++) {
		if (checkNum(i))
			cout << i << " ";

	}

	return 0;
}