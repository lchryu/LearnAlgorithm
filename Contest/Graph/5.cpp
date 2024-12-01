#include <bits/stdc++.h>
using namespace std;
int n;
int a[1001][1001];
vector<pair<int, int>>edges;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1 && i < j) {
                edges.push_back({i, j});
            }
        }
    }
    for (auto x : edges) {
        cout << x.first << ' ' << x.second << endl;
    }
    return 0;
}
