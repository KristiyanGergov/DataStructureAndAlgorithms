#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 1000000000;

vector<int> dijkstra(int start, vector<vector<pair<int, int>>> & adj) {
	vector<int> dist;

	int vertices = adj.size();
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

		for (auto edge : adj[endVertex]) {
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
	ios_base::sync_with_stdio(false);
	int t;

	cin >> t;

	vector<int> dist;

	for (int i = 0; i < t; i++)
	{
		int vertices, edges;
		cin >> vertices;
		cin >> edges;

		vector<vector<pair<int, int>>> adj(vertices + 1);


		for (int j = 0; j < edges; j++)
		{
			int startVertex, endVertex, weight;

			cin >> startVertex;
			cin >> endVertex;
			cin >> weight;

			adj[endVertex].push_back({ startVertex, weight });
			adj[startVertex].push_back({ endVertex, weight });
		}

		int start;
		cin >> start;

		vector<int> dist = dijkstra(start, adj);

		for (int i = 1; i < dist.size(); i++)
		{
			if (i == start)
				continue;

			if (dist[i] == INF)
			{
				cout << -1 << " ";
				continue;
			}
			cout << dist[i] << " ";
		}
		cout << endl;
	}

	//system("pause");
	return 0;
}