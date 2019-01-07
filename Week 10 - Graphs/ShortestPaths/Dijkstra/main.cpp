#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
	int n = adj.size();
	d.assign(n, INF);
	p.assign(n, -1);

	d[s] = 0;
	using pii = pair<int, int>;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({ 0, s });
	while (!q.empty()) {
		int v = q.top().second;
		int d_v = q.top().first;
		q.pop();
		if (d_v != d[v])
			continue;

		for (auto edge : adj[v]) {
			int to = edge.first;
			int len = edge.second;

			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
				q.push({ d[to], to });
			}
		}
	}
}


int main() {

	int t;

	cin >> t;

	vector<int> d;

	for (int i = 0; i < t; i++)
	{
		int n, m;
		cin >> n;
		cin >> m;

		for (int j = 0; j < m; j++)
		{
			int u, v, w;

			cin >> u;
			cin >> v;
			cin >> w;

			vector<pair<int, int>> curr;

			adj.insert(adj.begin() + u, curr);
		}

	}

	int s;
	cin >> s;



	return 0;
}