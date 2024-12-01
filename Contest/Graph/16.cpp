#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
const int maxn = 1e3; 
vector<int>adj[maxn + 1];
vector<bool>visited(maxn + 1, false);
vector<int>pre(maxn + 1, -1);

void dfs(int u) {
    visited[u] = true;
    sort(adj[u].begin(), adj[u].end());
    for (int v : adj[u]) {
        if (!visited[v]) {
            pre[v] = u;
            dfs(v);
        }
    }
}
void findPath() {
    dfs(s);
    if (!visited[t]) {
        cout << -1;
        return;
    }
    vector<int>path;
    for (int v = t; v != -1; v = pre[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    for (int u : path) cout << u << " ";
}
int main() {
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    findPath();
}