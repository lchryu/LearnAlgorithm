#include <bits/stdc++.h>
using namespace std;

vector<int> visited(1001, 0);
vector<int> adj[1001];
int n, m, s;

void DFS(int i) {
    visited[i] = 1;
    sort(adj[i].begin(), adj[i].end());
    cout << i << " ";
    for (int j : adj[i]) {
        if (!visited[j]) {
            DFS(j);
        }
    }
}

int main() {
    cin >> n >> m >> s;
    
    while(m--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    DFS(s);
    
    return 0;
}
