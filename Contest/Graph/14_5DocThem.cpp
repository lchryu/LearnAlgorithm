#include <bits/stdc++.h>
using namespace std;
int visited[1001];
set<int>alist[1001];
int n, m, s, t;
void DFS(int i, string s) {
    if (visited[t]) return;
    s = s + to_string(i) + " ";
    visited[i] = 1;
    if (i == t) {
        cout << s << endl;
        return;
    }
    
    for (int j : alist[i]) {
        if (visited[j] == 0) {
            DFS(j, s);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m >> s >> t;
    while (m--) {
        int x, y;
        cin >> x >> y;
        alist[x].insert(y);
        alist[y].insert(x);
    }
    
    DFS(s, "");
    if (visited[t] == 0) cout << -1 << endl;
    return 0;
}
