#include <bits/stdc++.h>
using namespace std;
const int m = 3e4;
vector<bool>p(m + 1, true);
void sieve() {
    p[0] = p[1] = false;
    for (int i = 2; i <= sqrt(m); i++) {
        if (p[i]) {
            for (int j = i * i; j <= m; j += i) {
                p[j] = false;
            }
        }
    }
}
int check(int n) {
    while (n != 0) {
        if (!p[n]) return false;
        n /= 10;
    }
    return true;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();

    int n; cin >> n;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (check(i)) {
            flag = true;
            cout << i << " ";
        }
    }
    if (!flag) cout << -1;
}
