#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;

void fastIO() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
}
ll factorial(ll n) {
    int res = 1;
    for (int i = 1; i <= n; i++) res *= i;
    return res;
}
ll nCk(ll n, ll k) {
    return 1.0 * factorial(n) / (factorial(k) * factorial(n - k));
}
int main() {
    fastIO();
    int t; cin >> t;
    ll sum = 0;
    while (t--) {
        ll n, k; cin >> n >> k;
        sum += nCk(n, k);
    }
    cout << sum;
}