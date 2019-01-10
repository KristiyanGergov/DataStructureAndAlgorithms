#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
using namespace std;

const int INF = 10000000000;

int counter = 0;

vector<int> dijkstra(int start, vector<vector<pair<int, int>>> & carRoads) {
	vector<int> dist;

	size_t vertices = carRoads.size();
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

void dijkstra(int s, vector<int> & d, vector<vector<int>> & p, vector<vector<pair<int, int>>> adj) {
	int n = adj.size();
	d.assign(n, INF);

	for (int i = 0; i < n; i++)
	{
		vector<int> curr;
		p.push_back(curr);
	}
	
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
				p[to].push_back(v);
				p[v].push_back(to);
				q.insert({ d[to], to });
			}
		}
	}
}


int main() {

	const char* str = "gosho";
	
	int size = sizeof(str) / str[0];


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

	vector<int> d;
	vector<vector<int>> p;

	dijkstra(1, d, p, carRoads);

	vector<int> dist = dijkstra(1, carRoads);

	int counter = 0;

	vector<pair<int, int>> trains;

	for (int i = 0; i < k; i++)
	{
		int v, w;

		cin >> v;
		cin >> w;

		trains.push_back({ v, w });
	}

	for (auto train : trains)
		if (dist[train.first] <= train.second)
			counter++;

	cout << counter;

	system("pause");

	return 0;
}
