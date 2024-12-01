#include <bits/stdc++.h>

using namespace std;

const int MAX = 1001;
vector<int> adj[MAX];   // Adjacency list to store the directed graph
int visited[MAX];       // 0 = not visited, 1 = visiting, 2 = visited
bool hasCycle = false;  // Flag to indicate if a cycle is detected

void DFS(int u) {
    visited[u] = 1;  // Mark the vertex as being visited
    for (int v : adj[u]) {
        if (visited[v] == 1) {  // If v is currently being visited, a cycle is detected
            hasCycle = true;
            return;
        }
        if (visited[v] == 0) {  // If v is not visited, continue DFS
            DFS(v);
        }
    }
    visited[u] = 2;  // Mark the vertex as fully visited
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);  // Directed edge from u to v
    }

    // Run DFS on all vertices to detect cycles
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            DFS(i);
            if (hasCycle) break;  
        }
    }

    cout << (hasCycle ? 1 : 0) << endl;

    return 0;
}
