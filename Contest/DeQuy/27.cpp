#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<ll, ll>m;
ll f(int n) {
    if (n < 2) return n;
    if (m.find(n) != m.end()) return m[n];
    m[n] = f(n - 1) + f(n - 2);
    return m[n];
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << f(n) << endl;
    }
    return 0;
}
