#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 1000000000;

vector<int> dijkstra(int start, vector<vector<pair<int, int>>> & carRoads) {
	vector<int> dist;

	int vertices = carRoads.size();
	dist.assign(vertices, INF);

	dist[start] = 0;
	using pii = pair<int, int>;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({ 0, start });
	while (!q.empty()) {
		int endVertex = q.top().second;
		int d_v = q.top().first;
		q.pop();
		if (d_v != dist[endVertex])
			continue;

		for (auto edge : carRoads[endVertex]) {
			int to = edge.first;
			int len = edge.second;

			if (dist[endVertex] + len < dist[to]) {
				dist[to] = dist[endVertex] + len;
				q.push({ dist[to], to });
			}
		}
	}

	return dist;
}

int main() {

	int n, m, k;

	cin >> n;
	cin >> m;
	cin >> k;

	vector<vector<pair<int, int>>> carRoads(n + 1);

	for (int i = 0; i < m; i++)
	{
		int v1, v2, w;

		cin >> v1;
		cin >> v2;
		cin >> w;

		pair<int, int> pair = { v2, w };

		carRoads[v1].push_back(pair);
	}

	vector<int> dist = dijkstra(1, carRoads);

	vector<int> trainRoads(n + 1);
	vector<bool> visited(n + 1);

	int counter = 0;

	for (int i = 0; i < k; i++)
	{
		int v, w;

		cin >> v;
		cin >> w;
		if (visited[v])
		{
			counter++;
			if (trainRoads[v] > w)
				trainRoads[v] = w;
		}
		else {
			trainRoads[v] = w;
			visited[v] = true;
		}
	}

	for (int i = 0; i < trainRoads.size(); i++)
	{
		if (!visited[i])
			continue;
		
		if (dist[i] >= trainRoads[i])
		{
			counter++;
		}
	}

	cout << counter;

	system("pause");

	return 0;
}
