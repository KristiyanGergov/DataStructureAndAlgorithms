#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	int startVertex, endVertex, weight;
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
		if (tree_id[e.startVertex] != tree_id[e.endVertex]) {
			cost += e.weight;
			result.push_back(e);

			int old_id = tree_id[e.startVertex], new_id = tree_id[e.endVertex];
			for (int i = 0; i < n; i++) {
				if (tree_id[i] == old_id)
					tree_id[i] = new_id;
			}
		}
	}

	return cost;
}