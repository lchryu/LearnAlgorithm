#include <iostream>
#include <vector>
#include <cstring>  // for memset

using namespace std;

int visited[1001];              // Global visited array
vector<int> adj[1001];          // Global adjacency list
int n, m;                       // Number of vertices and edges
int initial_components = 0;

// DFS function to explore the graph
void DFS(int u, int x, int y) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (!visited[v] && !(u == x && v == y) && !(u == y && v == x)) {
            DFS(v, x, y);
        }
    }
}

// Function to count the number of connected components
bool count_connected(pair<int, int> edge) {
    memset(visited, 0, sizeof(visited));  // Reset visited array
    int count = 0;

    // Count components after removing edge (edge.first, edge.second)
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            DFS(i, edge.first, edge.second);
            count++;
        }
    }

    // If the number of components increases, the edge is a bridge
    return count > initial_components;
}

int main() {
    cin >> n >> m;
    vector<pair<int, int>> elist;

    // Read the graph
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        elist.push_back({x, y});
    }

    // Initial DFS to count the number of connected components
    memset(visited, 0, sizeof(visited));  // Reset visited array
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS(i, 0, 0);  // Do initial DFS without removing any edge
            initial_components++;
        }
    }

    // Check for bridges
    int bridge_count = 0;
    for (auto edge : elist) {
        if (count_connected(edge)) {
            bridge_count++;
        }
    }

    cout << bridge_count << endl;
    return 0;
}
