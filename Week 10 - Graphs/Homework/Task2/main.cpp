#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 0;

void dijkstra(int start, vector<int> & dist, vector<vector<pair<int, int>>> & adj) {
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

			if (dist[endVertex] + len > dist[to]) {
				dist[to] = dist[endVertex] + len;
				q.push({ dist[to], to });
			}
		}
	}
}

int main() {

	int n, m, s, t;

	cin >> n;
	cin >> m;
	cin >> s;
	cin >> t;

	vector<vector<pair<int, int>>> adj(n + 1);

	for (int i = 0; i < m; i++)
	{
		int v1, v2, w;

		cin >> v1;
		cin >> v2;
		cin >> w;

		pair<int, int> pair = { v2, w };

		adj[v1].push_back(pair);
	}

	vector<int> dist;

	dijkstra(s, dist, adj);

	if (dist.at(t) == 0)
		cout << -1;
	else
		cout << dist.at(t);

	return 0;
}
