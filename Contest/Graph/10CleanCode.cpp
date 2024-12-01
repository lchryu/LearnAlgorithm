#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 1001;
vector<int> adjList[MAX_NODES];
vector<bool> visited(MAX_NODES, false);

void DFS(int node) {
    visited[node] = true;
    cout << node << " ";
    
    sort(adjList[node].begin(), adjList[node].end());
    
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, start;
    cin >> n >> m >> start;
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    DFS(start);

    return 0;
}
