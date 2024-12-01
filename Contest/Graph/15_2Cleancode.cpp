#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 1001;
vector<int> adjList[MAX_NODES];
int predecessor[MAX_NODES] = {};
bool visited[MAX_NODES] = {};
int n, m, s, t;

void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        sort(adjList[node].begin(), adjList[node].end());  // Sort to ensure lexicographical order
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                predecessor[neighbor] = node;
                q.push(neighbor);
            }
        }
    }
}

void findPath() {
    BFS(s);

    if (!visited[t]) {
        cout << "-1\n";  // No path found
        return;
    }

    vector<int> path;
    for (int v = t; v != s; v = predecessor[v]) {
        path.push_back(v);
    }
    path.push_back(s);
    reverse(path.begin(), path.end());

    for (int v : path) {
        cout << v << " ";  // Print the path
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
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    findPath();

    return 0;
}
