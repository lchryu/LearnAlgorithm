#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 2e5;
vector<int>a(MAXN + 5), res(MAXN + 5);
int main() {
    int n, k, q; cin >> n >> k >> q;
    while (n--) {
        int l, r; cin >> l >> r;
        ++a[l];
        --a[r + 1];
    }
    for (int i = 1; i <= MAXN; ++i) {
        a[i] += a[i - 1];
        if (a[i] >= k) res[i] = 1 + res[i - 1];
        else res[i] = res[i - 1];
    }
    while (q--) {
        int l, r; cin >> l >> r;
        cout << res[r] - res[l - 1] << endl;
    }
}
