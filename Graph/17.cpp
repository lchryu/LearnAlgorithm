#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;

const int maxn = 1e3;
vector<int>adj[maxn + 1];
vector<bool>visited(maxn + 1, false);
vector<int>pre(maxn + 1, -1);
int n, m, s, t;
void bfs(int start) {
    queue<int>q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        sort(all(adj[u]));
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                pre[v] = u;
                q.push(v);
            }
        }
    }  
}
void findPath() {
    bfs(s);
    if (!visited[t]) {
        cout << -1;
        return;
    }
    vector<int>path;
    for (int v = t; v != -1; v = pre[v]) {
        path.push_back(v);
    }
    reverse(all(path));
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

