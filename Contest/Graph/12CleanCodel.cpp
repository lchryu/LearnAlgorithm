#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 1001;
vector<int> adjList[MAX_NODES];
vector<bool> visited(MAX_NODES, false);

void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        cout << node << " ";
        
        sort(adjList[node].begin(), adjList[node].end());
        
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m, start;
    cin >> n >> m >> start;
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    BFS(start);

    return 0;
}
