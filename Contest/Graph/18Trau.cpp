#include <bits/stdc++.h>
using namespace std;

int checkWay(vector<int> a[], int s, int t) {
    vector<int> visited(1001, -1);
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while(q.empty() == 0) {
        if(visited[t] == 1) return 1;
        int i = q.front();
        sort(a[i].begin(), a[i].end());
        for(int x : a[i]) {
            if(visited[x] == -1) {
                visited[x] = 1;
                q.push(x);
            }
        }
        q.pop();
    }
    return visited[t];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> alist[1001];
    while(m--) {
        int x, y;
        cin >> x >> y;
        alist[x].push_back(y);
        alist[y].push_back(x);
    }
    
    int q;
    cin >> q;
    while(q--) {
        int s, t;
        cin >> s >> t;
        cout << checkWay(alist, s, t) << endl;
    }

    return 0;
}
