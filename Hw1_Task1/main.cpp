#include <iostream>
using namespace std;


int main() {
	int maxH = 0;
	int maxM = 0;

	int minH = 24;
	int minM = 60;

	for (int i = 0; i < 3; i++)
	{
		int hStart, mStart, hEnd, mEnd;
		cin >> hStart;
		cin >> mStart;
		cin >> hEnd;
		cin >> mEnd;

		if (hStart < 0 || hEnd < 0 || hStart > 24 || hEnd > 24 || mStart < 0 || mEnd < 0 || mStart > 60 || mEnd > 60)
		{
			return 0;
		}

		int hDiff = 24 - hStart;
		int mDiff = 0;

		if (hStart > hEnd)
			hDiff += hEnd;
		else
			hDiff -= 24 - hEnd;

		if (mEnd - mStart < 0)
		{
			mDiff = mEnd - mStart + 60;
			hDiff--;
		}
		else {
			mDiff = mEnd - mStart;
		}

		if (hDiff > maxH)
		{
			maxH = hDiff;
			maxM = mDiff;
		}
		if (hDiff < minH)
		{
			minH = hDiff;
			minM = mDiff;
		}
		if (hDiff == maxH)
		{
			if (mDiff > maxM)
				maxM = mDiff;
		}
		if (hDiff == minH)
			if (mDiff < minM)
				minM = mDiff;
	}
	const char* dMin = minM / 10 == 0 ? "0" : "";
	const char* dMax = maxM / 10 == 0 ? "0" : "";
	cout << minH << ":" << dMin << minM << endl;
	cout << maxH << ":" << dMax << maxM << endl;
	return 0;
}