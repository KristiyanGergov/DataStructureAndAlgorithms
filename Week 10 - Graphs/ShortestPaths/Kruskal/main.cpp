#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	int startVertex, endVertex, weight;
	bool operator<(Edge const& other) {
		return weight < other.weight;
	}
};

void findShortestPath(int vertices, vector<Edge> edges) {
	int cost = 0;
	vector<int> tree_id(vertices);
	vector<Edge> result;
	for (int i = 0; i < vertices; i++)
		tree_id[i] = i;

	sort(edges.begin(), edges.end());

	for (Edge e : edges) {
		if (tree_id[e.startVertex] != tree_id[e.endVertex]) {
			cost += e.weight;
			result.push_back(e);

			int old_id = tree_id[e.startVertex], new_id = tree_id[e.endVertex];
			for (int i = 0; i < vertices; i++) {
				if (tree_id[i] == old_id)
					tree_id[i] = new_id;
			}
		}
	}
}


int main() {





	return 0;
}