#include <bits/stdc++.h>
using namespace std;

int n, m;
int visited[1001] = {};
vector<int> alist[1001];

int DFS(int i, int leader) {
    visited[i] = 1;
    if (alist[i].size() > alist[leader].size()) leader = i;
    else if (alist[i].size() == alist[leader].size() && i < leader) leader = i;
    for (int j : alist[i]) {
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
        alist[x].push_back(y);
        alist[y].push_back(x);
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
