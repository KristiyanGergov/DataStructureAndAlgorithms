#include <iostream>
#include <queue>
using namespace std;

struct Point
{
	int x;
	int y;
};

struct path
{
	Point point;
	int dist;
};

bool isValid(int row, int col, int n, int m)
{
	return (row >= 0) && (row < n) && (col >= 0) && (col < m);
}

int rowNum[] = { -1, 0, 0, 1 };
int colNum[] = { 0, -1, 1, 0 };

int findShortestPath(int** matrix, Point dest, const int m, const int n)
{
	bool** visited = new bool*[m];

	for (int i = 0; i < m; i++)
	{
		visited[i] = new bool[n];
		for (int j = 0; j < n; j++)
		{
			visited[i][j] = false;
		}
	}

	visited[0][0] = true;

	queue<path> result;

	result.push({ { 0, 0 }, 0 });

	while (!result.empty())
	{
		path curr = result.front();
		Point point = curr.point;

		if (point.x == dest.x && point.y == dest.y)
			return curr.dist;

		result.pop();

		for (int i = 0; i < 4; i++)
		{
			int row = point.x + rowNum[i];
			int col = point.y + colNum[i];

			if (isValid(row, col, n, m) && matrix[row][col] == 0 && !visited[row][col])
			{
				visited[row][col] = true;
				path Adjcell = { { row, col }, curr.dist + 1 };
				result.push(Adjcell);
			}
		}
	}

	return -1;
}

int main() {

	int m, n, k;

	cin >> m;
	cin >> n;
	cin >> k;

	int** matrix = new int*[m];

	for (int i = 0; i < m; i++)
	{
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			int curr;
			cin >> curr;
			matrix[i][j] = curr;
		}
	}


	for (int i = 0; i < k; i++)
	{
		int x, y;

		cin >> x;
		cin >> y;

		Point point = { x, y };

		int dist = findShortestPath(matrix, point, m, n);
		cout << dist << endl;
	}


	return 0;
}