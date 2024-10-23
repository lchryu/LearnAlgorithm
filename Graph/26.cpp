#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
bool visited[1001];

void DFS(int u) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (visited[v] == 0) {
            DFS(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            v.push_back(i);
            DFS(i);
        }
    }

    cout << v.size() - 1 << endl;
    for (int i = 1; i < v.size(); i++) {
        cout << v[i - 1] << " " << v[i] << endl;
    }

    return 0;
}
