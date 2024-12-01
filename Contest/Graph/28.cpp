#include <bits/stdc++.h>
using namespace std;

int n, m;
int visited[1001] = {};
vector<int> adj[1001];

int DFS(int i, int leader) {
    visited[i] = 1;
    if (adj[i].size() > adj[leader].size()) leader = i;
    else if (adj[i].size() == adj[leader].size() && i < leader) leader = i;
    for (int j : adj[i]) {
        if (visited[j] == 0) {
            leader = DFS(j, leader);
        }
    }
    return leader;
}

int main() {
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            ans.push_back(DFS(i, i));
        }
    }

    sort(ans.begin(), ans.end());
    for (int x : ans) cout << x << " ";
    cout << endl;
    
    return 0;
}
