#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int>v(n);
    map<int, int>m;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        m[v[i]]++;
    }
    int ans = 0;
    for (auto x : m) {
        if (x.second == 1) ans++;
    }
    cout << ans;
}