#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 1001;
vector<int> adjList[MAX_NODES];
vector<bool> visited(MAX_NODES, false);

void DFS(int node) {
    visited[node] = true;
    
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

    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int components = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            components++;
            DFS(i);
        }
    }

    cout << components << endl;

    return 0;
}
