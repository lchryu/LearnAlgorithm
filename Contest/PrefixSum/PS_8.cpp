#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], l[maxn], r[maxn], v[maxn], query[maxn];
int diff[maxn]; // diff[i]: danh dau thao_tac[i] duoc thuc hien bao nhieu lan
int main() {
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> l[i] >> r[i] >> v[i]; // operation
    
    // k queries
    
    for (int i = 1; i <= k; i++) {
        int x, y; cin >> x >> y;
        diff[x]++;
        diff[y + 1]--;
    }
    // diff[i]: tt[i]
    // tt_max = tt_[m]
    for (int i = 1; i <= m; i++) {
        diff[i] += diff[i - 1];
        query[l[i]] += diff[i] * v[i];
        query[r[i] + 1] -= diff[i] * v[i];
    }
    
    for (int i = 1; i <= n; i++) {
        query[i] += query[i - 1];
        cout << a[i] + query[i] << ' ';
    }
    
    return 0;
}
