#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

const int INF = 1000000000;

void dijkstra(int s, vector<int> & d, vector<int> & p, vector<vector<pair<int, int>>> adj) {
	int n = adj.size();
	d.assign(n, INF);
	p.assign(n, -1);

	d[s] = 0;
	set<pair<int, int>> q;
	q.insert({ 0, s });
	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase(q.begin());

		for (auto edge : adj[v]) {
			int to = edge.first;
			int len = edge.second;

			if (d[v] + len < d[to]) {
				q.erase({ d[to], to });
				d[to] = d[v] + len;
				p[to] = v;
				q.insert({ d[to], to });
			}
		}
	}
}


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