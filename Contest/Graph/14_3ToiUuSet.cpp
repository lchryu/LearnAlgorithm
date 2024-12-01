#include <bits/stdc++.h>
using namespace std;

int visited[1001] = {};
set<int> alist[1001];
int pre[1001] = {};
int n, m, s, t;

void DFS(int i) {
    visited[i] = 1;
    for (int j : alist[i]) {
        if (visited[j] == 0) {
            pre[j] = i;
            DFS(j);
        }
    }
}

void findway() {
    DFS(s);
    if (visited[t] == 0) {
        cout << "-1\n";
        return;
    }
    vector<int> way;
    way.push_back(t);
    while (t != s) {
        t = pre[t];
        way.push_back(t);
    }
    for (int i = way.size() - 1; i >= 0; i--) {
        cout << way[i] << " ";
    }
    cout << endl;
}

int main() {
    cin >> n >> m >> s >> t;
    while (m--) {
        int x, y;
        cin >> x >> y;
        alist[x].insert(y);
        alist[y].insert(x);
    }

    findway();
    return 0;
}
