#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int>adj[1001];
int visited[1001] = {};

// dem trong thanh phan lien thong co bao nhieu dinh
int DFS(int i) {
    visited[i] = 1;
    int cnt = 1;
    for (int j : adj[i]) {
        if (visited[j] == 0) {
            cnt += DFS(j);
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    
    while (m--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int ans = 0;
    
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            ans = max(ans, DFS(i));
        }
    }

    cout << ans << endl;

    return 0;
}
