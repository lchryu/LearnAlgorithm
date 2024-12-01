#include <bits/stdc++.h>
using namespace std;

int visited[1001] = {};

void DFS(vector<int> v[], int i, int n) {
    visited[i] = 1;
    // sort(v[i].begin(), v[i].end());
    for(int j = 0; j < v[i].size(); j++) {
        if(visited[v[i][j]] == 0) {
            DFS(v, v[i][j], n);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> alist[1001];
    
    while(m--) {
        int x, y;
        cin >> x >> y;
        alist[x].push_back(y);
        alist[y].push_back(x);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            ans++;
            DFS(alist, i, n);
        }
    }
    
    cout << ans << endl;
    return 0;
}
