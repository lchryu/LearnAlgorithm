#include <bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    multiset<int>se;
    while (n--) {
        int x; cin >> x;
        se.insert(x);
    }
    int x; cin >> x;
    se.insert(x);
    for (int x : se) cout << x << " ";
}