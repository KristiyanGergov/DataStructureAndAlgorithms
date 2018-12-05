#include<iostream>
#include<vector>
#include <queue>

using namespace std;

// A utility function to add an edge in an 
// undirected graph. 
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

// A utility function to print the adjacency list 
// representation of graph 
void printGraph(vector<int> adj[], int V)
{
	for (int v = 0; v < V; ++v)
	{
		cout << "\n Adjacency list of vertex "
			<< v << "\n head ";
		for (auto x : adj[v])
			cout << "-> " << x;
		printf("\n");
	}
}

// Driver code 
int main()
{
	int n, m;

	cin >> n;
	cin >> m;

	vector<int> adj[n];

	queue<bool> coffees;

	for (int i = 0; i < n; i++)
	{
		bool hasCoffee;
		cin >> hasCoffee;

		coffees.push(hasCoffee);
	}

	for (int i = 0; i < n - 1; i++)
	{
		int vertice, edge;

		cin >> vertice;
		cin >> edge;
		addEdge(adj, vertice, edge);

	}

	printGraph(adj, n - 1);
	return 0;
}