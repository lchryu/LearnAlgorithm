#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> adj[1001];    // Adjacency list for the original graph
vector<int> t_adj[1001];  // Adjacency list for the transposed graph
int visited[1001] = {};     // Visited array
vector<int> v, v2;          // Vectors to store traversal order

// DFS for the original graph
void DFS(int i) {
    visited[i] = 1;  // Mark node as visited
    v.push_back(i);  // Store the node in traversal order
    for (int j : adj[i]) {
        if (visited[j] == 0) {
            DFS(j);  // Continue DFS if not visited
        }
    }
}
// DFS for the transposed graph
void DFS2(int i) {
    visited[i] = 1;  // Mark node as visited
    v2.push_back(i);  // Store the node in traversal order
    for (int j : t_adj[i]) {
        if (visited[j] == 0) {
            DFS2(j);  // Continue DFS on the transposed graph if not visited
        }
    }
}

int main() {
    cin >> n >> m;
    
    // Read the edges and build both the original and transposed graphs
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);  // Original graph: edge from x to y
        t_adj[y].push_back(x);  // Transposed graph: edge from y to x
    }

    // Run DFS on the original graph from node 1
    DFS(1);

    // Check if there are any unvisited nodes
    for (int i = 2; i <= n; i++) {
        if (visited[i] == 0) {
            cout << "0\n";  // If any node is unvisited, the graph is not strongly connected
            return 0;
        }
    }

    // Reset visited array for the transposed graph DFS
    fill(visited, visited + 1001, 0);

    // Run DFS on the transposed graph from node 1
    DFS2(1);

    // Check again if there are any unvisited nodes in the transposed graph
    for (int i = 2; i <= n; i++) {
        if (visited[i] == 0) {
            cout << "0\n";  // If any node is unvisited in the transposed graph, not strongly connected
            return 0;
        }
    }

    // If all nodes are visited in both the original and transposed graph DFS, the graph is strongly connected
    cout << "1\n";
    return 0;
}
