#include <bits/stdc++.h>
using namespace std;

int visited[1001];
int n, m, s;
vector<int> adj[1001];

void BFS(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    
    while(!q.empty()) {
        int i = q.front();
        cout << i << " ";
        sort(adj[i].begin(), adj[i].end());
        for(int x : adj[i]) {
            if(!visited[x]) {
                visited[x] = 1;
                q.push(x);
            }
        }
        q.pop();
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
    
    BFS(s);
    
    return 0;
}
