// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// int n, m;
// vector<int> ke[1005];

// int main() {
//     cin >> n >> m;
//     for(int i = 0; i < m; i++) {
//         int x, y; cin >> x >> y;
//         ke[x].push_back(y);
//         ke[y].push_back(x);
//     }
    
//     for(int i = 1; i <= n; i++) {
//         sort(ke[i].begin(), ke[i].end());
//         cout << i << ": ";
//         for(int x : ke[i]) {
//             cout << x << ' ';
//         }
//         cout << '\n';
//     }
// }
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define pb push_back
int v, e;
vector<int> adj[1005];
int main() {
    cin >> v >> e;
    for (int i = 0; i < e; ++i) {
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for (int i = 1; i <= v; i++) {
        cout << i << ": ";
        sort(all(adj[i]));
        for (int x : adj[i]) cout << x << ' ';
        cout << endl;
    }
}