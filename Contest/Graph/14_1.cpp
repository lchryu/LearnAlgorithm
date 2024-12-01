#include <bits/stdc++.h>
using namespace std;

int visited[1001];
vector<int> adj[1001];
int pre[1001];
int n, m, s, t;


void DFS(int i) {
    visited[i] = 1;
    sort(adj[i].begin(), adj[i].end());
    for(int j = 0; j < adj[i].size(); j++) {
        if(!visited[adj[i][j]]) {
            pre[adj[i][j]] = i;
            DFS(adj[i][j]);
        }
    }
}

void findway() {
    DFS(s); // ghi lai pre[i]
    if(visited[t] == 0) {
        cout << "-1\n";
        return;
    }
    vector<int> way;
    way.push_back(t);
    while(t != s) {
        t = pre[t];
        way.push_back(t);
    }
    for(int i = way.size() - 1; i >= 0; i--) {
        cout << way[i] << " ";
    }
    cout << endl;
}

int main() {
    cin >> n >> m >> s >> t;
    while(m--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    findway();
    return 0;
}
