#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<pii>> Graph;

vector<int> prim(const Graph& graph, int start) {
    int V = graph.size();
    vector<int> parent(V, -1); // To store the parent of each vertex in MST
    vector<int> key(V, INT_MAX); // To store the minimum weight edge connecting each vertex to MST
    vector<bool> inMST(V, false); // To track vertices included in MST

    // Min heap to select the vertex with minimum key value
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, start});
    key[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    return parent;
}

void printMST(const Graph& graph, const vector<int>& parent) {
    cout << "Minimum Spanning Tree:\n";
    for (int i = 1; i < graph.size(); ++i) {
        cout << "Edge: " << parent[i] << " - " << i << " Weight: " << graph[i][parent[i]].second << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    Graph graph(V);

    cout << "Enter the edges in the format 'src dest weight':\n";
    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src].push_back({dest, weight});
        graph[dest].push_back({src, weight}); // Undirected graph
    }

    int start;
    cout << "Enter the starting vertex for Prim's algorithm: ";
    cin >> start;

    vector<int> parent = prim(graph, start);

    printMST(graph, parent);

    return 0;
}
