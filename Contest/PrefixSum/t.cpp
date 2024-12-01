#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int res[maxn], d[maxn];
int main() {
    int n, k, q; 
    cin >> n >> k >> q;
    while (n--) {
        int l, r; cin >> l >> r;
        ++d[l];
        --d[r + 1];
    }
    for (int i = 1; i <= maxn; ++i) {
        d[i] += d[i - 1];
        if (d[i] >= k) res[i] = res[i - 1] + 1;
        else res[i] = res[i - 1];
    }
    while (q--) {
        int l, r; cin >> l >> r;
        cout << res[r] - res[l - 1] << '\n';
    }
}