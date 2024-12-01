#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[1001];  // Adjacency list for the graph
bool visited[1001];     // Array to track visited vertices
bool hasCycle = false;  // Boolean variable to track if there is a cycle

// DFS function to detect cycles in the graph
void DFS(int u, int parent) {
    visited[u] = true;  // Mark the current vertex as visited
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v, u);  // Recursively visit adjacent vertex v
        } else if (v != parent) {
            hasCycle = true;  // If visited v and v is not the parent, a cycle exists
            return;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    // Input the edges and build the adjacency list
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);  // Add edge u-v
        adj[v].push_back(u);  // Add edge v-u since the graph is undirected
    }

    // Run DFS for each unvisited vertex to check for cycles
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            DFS(i, -1);  // Start DFS from vertex i with no parent (-1)
            if (hasCycle) break;  // If a cycle is found, exit early
        }
    }

    // Output the result: 1 if a cycle exists, otherwise 0
    cout << (hasCycle ? 1 : 0) << endl;

    return 0;
}
