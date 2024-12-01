#include <bits/stdc++.h>
using namespace std;

int visited[1001] = {};

void BFS(vector<int> alist[], int s) {
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    
    while(q.empty() == 0) {
        int i = q.front();
        cout << i << " ";
        sort(alist[i].begin(), alist[i].end());
        
        for(int x : alist[i]) {
            if(visited[x] == 0) {
                visited[x] = 1;
                q.push(x);
            }
        }
        q.pop();
    }
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<int> alist[1001];
    
    while(m--) {
        int x, y;
        cin >> x >> y;
        alist[x].push_back(y);
    }
    
    BFS(alist, s);
    
    return 0;
}
