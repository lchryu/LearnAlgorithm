#include <bits/stdc++.h>
using namespace std;
set<int>adj[1001];
vector<bool>v(1001, false);
vector<int>pre(1001, -1);
int n, m, s, t;
void bfs(int u) {
    queue<int>q; q.push(u); v[u] = true;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int j : adj[cur]) {
            if (!v[j]) {
                q.push(j);
                v[j] = true;
                pre[j] = cur;
            }
        }
    }
}
void solve() {
    bfs(s);
    if (!v[t]) {
        cout << "-1";
        return;
    }
    vector<int>path;
    for (int i = t; i != -1; i = pre[i]) path.push_back(i);
    cout << path.size() - 1 << endl;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
        
    cin >> n >> m >> s >>  t;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    solve();
}