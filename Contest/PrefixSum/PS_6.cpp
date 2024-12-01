#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;
int main() {
    int n, q; cin >> n >> q;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int>D(n + 2, 0);
    // D[i] phan tu o chi so i duoc truy van bao nhieu lan
    while (q--) {
        int l, r; cin >> l >> r;
        D[l]++;
        D[r + 1]--;
    }
    for (int i = 1; i <= n; i++) D[i] += D[i - 1];
    sort(D.begin() + 1, D.begin() + n + 1, greater<int>());
    sort(a.begin() + 1, a.begin() + n + 1, greater<int>());
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += a[i] * D[i];
    cout << ans << endl;
}

// int n; cin >> n;
// for (int i = 1; i <= n; i++) {
//     cin >> a[i];
//     a[i] += a[i - 1];
// }