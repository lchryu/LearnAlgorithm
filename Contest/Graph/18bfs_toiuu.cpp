#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
vector<int> adjList[MAXN];  // Adjacency list to store the graph
int component[MAXN];        // To store the connected component of each node
int componentCount = 1;     // Counter for connected components

// Breadth-First Search to label connected components
void BFS(int startNode) {
    queue<int> q;
    q.push(startNode);
    component[startNode] = componentCount;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adjList[node]) {
            if (component[neighbor] == 0) {
                component[neighbor] = componentCount;
                q.push(neighbor);
            }
        }
    }
}

int main() {

    int n, m;
    cin >> n >> m;
    
    // Read graph edges
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    for (int i = 1; i <= n; ++i) {
        if (component[i] == 0) {
            BFS(i);
            componentCount++;
        }
    }
    
    int q;
    cin >> q;
    while (q--) {
        int s, t;
        cin >> s >> t;
        if (component[s] == component[t]) {
            cout << "1\n";
        } else {
            cout << "-1\n";
        }
    }
    
    return 0;
}
