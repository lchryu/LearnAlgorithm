#include <bits/stdc++.h>
using namespace std;
bool p(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return n > 1;
}
int check(int n) {
    int s = 0;
    while (n != 0) {
        s += n % 10;
        n /= 10;
    }
    return p(s);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int l, r; cin >> l >> r;
    int cnt = 0;
    for (int i = l + 1; i <= r; i++) {
        if (check(i)) cnt++;
    }
    cout << cnt;
}