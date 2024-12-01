#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 1001;
vector<set<int>> adjList(MAX_NODES);
vector<int> predecessor(MAX_NODES, -1);
vector<bool> visited(MAX_NODES, false);
int n, m, s, t;

void DFS(int node) {
    visited[node] = true;
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            predecessor[neighbor] = node;
            DFS(neighbor);
        }
    }
}

void findPath() {
    DFS(s);
    
    if (!visited[t]) {
        cout << "-1\n";
        return;
    }
    
    vector<int> path;
    for (int v = t; v != -1; v = predecessor[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    for (int v : path) {
        cout << v << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> s >> t;
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }

    findPath();
    
    return 0;
}
