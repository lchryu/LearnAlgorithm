#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int start) {
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int u = s.top();
        s.pop();
        if (!visited[u]) {
            visited[u] = true;
            cout << u << " ";
            
            sort(adj[u].begin(), adj[u].end(), greater<int>());
            
            for (int x : adj[u]) {
                if (!visited[x]) s.push(x);
            }
        }
    }
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    dfs(s);

    cout << endl;

    return 0;
}