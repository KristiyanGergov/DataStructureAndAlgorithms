#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1000000000;

struct Edge {
	int u, v, weight;
	bool operator<(Edge const& other) {
		return weight < other.weight;
	}
};

int kruskal(vector<Edge> & edges, int n) {

	int cost = 0;
	vector<int> tree_id(n);
	vector<Edge> result;
	for (int i = 0; i < n; i++)
		tree_id[i] = i;

	sort(edges.begin(), edges.end());

	for (Edge e : edges) {
		if (tree_id[e.u] != tree_id[e.v]) {
			cost += e.weight;
			result.push_back(e);

			int old_id = tree_id[e.u], new_id = tree_id[e.v];
			for (int i = 0; i < n; i++) {
				if (tree_id[i] == old_id)
					tree_id[i] = new_id;
			}
		}
	}

	return cost;
}

int main()
{

	int n, m;

	cin >> n;
	cin >> m;

	vector<Edge> result;

	for (int i = 0; i < m; i++)
	{
		int u, v, w;

		cin >> u;
		cin >> v;
		cin >> w;

		Edge edge = { u, v, w };
		
		result.push_back(edge);
	}

	cout << kruskal(result, m) << endl;

	system("pause");
	return 0;
}