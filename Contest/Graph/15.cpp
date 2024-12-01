#include <bits/stdc++.h>
using namespace std;

int visited[1001];
int pre[1001];
int n, m, s, t;

void BFS(vector<int> a[], int s) {
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while (q.empty() == 0) {
        int i = q.front();
        q.pop();
        sort(a[i].begin(), a[i].end());
        for (int x : a[i]) {
            if (visited[x] == 0) {
                visited[x] = 1;
                pre[x] = i;
                q.push(x);
            }
        }
    }
}

void findway(vector<int> a[], int s, int t) {
    BFS(a, s);
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
    vector<int> alist[1001];
    while (m--) {
        int x, y;
        cin >> x >> y;
        alist[x].push_back(y);
        alist[y].push_back(x);
    }
    findway(alist, s, t);
    return 0;
}
